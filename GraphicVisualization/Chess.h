#pragma once
#pragma execution_character_set("utf-8")

/**
 * @file Chess.h
 * @author Chijiang Zhai (2513502304@qq.com)
 * @brief
 * 棋盘最大涂色区域<br>
 * 【问题描述】<br>
 *  有一个 n * m 的棋盘，每个格子涂有不同颜色。需要找到其中同一颜色面积最大的连续区域（按照四连通标准），并求出其面积。<br>
 * 【输入格式】<br>
 * 第一行 2 个正整数 n, m 描述棋盘尺寸。<br>
 * 接下来 n 行描述这个棋盘，每行 m 个字符，每个字符为 W（白） / G（绿） / R（红） / B（蓝），表示对应格子的颜色。<br>
 * 【基本要求】<br>
 * Chess_data.txt 为用于测试的样例数据，要求输出被涂色面积最大的连续区域，并求该最大面积。<br>
 * 可基于图形界面编程实现，读入棋盘文件，表达棋盘和颜色，并显示计算结果。要求算法代码和界面代码分离。<br>
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
#include <QColor>

using namespace std;

/**
 * @brief
 * 棋子类
 *
 */
class Chessman
{
public:
    /**
     * @brief Construct a new Chessman object
     *
     */
    explicit Chessman() = default;

    /**
     * @brief Construct a new Chessman object
     *
     * @param x
     * @param y
     * @param color 棋子颜色
     */
    explicit Chessman(int x, int y, char color);

    /**
     * @brief
     * 棋子坐标
     */
    int x = 0, y = 0;

    /**
     * @brief
     * 棋子颜色
     */
    QColor color = QColor(Qt::GlobalColor::black);
};

/**
 * @brief
 * 棋盘类
 */
class ChessBoard
{
public:
    /**
     * @brief Construct a new Chess Board object
     *
     */
    explicit ChessBoard() = default;

    /**
     * @brief Construct a new Chess Board object
     *
     * @param file 棋盘文件
     */
    explicit ChessBoard(const string &file);

    /**
     * @brief
     * 棋盘行列数
     */
    int row = 0, col = 0;

    /**
     * @brief
     * 棋盘
     */
    vector<vector<Chessman>> board;

    /**
     * @brief
     * 涂色区域访问标记
     */
    vector<vector<bool>> visited;

    /**
     * @brief
     * 最大涂色区域
     */
    vector<vector<bool>> maxArea;

    /**
     * @brief
     * 最大涂色区域面积
     */
    int maxAreaSize = 0;

    /**
     * @brief
     * 读取棋盘
     * @param file 棋盘文件
     */
    void readChessBoard(const string &file);

    /**
     * @brief
     * 深度优先搜索
     * @param i 棋盘行
     * @param j 棋盘列
     * @param area 区域面积
     */
    void dfs(int i, int j, int &area);

    /**
     * @brief
     * 求最大涂色区域
     */
    void findMaxArea();
};