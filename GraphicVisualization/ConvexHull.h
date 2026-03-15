#pragma once
#pragma execution_character_set("utf-8")

/**
 * @file ConvexHull.h
 * @author Chijiang Zhai (2513502304@qq.com)
 * @brief
 * 凸包求解<br>
 * 【问题描述】<br>
 *  凸包是一种基础的几何结构，在地理信息科学领域广泛应用。给出一组平面上的点，构造出对应的凸包，并依次输出极点编号。<br>
 * 【输入格式】<br>
 * 第一行即输入点的总数 n，接下来 n 行依次给出各点的横纵坐标，横坐标与纵坐标间用空格分隔。<br>
 * 【输出格式】<br>
 * 依次输出各个极点的对应编号（编号从 1 开始，而非 0）。<br>
 * 可基于界面编程将凸包可视化。要求算法代码和界面代码分离。<br>
 * @version 0.1
 * @date 2023-12-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <QPoint>
#include <QColor>

using namespace std;

/**
 * @brief
 * 凸包类
 */
class ConvexHull
{
public:
    /**
     * @brief
     * 有序点方向
     */
    enum ORIENTATION
    {
        COLLINEAR,       ///< 共线
        CLOCKWISE,       ///< 顺时针
        COUNTERCLOCKWISE ///< 逆时针
    };

public:
    /**
     * @brief Construct a new Convex Hull object
     *
     */
    explicit ConvexHull() = default;

    /**
     * @brief Construct a new Convex Hull object
     *
     * @param points 点集
     */
    explicit ConvexHull(const vector<QPointF> &points);

    /**
     * @brief Construct a new Convex Hull object
     *
     * @param file 点集文件
     */
    explicit ConvexHull(const string &file);

    /**
     * @brief
     * 凸包点
     */
    vector<QPointF> points;

    /**
     * @brief
     * 检测的凸包结果
     */
    vector<QPointF> convexhullResult;

    /**
     * @brief
     * 边界点
     */
    QPointF leftPoint, rightPoint, topPoint, bottomPoint;

    /**
     * @brief
     * 边界点索引
     */
    int leftPointIndex, rightPointIndex, topPointIndex, bottomPointIndex;

    /**
     * @brief
     * 读取点坐标
     * @param file 点集文件
     */
    void readPoint(const string &file);

    /**
     * @brief
     * 寻找边界点
     */
    void findBoundaryPoints();

    /**
     * @brief
     * 检测有序点方向
     * @param p1 点 1
     * @param p2 点 2
     * @param p3 点 3
     * @return ConvexHull::ORIENTATION
     */
    ConvexHull::ORIENTATION orientation(const QPointF &p1, const QPointF &p2, const QPointF &p3);

    /**
     * @brief
     * 给定三个共线点 p、q、r，检查点 q 是否位于线段 pr 上
     * @param p 线段起点
     * @param q 待检测点
     * @param r 线段终点
     * @return true
     * @return false
     */
    bool onSegment(const QPointF &p, const QPointF &q, const QPointF &r);

    /**
     * @brief
     * 检测两个给定线段是否相交
     * @param p1 线段 1 起点
     * @param q1 线段 1 终点
     * @param p2 线段 2 起点
     * @param q2 线段 2 终点
     * @return true
     * @return false
     */
    bool isIntersect(const QPointF &p1, const QPointF &q1, const QPointF &p2, const QPointF &q2);

    /**
     * @brief
     * 凸包检测
     */
    void findConvexHull();
};