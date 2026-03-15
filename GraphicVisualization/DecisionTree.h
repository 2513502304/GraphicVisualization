#pragma once
#pragma execution_character_set("utf-8")

/**
 * @file DecisionTree.h
 * @author Chijiang Zhai (2513502304@qq.com)
 * @brief
 * 决策树（ID3/C4.5）<br>
 * 【问题描述】<br>
 * ID3 算法是一种贪心算法，用来构造决策树。ID3 算法起源于概念学习系统（CLS），以信息熵的下降速度为选取测试属性的标准，即在每个节点选取还尚未被用来划分的具有最高信息增益的属性作为划分标准，然后继续这个过程，直到生成的决策树能完美分类训练样例。<br>
 * 具体方法是：从根结点开始，对结点计算所有可能的特征的信息增益，选择信息增益最大的特征作为结点的特征，由该特征的不同取值建立子结点；再对子结点递归的调用以上方法，构建决策树；直到所有特征的信息增益均很小或没有特征可以选择为止。<br>
 * 参考论文：Quinlan J R.Induction of Decision Trees[J].Machine Learning, 1986, 1(1) : 81 - 106.<br>
 * 参考资料：https ://blog.csdn.net/choven_meng/article/details/82878018<br>
 * 【数据说明】<br>
 * DT_data.csv 为样本数据，共 14 条记录。每一条记录共 4 维特征，分别为 Weather（天气）, Temperature（温度）, Humidity（湿度）, Wind（风力）; 其中Date（约会）为标签列。<br>
 * 【基本要求】<br>
 * 根据样本数据，建立决策树。<br>
 * 输入测试数据，得到预测是否约会（yes / no）。<br>
 * 【提高要求】<br>
 * 对决策树（ID3）中特征节点分类选择指标（信息增益）进行优化，选择信息增益率作为决策树(C4.5)中特征节点分类指标。<br>
 * 决策树(C4.5)及信息增益率参考资料：https://blog.csdn.net/qq_28697571/article/details/84679852<br>
 * @version 0.1
 * @date 2023-12-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <regex>
#include <algorithm>
#include <qstring.h>
#include <qstringlist.h>

using namespace std;

/**
 * @brief
 * 树节点类
 */
class Node
{
public:
	/**
	 * @brief
	 * 用于划分数据的特征字段
	 */
	string field;

	/**
	 * @brief
	 * 用于划分数据的特征字段的值
	 */
	string value;

	/**
	 * @brief
	 * 当前节点的预测类别（若节点为叶节点）
	 */
	string label;

	/**
	 * @brief
	 * 当前节点深度
	 */
	int depth;

	/**
	 * @brief
	 * 当前节点的父节点
	 */
	shared_ptr<Node> parent;

	/**
	 * @brief
	 * 当前节点的子节点，key 为特征字段的值，value 为对应的子节点
	 */
	map<string, shared_ptr<Node>> children;
};

// 机器学习教程：https://www.geeksforgeeks.org/machine-learning/?ref=outind#su
/**
 * @brief
 * 决策树类
 */
class DecisionTree
{
public:
	/**
	 * @brief
	 * 拆分标准，信息增益、信息熵、基尼系数、误差等指标用于计算最佳拆分
	 */
	enum CRITERION
	{
		GINI,		///< 基尼系数，最小的准则，用于 CART 算法
		ENTROPYID3, ///< 信息熵，最大的准则（信息增益）
		ENTROPYC45, ///< 信息熵，最大的准则（信息增益率）
		LOGLOSS		///< 对数损失
	};

	/**
	 * @brief
	 * 表格类型，类似于 pandas.DataFrame in Python
	 */
	typedef map<string, vector<string>> Table;

public:
	/**
	 * @brief Construct a new Decision Tree object
	 *
	 */
	explicit DecisionTree() = default;

	/**
	 * @brief Construct a new Decision Tree object
	 *
	 * @param file CSV 文件
	 */
	explicit DecisionTree(const string &file);

	/**
	 * @brief
	 * 存储 CSV 表格
	 */
	Table table;

	/**
	 * @brief
	 * 存储表头字段列表
	 */
	vector<string> fields;

	/**
	 * @brief
	 * 特征集字段、目标集字段
	 */
	vector<string> featureFields;
	string targetFields;

	/**
	 * @brief
	 * 预测样本
	 */
	map<string, string> predictSample;

	/**
	 * @brief
	 * 设置节点的深度
	 */
	int currentDepth = 0;

	/**
	 * @brief
	 * 读取 CSV 文件
	 * @param file CSV 文件
	 */
	void readCSV(const string &file);

	/**
	 * @brief
	 * 计算目标值信息熵
	 * @param target 目标值
	 * @return double 信息熵
	 */
	double calcEntropy(const vector<string> &target);

	/**
	 * @brief
	 * 计算目标值与当前字段信息增益
	 * @param table 表格
	 * @param target 目标值
	 * @param field 当前字段
	 * @return double 信息增益
	 */
	double calcInfoGain(Table &table, const vector<string> &target, const string &field);

	/**
	 * @brief
	 * 计算属性的固有值
	 * @param table 表格
	 * @param field 当前字段
	 * @return double 固有值
	 */
	double calcIntrinsicValue(Table &table, const string &field);

	/**
	 * @brief
	 * 计算信息增益率
	 * @param table 表格
	 * @param target 目标值
	 * @param field 当前字段
	 * @return double 信息增益率
	 */
	double calcInfoGainRatio(Table &table, const vector<string> &target, const string &field);

	/**
	 * @brief
	 * 检查所有的目标值是否相同，若相同则，则认为当前节点是纯净的，返回 true，否则返回 false
	 * @param target 目标值
	 * @return true
	 * @return false
	 */
	bool isPure(const vector<string> &target);

	/**
	 * @brief
	 * 计算目标值最多的目标值
	 * @param target 目标值
	 * @return string 最多的目标值
	 */
	string mostCommonTarget(const vector<string> &target);

	/**
	 * @brief
	 * 使用贪婪的自上而下的方法从给定数据集构建决策树
	 * @param criterion 拆分标准
	 * @param table 表格
	 * @param targetFields 目标字段
	 * @param featureFields 特征字段
	 * @param maxDepth 最大深度
	 * @return shared_ptr<Node> 决策树节点
	 */
	shared_ptr<Node> buildTree(DecisionTree::CRITERION criterion, Table &table, const string &targetFields, const vector<string> &featureFields, int maxDepth);

	/**
	 * @brief
	 * 根据决策树训练模型，录入预测特征值，进行目标值预测
	 * @param node 决策树节点
	 * @param predictSample 预测样本
	 * @return string 预测目标值
	 */
	string predict(shared_ptr<Node> node, map<string, string> predictSample);
};