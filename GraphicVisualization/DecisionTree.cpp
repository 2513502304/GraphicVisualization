#include "DecisionTree.h"

DecisionTree::DecisionTree(const string &file)
{
	// 读取 CSV 文件
	this->readCSV(file);
}

// 读取 CSV 文件
void DecisionTree::readCSV(const string &file)
{
	// 文件流
	ifstream in(file);
	// 当前行
	string line;
	// 读取 CSV 表头，确定 CSV 字段列名
	getline(in, line, '\n');
	istringstream is(line);
	string field;
	while (getline(is, field, ','))
	{
		this->fields.push_back(field);
		this->table.insert(make_pair(field, vector<string>()));
	}
	// 读取 CSV 表格
	while (getline(in, line, '\n'))
	{
		istringstream is(line);
		string field;
		int i = 0;
		while (getline(is, field, ','))
		{
			this->table[this->fields[i++]].push_back(field);
		}
	}
	// 关闭文件
	in.close();
}

// 计算目标值信息熵
// H(D) = -∑(i=1, n) p_i * log2(p_i)，D 为数据集，p_i 为第 i 个目标值分类的概率，n 为目标值分类的个数
double DecisionTree::calcEntropy(const vector<string> &target)
{
	// 目标值分类类别计数表
	map<string, int> counts;
	// 信息熵
	double entropy = 0.0;
	// 初始化目标值分类类别计数表
	for (const string &value : target)
	{
		counts[value]++;
	}
	// 计算信息熵
	for (auto &pair : counts)
	{
		// 计算概率
		double prob = static_cast<double>(pair.second) / target.size();
		// 累加信息熵
		entropy -= prob * log2(prob);
	}
	return entropy;
}

// 计算目标值与当前字段信息增益
// g(D, A) = H(D) - H(D|A)，H(D|A)为条件熵，H(D|A) = ∑(i=1, n) D_i / D ∑(k=1, k) D_ik / Di * log2(D_ik / Di)
// 缺点：信息增益偏向取值较多的特征
// 原因：当特征的取值较多时，根据此特征划分更容易得到纯度更高的子集，划分之后的熵更低，由于划分前的熵是一定的，因此信息增益更大，偏向取值较多的特征
double DecisionTree::calcInfoGain(Table &table, const vector<string> &target, const string &field)
{
	// 计算原始信息熵
	double originalEntropy = this->calcEntropy(target);
	// 获取字段的数据
	vector<string> fieldData = table[field];
	// 计算字段的唯一值
	set<string> uniqueValues(fieldData.begin(), fieldData.end());
	// 计算条件熵
	double conditionalEntropy = 0.0;
	// 遍历字段的唯一值
	for (const string &value : uniqueValues)
	{
		// 字段唯一值发生的情况下，子目标值的列表
		vector<string> subTarget;
		// 遍历字段的数据
		for (int i = 0; i < fieldData.size(); i++)
		{
			// 如果字段的数据等于当前值
			if (fieldData[i] == value)
			{
				// 添加当字段唯一值发生的情况下的目标值
				subTarget.push_back(target[i]);
			}
		}
		// 计算概率
		double prob = static_cast<double>(subTarget.size()) / fieldData.size();
		// 累加条件熵
		conditionalEntropy += prob * this->calcEntropy(subTarget);
	}
	// 计算信息增益
	double infoGain = originalEntropy - conditionalEntropy;
	return infoGain;
}

// 计算属性的固有值
// H_A(D) = -∑(i=1, n) p_i * log2(p_i)，A 为某一特征值，p_i 为第 i 个特征值分类的概率，n 为特征值分类的个数
double DecisionTree::calcIntrinsicValue(Table &table, const string &field)
{
	// 获取字段的数据
	vector<string> fieldData = table[field];
	// 计算字段的唯一值
	set<string> uniqueValues(fieldData.begin(), fieldData.end());
	// 计算固有值
	double intrinsicValue = 0.0;
	// 遍历字段的唯一值
	for (const string &value : uniqueValues)
	{
		// 计算概率
		double prob = count(fieldData.begin(), fieldData.end(), value) / static_cast<double>(fieldData.size());
		// 累加固有值
		intrinsicValue -= prob * log2(prob);
	}
	return intrinsicValue;
}

