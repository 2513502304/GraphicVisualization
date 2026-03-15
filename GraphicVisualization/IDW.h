#pragma once
#pragma execution_character_set("utf-8")

/**
 * @file IDW.h
 * @author Chijiang Zhai (2513502304@qq.com)
 * @brief
 * @version 0.1
 * @date 2023-12-23
 * 反距离加权插值（IDW）<br>
 * 【问题描述】<br>
 * 插值是数据处理的常用手段，反距离加权插值（IDW）是一种常用而简便的空间插值方法，它以插值点与样本点间的距离为权重进行加权平均，离插值点越近的样本点赋予的权重越大。<br>
 * 具体方法是：给出一系列平面上的点，构成插值空间。选择想要获取的属性的未知点，以此点为中心进行四邻域遍历，当遍历点数为 m 时，停止遍历。将遍历获取点按照插值点与样本点之间距离进行加权插值。<br>
 * 反距离加权参考资料：https ://malagis.com/inverse-distance-weighting-interpolation-algorithm.html<br>
 * 【输入格式】<br>
 * 第一行即输入点的总数 n，第二行输入插值所需临近点的个数 m。接下来 n 行依次给出各点的横纵坐标和属性值，横坐标、纵坐标、属性值间用空格分隔，构成插值空间。输入想要获取的未知的点横纵坐标。<br>
 * 【输出格式】<br>
 * 输出输入未知点的属性值。<br>
 * 可基于界面编程将凸包可视化。要求算法代码和界面代码分离。<br>
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <QPoint>
#include <algorithm>
#include <nlohmann/json.hpp>
#include <algorithm>

using namespace std;

/**
 * @brief
 * LineString in GeoJSON
 */
class LineString
{
public:
	// 属性 ID
	int id;

	// 高程值
	double elev;

	// 数据点
	vector<QPointF> points;
};

/**
 * @brief
 * 反距离加权插值（IDW）
 */
class IDW
{
public:
	/**
	 * @brief Construct a new IDW object
	 *
	 */
	explicit IDW() = default;

	/**
	 * @brief Construct a new IDW object
	 *
	 * @param file GeoJSON 文件
	 */
	IDW(const string &file);

	/**
	 * @brief
	 * LineString 集合
	 */
	vector<LineString> lineStrings;

	/**
	 * @brief
	 * 读取 GeoJSON 文件
	 * @param file GeoJSON 文件
	 */
	void readGeoJSON(const string &file);

	/**
	 * @brief
	 * 计算两点之间的欧式距离
	 * @param p1 点 1
	 * @param p2 点 2
	 * @return double 欧式距离
	 */
	double distance(const QPointF &p1, const QPointF &p2);

	/**
	 * @brief
	 * 执行反距离加权插值（IDW）算法
	 * @param point 插值点
	 * @param m 临近点个数
	 * @return double 插值结果
	 */
	double interpolate(const QPointF &point, int m = 100);
};