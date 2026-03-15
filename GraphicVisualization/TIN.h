#pragma once
#pragma execution_character_set("utf-8")

/**
 * @file TIN.h
 * @author Chijiang Zhai (2513502304@qq.com)
 * @brief
 * TIN 的构建<br>
 * 不规则三角网（TIN）是一系列互不交叉、互不重叠的连接在一起的三角形来表示物体 / 地形表面，能够很好的描述和维护空间关系，在地理信息系统里有广泛应用。<br>
 * 给定一系列点，利用这些点作为不规则三角网中三角形的节点，来构建 TIN。TIN 对三角形的几何形状有三个基本要求：<br>
 * 1、三角形的格网唯一；<br>
 * 2、每一个三角形都尽可能接近正三角形；<br>
 * 3、三角形边长之和最小，保证最近的点形成三角形。<br>
 * 在线参考资料：<br>
 * https ://blog.csdn.net/u014136513/article/details/50580500?locationNum=12<br>
 * 【测试数据】<br>
 * TIN_data.csv 为洪山区 POI 数据，包括 POI 的序号、POI 名称、经纬度等信息。<br>
 * 【基本要求】<br>
 * 给出一系列点，通过这些点来构建 TIN（数据量不小于 500 条）。<br>
 * 输入点的序号和坐标，输出三角形边对应的点序号。<br>
 * 【提高要求】<br>
 * 在数据量较大（数据量大于 5000 条）的时候，需要考虑更复杂的数据结构从而保证系统的稳定性和高效性。给出洪山区的所有 POI，请利用这一相对较为庞大的数据，快速构建出不规则三角网，并进行可视化。<br>
 * 可视化的过程可以采用第三方软件（比如 QGIS ）进行实现，可寻求学长和学姐的帮助。<br>
 * @version 0.1
 * @date 2023-12-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <codecvt>
#include <vector>
#include <array>
#include <map>
#include <algorithm>
#include <QStringList>
#include <QPoint>

using namespace std;

/**
 * @brief
 * Point of Interest
 */
class POI
{
public:
	/**
	 * @brief
	 * 属性 ID
	 */
	int objectID;

	/**
	 * @brief
	 * POI 名称
	 */
	wstring name;

	/**
	 * @brief
	 * 经纬度点
	 */
	QPointF point;
};

/**
 * @brief
 * Triangulated Irregular Network
 */
class TIN
{
public:
	/**
	 * @brief
	 * 表格类型，类似于 pandas.DataFrame in Python
	 */
	typedef map<string, vector<string>> Table;

public:
	/**
	 * @brief Construct a new TIN object
	 *
	 */
	explicit TIN() = default;

	/**
	 * @brief Construct a new TIN object
	 *
	 * @param file CSV 文件
	 */
	explicit TIN(const string &file);

	/**
	 * @brief
	 * CSV 表格
	 */
	Table table;

	/**
	 * @brief
	 * 表格字段
	 */
	vector<string> fields;

	/**
	 * @brief
	 * 存储 POI 点
	 */
	vector<POI> points;

	/**
	 * @brief
	 * 存储三角形顶点索引
	 */
	vector<array<int, 3>> simplices;

	/**
	 * @brief
	 * 读取 CSV 文件
	 * @param file CSV 文件
	 */
	void readCSV(const string &file);

	/**
	 * @brief
	 * 读取 POI 点
	 * @param table 表格
	 */
	void readPOI(Table &table);

	/**
	 * @brief
	 * 使用向量叉积和点积判断点是否在三角形的外接圆内
	 * @param p1 三角形顶点 1
	 * @param p2 三角形顶点 2
	 * @param p3 三角形顶点 3
	 * @param p 待判断点
	 * @return true
	 * @return false
	 */
	bool inCircumcircle(const QPointF &p1, const QPointF &p2, const QPointF &p3, const QPointF &p);

	/**
	 * @brief
	 * 创建 Delaunay 三角网（Bowyer-Watson 算法，算法复杂度：O(n^2)）
	 */
	void createDelaunay();
};