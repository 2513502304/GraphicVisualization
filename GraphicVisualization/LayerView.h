#pragma once
#pragma execution_character_set("utf-8")

#include "LayerScene.h"
#include <QObject>
#include <QGraphicsView>
#include <QScrollBar>
#include <QMouseEvent>
#include <QInputDialog>
#include <QFileDialog>
#include <QTreeWidgetItem>
#include <QDebug>

using namespace std;

class LayerView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit LayerView(QWidget *parent = 0);

    // 绘图状态
    enum DrawState
    {
        NoDrawState,
        DrawPointState,
        DrawLineState,
        DrawPolylineState,
        DrawRectangleState,
        DrawCircleState,
        DrawSectorState,
        DrawPolygonState,
        DrawCurveState,
        DrawTextState,
        DrawPixmapState,
    };

    // 绘制场景
    QVector<LayerScene *> scenes;

    // 当前场景
    LayerScene *currentScene;

    // 绘制状态
    int state;

    // 上一次点击位置与下一次点击位置，用于绘制点、线、矩形、圆、文本、图片
    QPointF lastPos, endPos;

    // 存储点的数组，用于绘制折线、扇形、多边形、三次贝塞尔曲线
    QVector<QPointF> points;

    // 起始角与结束角，用于绘制扇形
    int startAngle, endAngle;

    // 点击次数
    int clickNum = 0;

    // 设置当前场景
    void setCurrentScene();

    // 鼠标按下事件
    void mousePressEvent(QMouseEvent *event);

    // 鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);

    // 鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *event);

    // 鼠标滚轮事件
    void wheelEvent(QWheelEvent *event);

    // 键盘按下事件
    void keyPressEvent(QKeyEvent *event);

signals:
    // 鼠标左键按下信号
    void leftButtonPressed(QMouseEvent *event);
};