// 计算信息增益率
// g_R(D, A) = g(D, A) / H_A(D)，H_A(D) 为属性的固有值，也叫做惩罚系数
// 缺点：信息增益比偏向取值较少的特征
// 原因：当特征取值较少时 H_A(D) 的值较小，其倒数较大，因而信息增益率更大，偏向取值较少的特征
double DecisionTree::calcInfoGainRatio(Table &table, const vector<string> &target, const string &field)
{
	// 计算信息增益
	double infoGain = this->calcInfoGain(table, target, field);
	// 计算固有值
	double intrinsicValue = this->calcIntrinsicValue(table, field);
	// 计算信息增益率
	double infoGainRatio = infoGain / intrinsicValue;
	return infoGainRatio;
}

// 检查所有的目标值是否相同，若相同则，则认为当前节点是纯净的，返回 true，否则返回 false
bool DecisionTree::isPure(const vector<string> &target)
{
	// 检查目标值的数量
	if (target.size() == 0)
	{
		return true;
	}
	// 获取第一个目标值
	const string &first = target[0];
	// 检查所有的目标值是否都相同
	for (const string &value : target)
	{
		if (value != first)
		{
			return false;
		}
	}
	return true;
}

// 计算目标值最多的目标值
string DecisionTree::mostCommonTarget(const vector<string> &target)
{
	// 创建一个映射来存储每个目标值的计数
	map<string, int> counts;
	// 计算每个目标值的计数
	for (const string &value : target)
	{
		counts[value]++;
	}
	// 找出计数最多的目标值
	string mostCommon;
	int maxCount = -1;
	// 遍历目标值的计数
	for (const auto &pair : counts)
	{
		if (pair.second > maxCount)
		{
			mostCommon = pair.first;
			maxCount = pair.second;
		}
	}
	return mostCommon;
}

