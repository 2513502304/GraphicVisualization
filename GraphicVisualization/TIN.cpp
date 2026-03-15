#include "TIN.h"

TIN::TIN(const string &file)
{
	// 读取 CSV 文件
	this->readCSV(file);
	// 读取 POI 点
	this->readPOI(this->table);
}

// 读取 CSV 文件
void TIN::readCSV(const string &file)
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

// 读取 POI 点
void TIN::readPOI(Table &table)
{
	// 字符编码转换器
	wstring_convert<codecvt_utf8<wchar_t>> converter;
	for (int i = 0; i < table["OBJECTID"].size(); i++)
	{
		POI poi;
		poi.objectID = stoi(table["OBJECTID"][i]);
		poi.name = converter.from_bytes(table["name"][i]);
		poi.point = QPointF(stod(table["locationx"][i]), stod(table["locationy"][i]));
		this->points.push_back(poi);
	}
}

// 使用向量叉积和点积判断点是否在三角形的外接圆内
bool TIN::inCircumcircle(const QPointF &p1, const QPointF &p2, const QPointF &p3, const QPointF &p)
{
	// ----------------------------------- 计算三角形的外接圆圆心(ux, uy)和半径 r -----------------------------------
	double ax = p1.x() - p.x();
	double ay = p1.y() - p.y();
	double bx = p2.x() - p.x();
	double by = p2.y() - p.y();
	double cx = p3.x() - p.x();
	double cy = p3.y() - p.y();
	double d = 2 * (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by));
	double ux = ((ax * ax + ay * ay) * (by - cy) + (bx * bx + by * by) * (cy - ay) + (cx * cx + cy * cy) * (ay - by)) / d;
	double uy = ((ax * ax + ay * ay) * (cx - bx) + (bx * bx + by * by) * (ax - cx) + (cx * cx + cy * cy) * (bx - ax)) / d;
	// 计算半径
	double r = sqrt((p1.x() - ux) * (p1.x() - ux) + (p1.y() - uy) * (p1.y() - uy));
	// ----------------------------------- 判断点是否在三角形的外接圆内 -----------------------------------
	return (p.x() - ux) * (p.x() - ux) + (p.y() - uy) * (p.y() - uy) <= r * r;
}

// 创建 Delaunay 三角网（Bowyer-Watson 算法，算法复杂度：O(n^2)）
void TIN::createDelaunay()
{
	// 初始化超级三角形
	array<int, 3> superTriangle = {0, 1, 2};
	this->simplices.push_back(superTriangle);
	// 对每个点进行迭代
	for (int i = 3; i < this->points.size(); ++i)
	{
		vector<array<int, 3>> newSimplices;
		vector<int> toRemove;
		// 对每个三角形进行迭代
		for (int j = 0; j < this->simplices.size(); ++j)
		{
			array<int, 3> &simplex = this->simplices[j];
			// 如果点在三角形的外接圆内
			if (this->inCircumcircle(this->points[simplex[0]].point, this->points[simplex[1]].point, this->points[simplex[2]].point, this->points[i].point))
			{
				// 将三角形的边添加到新的三角形列表中
				for (int k = 0; k < 3; ++k)
				{
					array<int, 2> edge = {simplex[k], simplex[(k + 1) % 3]};
					array<int, 3> newSimplex = {edge[0], edge[1], i};
					newSimplices.push_back(newSimplex);
				}
				// 记录需要移除的三角形
				toRemove.push_back(j);
			}
		}
		// 移除需要移除的三角形
		for (int j = toRemove.size() - 1; j >= 0; --j)
		{
			this->simplices[j] = this->simplices.back();
			this->simplices.pop_back();
		}
		// 添加新的三角形
		this->simplices.insert(this->simplices.end(), newSimplices.begin(), newSimplices.end());
	}
	// 移除包含超级三角形的点的三角形
	this->simplices.erase(remove_if(this->simplices.begin(), this->simplices.end(), [&](const std::array<int, 3> &simplex)
									{ return simplex[0] < 3 || simplex[1] < 3 || simplex[2] < 3; }),
						  this->simplices.end());
}