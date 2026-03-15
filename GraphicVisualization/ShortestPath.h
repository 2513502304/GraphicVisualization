#pragma once
#pragma execution_character_set("utf-8")

/**
 * @file ShortestPath.h
 * @author Chijiang Zhai (2513502304@qq.com)
 * @brief
 * 校园导航（图的构建和最短路径算法）<br>
 * 【问题描述】<br>
 * 一个学校平面图，至少包括 10 个以上的场所，每个场所带有编号、坐标、名称、类别等信息，两个场所间可以有路径相通，路长（耗时）各有不同。要求读取该校园平面图，查询各个场所信息，找出从任意场所到达另一场所的最短路径（最佳路径）。<br>
 * 【基本要求】<br>
 * 校园平面图用图数据结构表达，采用指令或菜单方式操作，实现场所查询和路径求解。<br>
 * 【提高要求】<br>
 * 编写图形用户界面程序，使用交互方式：<br>
 * 1）绘制校园平面图，并加以存储；<br>
 * 2）点选查询场所信息；<br>
 * 3）点选起点和终点，显示求得的最佳路径。<br>
 * 【测试数据】<br>
 * 自行设计校园平面图，用数据文件存储，格式自定。<br>
 * @version 0.1
 * @date 2024-01-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <codecvt>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <memory>
#include <QPoint>

using namespace std;

/**
 * @brief
 * 场所
 */
class Place
{
public:
    /**
     * @brief
     * 属性 ID
     */
    int id;

    /**
     * @brief
     * 坐标
     */
    QPointF point;

    /**
     * @brief
     * 名称
     */
    wstring name;

    /**
     * @brief
     * 类别
     */
    wstring category;
};

/**
 * @brief
 * 路径
 */
class Path
{
public:
    /**
     * @brief
     * 起点
     */
    Place from;

    /**
     * @brief
     * 终点
     */
    Place to;

    /**
     * @brief
     * 路长
     */
    double length;
};

/**
 * @brief
 * 最短路径（点到点）
 */
class ShortestPathPointToPoint
{
public:
    /**
     * @brief Construct a new Shortest Path Point To Point object
     *
     */
    explicit ShortestPathPointToPoint() = default;

    /**
     * @brief Construct a new Shortest Path Point To Point object
     *
     * @param placeFile 场所文件
     * @param pathFile 路径文件
     */
    explicit ShortestPathPointToPoint(const string &placeFile, const string &pathFile);

    /**
     * @brief
     * 场所集合
     */
    vector<Place> places;

    /**
     * @brief
     * 路径集合
     */
    vector<Path> paths;

    /**
     * @brief
     * 读取路网
     * @param placeFile 场所文件
     * @param pathFile 路径文件
     */
    void readRoad(const string &placeFile, const string &pathFile);

    /**
     * @brief
     * 最短路径算法（Dijkstra）
     * @param startPlace 起点
     * @param endPlace 终点
     * @return vector<Place> 最短路径
     */
    vector<Place> shortestPath(Place startPlace, Place endPlace);

    /**
     * @brief
     * 计算最短路径
     * @param places 场所集合
     * @return double 最短路径
     */
    double calcMinDistance(const vector<Place> &places);
};