// CART 算法（迭代二分法），使用贪婪的自上而下的方法从给定数据集构建决策树
//		1. 从根节点开始，对节点计算所有可能的特征的基尼系数
//		2. 选择基尼系数最小的特征作为节点的特征，由该特征的不同取值建立子节点
//		3. 对于每个子节点，递归的调用（重复 1、2 步），直到子节点的所有特征取值相同，或者没有特征可以选择为止
//		4. 重复 1、2、3 步，直到决策树达到预定的最大深度
// ID3 算法（迭代二分法），使用贪婪的自上而下的方法从给定数据集构建决策树
//		1. 从根节点开始，对节点计算所有可能的特征的信息增益
//		2. 选择信息增益最大的特征作为节点的特征，由该特征的不同取值建立子节点
//		3. 对于每个子节点，递归的调用（重复 1、2 步），直到子节点的所有特征取值相同，或者没有特征可以选择为止
// C4.5 算法（迭代二分法），使用贪婪的自上而下的方法从给定数据集构建决策树
//		1. 从根节点开始，对节点计算所有可能的特征的信息增益比
//		2. 选择信息增益比最大的特征作为节点的特征，由该特征的不同取值建立子节点
//		3. 对于每个子节点，递归的调用（重复 1、2 步），直到子节点的所有特征取值相同，或者没有特征可以选择为止
shared_ptr<Node> DecisionTree::buildTree(DecisionTree::CRITERION criterion, Table &table, const string &targetFields, const vector<string> &featureFields, int maxDepth)
{
	// 目标值列表
	vector<string> target = table[targetFields];
	// 创建新的节点
	shared_ptr<Node> node = make_shared<Node>();
	// 设置节点的深度
	node->depth = this->currentDepth;
	// ----------------------------------- 递归终止条件 -----------------------------------
	// 如果所有目标值都相同，返回叶节点
	if (this->isPure(target))
	{
		node->label = target[0];
		return node;
	}
	// 如果没有特征可用，或者已经达到最大深度，返回最常见的目标值
	if (featureFields.empty() || node->depth == maxDepth)
	{
		node->label = this->mostCommonTarget(target);
		return node;
	}
	switch (criterion)
	{
	// ----------------------------------- 基尼系数，最小的准则，用于 CART 算法 -----------------------------------
	case DecisionTree::GINI:
	{
	}
	break;
	// ----------------------------------- 递归创建节点，信息熵，最大的准则，用于 ID3（信息增益）算法、C4.5（信息增益率）算法 -----------------------------------
	case DecisionTree::ENTROPYID3:
	{
		// 计算每个特征的信息增益
		string bestField;
		double bestInfoGain = -1.0;
		// 遍历每个特征，寻找其中的最佳特征（信息增益值最大化特征）
		for (const string &field : featureFields)
		{
			double infoGain = this->calcInfoGain(table, target, field);
			if (infoGain > bestInfoGain)
			{
				bestInfoGain = infoGain;
				bestField = field;
			}
		}
		// 设置节点的字段
		node->field = bestField;
		// 获取最佳字段的数据
		vector<string> bestFieldData = table[bestField];
		// 当前最佳字段唯一值的容器
		set<string> uniqueValues = set<string>(bestFieldData.begin(), bestFieldData.end());
		// 对每个唯一值，递归地构建子树
		for (const string &value : uniqueValues)
		{
			// 创建子表格
			Table subTable;
			// 遍历最佳字段的数据
			for (int i = 0; i < bestFieldData.size(); i++)
			{
				// 如果最佳字段的数据等于当前唯一值
				if (bestFieldData[i] == value)
				{
					// 为子表格添加字段数据
					for (const auto &p : table)
					{
						subTable[p.first].push_back(p.second[i]);
					}
				}
			}
			// 为当前唯一值创建子节点
			this->currentDepth++;
			shared_ptr<Node> child = this->buildTree(criterion, subTable, targetFields, featureFields, maxDepth);
			this->currentDepth--;
			// 设置子节点，key 为特征值，value 为子节点
			node->children[value] = child;
			// 设置划分数据的特征字段的值
			node->children[value]->value = value;
			// 设置父节点
			node->children[value]->parent = node;
		}
		return node;
	}
	break;
	case DecisionTree::ENTROPYC45:
	{
		// ... 和 ID3 算法类似，但是选择划分属性时使用信息增益比
		// 计算每个特征的信息增益比
		string bestField;
		double bestInfoGainRatio = -1.0;
		// 遍历每个特征，寻找其中的最佳特征（信息增益比值最大化特征）
		for (const string &field : featureFields)
		{
			double infoGainRatio = this->calcInfoGainRatio(table, target, field);
			if (infoGainRatio > bestInfoGainRatio)
			{
				bestInfoGainRatio = infoGainRatio;
				bestField = field;
			}
		}
		// ... 以下流程与 ID3 算法一致
		// 设置节点的字段
		node->field = bestField;
		// 获取最佳字段的数据
		vector<string> bestFieldData = table[bestField];
		// 当前最佳字段唯一值的容器
		set<string> uniqueValues = set<string>(bestFieldData.begin(), bestFieldData.end());
		// 对每个唯一值，递归地构建子树
		for (const string &value : uniqueValues)
		{
			// 创建子表格
			Table subTable;
			// 遍历最佳字段的数据
			for (int i = 0; i < bestFieldData.size(); i++)
			{
				// 如果最佳字段的数据等于当前唯一值
				if (bestFieldData[i] == value)
				{
					// 为子表格添加字段数据
					for (const auto &p : table)
					{
						subTable[p.first].push_back(p.second[i]);
					}
				}
			}
			// 为当前唯一值创建子节点
			this->currentDepth++;
			shared_ptr<Node> child = this->buildTree(criterion, subTable, targetFields, featureFields, maxDepth);
			this->currentDepth--;
			// 设置子节点，key 为特征值，value 为子节点
			node->children[value] = child;
			// 设置划分数据的特征字段的值
			node->children[value]->value = value;
			// 设置父节点
			node->children[value]->parent = node;
		}
		return node;
	}
	break;
	// ----------------------------------- 误差 -----------------------------------
	case DecisionTree::LOGLOSS:
	{
	}
	break;
	default:
		throw invalid_argument("算法准测类型错误，请选择合适的准则");
		break;
	}
}

// 根据决策树训练模型，录入预测特征值，进行目标值预测
// 递归遍历决策树节点，直到找到一个叶节点，返回叶节点的标签作为预测结果
string DecisionTree::predict(shared_ptr<Node> node, map<string, string> predictSample)
{
	// 如果节点是叶节点，返回其标签
	if (node->children.empty())
	{
		return node->label;
	}
	// 获取当前节点的字段
	string field = node->field;
	// 获取预测样本在当前字段的值
	string value = predictSample[field];
	// 如果预测样本的值在子节点中不存在，返回最常见的目标值
	if (node->children.count(value) == 0)
	{
		vector<string> targets = this->table[this->targetFields];
		return this->mostCommonTarget(targets);
	}
	// 递归地在对应的子节点上进行预测
	return this->predict(node->children[value], predictSample);
}
