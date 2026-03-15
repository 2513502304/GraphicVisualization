#pragma once
#pragma execution_character_set("utf-8")

#include "AttributeDialog.h"
#include "ui_AttributeDialog.h"
#include "Chess.h"
#include "ConvexHull.h"
#include "Interpolation.h"
#include "MachineLearning.h"
#include "NetworkAnalysis.h"
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QCursor>
#include <QKeyEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QGraphicsEffect>
#include <QDebug>
#include <QtMath>
#include <QFileInfo>
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include <memory>

using namespace std;

class GraphItem : public QObject, virtual public QGraphicsItem
{
    Q_OBJECT

public:
    explicit GraphItem(int id = 0, QGraphicsItem *parent = (QGraphicsItem *)nullptr);

    virtual ~GraphItem();

    // 当前缩放倍数
    double scaleValue = 1;

    // 最大缩放倍数
    double scaleMax = 50;

    // 最小缩放倍数
    double scaleMin = 0.1;

    // ID
    int id;

    // 路径
    QPainterPath path;

    // 属性对话框
    shared_ptr<AttributeDialog> dialog;

    // 画笔
    QPen pen;

    // 画刷
    QBrush brush;

    // 画笔颜色
    QColor penColor = QColor(Qt::black);

    // 画刷颜色
    QColor brushColor = QColor(QColor(100, 100, 100, 100));

    // 模糊效果
    QGraphicsBlurEffect *blurEffect;

    // 染色效果
    QGraphicsColorizeEffect *colorizeEffect;

    // 阴影效果
    QGraphicsDropShadowEffect *dropShadowEffect;

    // 透明效果
    QGraphicsOpacityEffect *opacityEffect;

    // 设置画笔
    void setPen();
    void setPen(const QColor &color);
    void setPen(const QPen &pen);

    // 设置画刷
    void setBrush();
    void setBrush(const QColor &color);
    void setBrush(const QBrush &brush);

    // 设置属性对话框
    void setAttributeDialog();
};

class PointItem : public GraphItem
{
    Q_OBJECT

public:
    explicit PointItem(const QPointF &pos, int id = 0, QGraphicsItem *parent = (QGraphicsItem *)nullptr);

    virtual ~PointItem();

    // 点
    QPointF pos;

    // 点实例
    shared_ptr<QGraphicsEllipseItem> pointItem;

    // 设置属性
    void setX(int val);
    void setY(int val);
    void setPos(int x, int y);
    void setSize(int val);

    // 重载纯虚函数，用来返回绘制图形项的矩形区域
    QRectF boundingRect() const override;

    // 重载纯虚函数，用来执行实际的绘图操作
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) override;

    // 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标移动事件
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标施放事件
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    // 滚轮事件
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;

    // 键盘按下事件
    void keyPressEvent(QKeyEvent *event) override;

    // 悬停事件，设置光标外观和提示
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

    // 右键菜单事件，为图形项添加一个右键菜单
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

    // 形状函数，用于碰撞检测
    QPainterPath shape() const override;

signals:
    void PointSelected(int id);
};

class LineItem : public GraphItem
{
    Q_OBJECT

public:
    explicit LineItem(const QPointF &start, const QPointF &end, int id = 0, QGraphicsItem *parent = (QGraphicsItem *)nullptr);

    virtual ~LineItem();

    // 线段起点与终点
    QPointF start, end;

    // 旋转角
    double angle = 0;

    // 开始旋转与结束旋转点
    QPointF beginRotation, stopRotation;

    QPointF beginScale, stopScale;

    // 线段实例
    shared_ptr<QGraphicsLineItem> lineItem;

    // 重载纯虚函数，用来返回绘制图形项的矩形区域
    QRectF boundingRect() const override;

    // 重载纯虚函数，用来执行实际的绘图操作
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) override;

    // 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标移动事件
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标施放事件
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    // 滚轮事件
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;

    // 键盘按下事件
    void keyPressEvent(QKeyEvent *event) override;

    // 悬停事件，设置光标外观和提示
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

    // 右键菜单事件，为图形项添加一个右键菜单
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

    // 形状函数，用于碰撞检测
    QPainterPath shape() const override;
};

class PolylineItem : public GraphItem
{
    Q_OBJECT

public:
    explicit PolylineItem(const QVector<QPointF> &points, int id = 0, QGraphicsItem *parent = (QGraphicsItem *)nullptr);

    virtual ~PolylineItem();

    // 存储折线节点数组
    QVector<QPointF> points;

    // 折线实例
    shared_ptr<QGraphicsPathItem> polylineItem;

    // 重载纯虚函数，用来返回绘制图形项的矩形区域
    QRectF boundingRect() const override;

    // 重载纯虚函数，用来执行实际的绘图操作
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) override;

    // 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标移动事件
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标施放事件
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    // 滚轮事件
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;

    // 键盘按下事件
    void keyPressEvent(QKeyEvent *event) override;

    // 悬停事件，设置光标外观和提示
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

    // 右键菜单事件，为图形项添加一个右键菜单
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

    // 形状函数，用于碰撞检测
    QPainterPath shape() const override;
};

class RectangleItem : public GraphItem
{
    Q_OBJECT

public:
    explicit RectangleItem(const QPointF &start, const QPointF &end, int id = 0, QGraphicsItem *parent = (QGraphicsItem *)nullptr);

    virtual ~RectangleItem();

    // 宽和高
    double width;
    double height;

    // 上一次点击位置与下一次点击位置，用于初始化矩形四个控制点
    QPointF lastPos, endPos;

    // 矩形四个控制点
    QPointF topLeft, topRight, bottomLeft, bottomRight;

    // 矩形实例
    shared_ptr<QGraphicsRectItem> rectangleItem;

    // 重载纯虚函数，用来返回绘制图形项的矩形区域
    QRectF boundingRect() const override;

    // 重载纯虚函数，用来执行实际的绘图操作
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) override;

    // 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标移动事件
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标施放事件
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    // 滚轮事件
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;

    // 键盘按下事件
    void keyPressEvent(QKeyEvent *event) override;

    // 悬停事件，设置光标外观和提示
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

    // 右键菜单事件，为图形项添加一个右键菜单
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

    // 形状函数，用于碰撞检测
    QPainterPath shape() const override;
};

class CircleItem : public GraphItem
{
    Q_OBJECT

public:
    explicit CircleItem(const QPointF &lastPos, const QPointF &endPos, int id = 0, QGraphicsItem *parent = (QGraphicsItem *)nullptr);

    virtual ~CircleItem();

    // 上一次点击位置与下一次点击位置
    QPointF lastPos, endPos;

    // 半径
    double radius;

    // 圆心
    QPointF center;

    // 圆实例
    shared_ptr<QGraphicsEllipseItem> circleItem;

    double getRadius() const;

    // 重载纯虚函数，用来返回绘制图形项的矩形区域
    QRectF boundingRect() const override;

    // 重载纯虚函数，用来执行实际的绘图操作
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) override;

    // 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标移动事件
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标施放事件
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    // 滚轮事件
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;

    // 键盘按下事件
    void keyPressEvent(QKeyEvent *event) override;

    // 悬停事件，设置光标外观和提示
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

    // 右键菜单事件，为图形项添加一个右键菜单
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

    // 形状函数，用于碰撞检测
    QPainterPath shape() const override;
};

class SectorItem : public GraphItem
{
    Q_OBJECT

public:
    explicit SectorItem(const QPointF &start, const QPointF &center, const QPointF &end, int id = 0, QGraphicsItem *parent = (QGraphicsItem *)nullptr);

    virtual ~SectorItem();

    // 扇形的第一条线的起点，圆心,最后一条线的终点
    QPointF start, center, end;

    // 基准线
    QLineF benchmark;

    // 扇形的两条边
    QLineF line1, line2;

    // 开始角与旋转角
    qreal startAngle, spanAngle;

    // 扇形矩形的topLeft与bottomRight顶点
    QPointF topLeft, bottomRight;

    // 一半矩形长度
    double halfRect;

    // 扇形实例
    shared_ptr<QGraphicsEllipseItem> sectorItem;

    double getRadius(const QPointF &p1, const QPointF &p2) const;

    // 重载纯虚函数，用来返回绘制图形项的矩形区域
    QRectF boundingRect() const override;

    // 重载纯虚函数，用来执行实际的绘图操作
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) override;

    // 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标移动事件
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标施放事件
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    // 滚轮事件
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;

    // 键盘按下事件
    void keyPressEvent(QKeyEvent *event) override;

    // 悬停事件，设置光标外观和提示
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

    // 右键菜单事件，为图形项添加一个右键菜单
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

    // 形状函数，用于碰撞检测
    QPainterPath shape() const override;
};

class PolygonItem : public GraphItem
{
    Q_OBJECT

public:
    explicit PolygonItem(const QVector<QPointF> &points, int id = 0, QGraphicsItem *parent = (QGraphicsItem *)nullptr);

    virtual ~PolygonItem();

    // 存储多边形节点数组
    QVector<QPointF> points;

    // 多边形实例
    shared_ptr<QGraphicsPolygonItem> polygonItem;

    // 重载纯虚函数，用来返回绘制图形项的矩形区域
    QRectF boundingRect() const override;

    // 重载纯虚函数，用来执行实际的绘图操作
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) override;

    // 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标移动事件
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标施放事件
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    // 滚轮事件
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;

    // 键盘按下事件
    void keyPressEvent(QKeyEvent *event) override;

    // 悬停事件，设置光标外观和提示
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

    // 右键菜单事件，为图形项添加一个右键菜单
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

    // 形状函数，用于碰撞检测
    QPainterPath shape() const override;
};

class CurveItem : public GraphItem
{
    Q_OBJECT

public:
    explicit CurveItem(const QPointF &start, const QPointF &fisrtControl, const QPointF &secondControl, const QPointF &end, int id = 0, QGraphicsItem *parent = (QGraphicsItem *)nullptr);

    virtual ~CurveItem();

    // 起始点，控制点一，控制点二，结束点
    QPointF start, fisrtControl, secondControl, end;

    // 曲线实例
    shared_ptr<QGraphicsPathItem> curveItem;

    // 重载纯虚函数，用来返回绘制图形项的矩形区域
    QRectF boundingRect() const override;

    // 重载纯虚函数，用来执行实际的绘图操作
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) override;

    // 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标移动事件
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标施放事件
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    // 滚轮事件
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;

    // 键盘按下事件
    void keyPressEvent(QKeyEvent *event) override;

    // 悬停事件，设置光标外观和提示
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

    // 右键菜单事件，为图形项添加一个右键菜单
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

    // 形状函数，用于碰撞检测
    QPainterPath shape() const override;
};

class TextItem : public GraphItem
{
    Q_OBJECT

public:
    explicit TextItem(const QPointF &start, const QPointF &end, const QString &textContext, int id = 0, QGraphicsItem *parent = (QGraphicsItem *)nullptr);

    explicit TextItem(const QPointF &center, const QString &textContext, int id = 0);

    virtual ~TextItem();

    // 上一次点击位置与下一次点击位置，用于初始化文本矩形四个控制点
    QPointF lastPos, endPos;

    // 宽和高
    double width;
    double height;

    // 文本矩形四个控制点
    QPointF topLeft, topRight, bottomLeft, bottomRight;

    // 文本实例
    shared_ptr<QGraphicsRectItem> textItem;

    // 文本内容
    QString textContext;

    // 字体
    QFont font;

    // 设置文本
    void setText(const QString &textContext);

    // 重设文本项大小
    void resetSize(QSizeF size);

    // 重载纯虚函数，用来返回绘制图形项的矩形区域
    QRectF boundingRect() const override;

    // 重载纯虚函数，用来执行实际的绘图操作
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) override;

    // 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标移动事件
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标施放事件
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    // 滚轮事件
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;

    // 键盘按下事件
    void keyPressEvent(QKeyEvent *event) override;

    // 悬停事件，设置光标外观和提示
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

    // 右键菜单事件，为图形项添加一个右键菜单
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

    // 形状函数，用于碰撞检测
    QPainterPath shape() const override;
};

class PixmapItem : public GraphItem
{
    Q_OBJECT

public:
    explicit PixmapItem(const QString &fileName, int id = 0, QGraphicsItem *parent = (QGraphicsItem *)nullptr);

    explicit PixmapItem(const QPointF &center, const QString &fileName, int id = 0);

    virtual ~PixmapItem();

    // 图片的中心点
    QPointF center;

    // 图片信息
    QFileInfo info;

    // 图片
    QPixmap pixmap;

    // 图片实例
    shared_ptr<QGraphicsPixmapItem> pixmapItem;

    // 重载纯虚函数，用来返回绘制图形项的矩形区域
    QRectF boundingRect() const override;

    // 重载纯虚函数，用来执行实际的绘图操作
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w) override;

    // 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标移动事件
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标施放事件
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    // 滚轮事件
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;

    // 键盘按下事件
    void keyPressEvent(QKeyEvent *event) override;

    // 悬停事件，设置光标外观和提示
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

    // 右键菜单事件，为图形项添加一个右键菜单
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

    // 形状函数，用于碰撞检测
    QPainterPath shape() const override;
};

class ChessBoardItem : public GraphItem
{
    Q_OBJECT

public:
    explicit ChessBoardItem(int id = 0, QGraphicsItem *parent = (QGraphicsItem *)nullptr);

    virtual ~ChessBoardItem();

    // 文件路径
    QString filePath;

    // 棋盘对象
    ChessBoard chessboard;

    // 存储棋盘网格 Item
    QVector<shared_ptr<RectangleItem>> cellItems;

    // 棋盘格子尺寸
    const int cellSize = 50;

    // 初始化棋盘项
    void initChessBoardItem();

    // 绘制最大涂色区域
    void drawMaxArea();

    // 重载纯虚函数，用来返回绘制图形项的矩形区域
    QRectF boundingRect() const override;

    // 重载纯虚函数，用来执行实际的绘图操作
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w) override;

    // 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标移动事件
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标施放事件
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    // 滚轮事件
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;

    // 键盘按下事件
    void keyPressEvent(QKeyEvent *event) override;

    // 悬停事件，设置光标外观和提示
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

    // 右键菜单事件，为图形项添加一个右键菜单
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

    // 形状函数，用于碰撞检测
    QPainterPath shape() const override;
};

class ConvexHullItem : public GraphItem
{
    Q_OBJECT

public:
    explicit ConvexHullItem(int id = 0, QGraphicsItem *parent = (QGraphicsItem *)nullptr);

    virtual ~ConvexHullItem();

    // 文件路径
    QString filePath;

    // 凸包对象
    ConvexHull convexhull;

    bool isAddingPoint = false;

    // 凸包点索引
    int index = 0;

    // 存储凸包点 Item
    QVector<shared_ptr<PointItem>> convexHullPointItems;

    // 存储凸包点信息 TextItem
    QVector<shared_ptr<TextItem>> convexHullTextItems;

    // 凸包线 Item
    shared_ptr<PolylineItem> convexHullLineItem;

    // 初始化凸包项
    void initConvexHullItem();

    // 重载纯虚函数，用来返回绘制图形项的矩形区域
    QRectF boundingRect() const override;

    // 重载纯虚函数，用来执行实际的绘图操作
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w) override;

    // 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标移动事件
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标施放事件
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    // 滚轮事件
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;

    // 键盘按下事件
    void keyPressEvent(QKeyEvent *event) override;

    // 悬停事件，设置光标外观和提示
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

    // 右键菜单事件，为图形项添加一个右键菜单
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

    // 形状函数，用于碰撞检测
    QPainterPath shape() const override;
};

class DecisionTreeItem : public GraphItem
{
    Q_OBJECT

public:
    explicit DecisionTreeItem(shared_ptr<Node> root, int id = 0, QGraphicsItem *parent = (QGraphicsItem *)nullptr);

    virtual ~DecisionTreeItem();

    // 决策树节点
    vector<shared_ptr<QGraphicsEllipseItem>> nodeItems;

    // 决策树节点信息
    vector<shared_ptr<TextItem>> labelItems;

    // 决策树边
    vector<shared_ptr<LineItem>> lineItems;

    // 决策树边信息
    vector<shared_ptr<TextItem>> edgeLabelItems;

    /**
     * @brief
     * 匹配整数和浮点数，包括可选的正负号、小数点、以及科学记数法
     */
    const regex numericRegex = regex("^[-+]?[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?$");

    /**
     * @brief
     * 判断字符串是否转换为数值
     */
    bool isNumeric(const string& value);

    /**
     * @brief
     * 重塑决策树，将其转换为绘图所需的数据结构
     * @param node 根节点
     * @param leaves 存储唯一叶子节点与它的判别条件（数值类型）
     */
    void reshapeDecisionTree(shared_ptr<Node> node);

    // 计算树的宽度
    int calculateTreeWidth(shared_ptr<Node> node);

    // 初始化决策树 Item
    void initDecisionTreeItem(shared_ptr<Node> node, int x, int y, int parentX, int parentY, QString edgeLabel = "");

    // 重载纯虚函数，用来返回绘制图形项的矩形区域
    QRectF boundingRect() const override;

    // 重载纯虚函数，用来执行实际的绘图操作
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w) override;

    // 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标移动事件
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标施放事件
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    // 滚轮事件
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;

    // 键盘按下事件
    void keyPressEvent(QKeyEvent *event) override;

    // 悬停事件，设置光标外观和提示
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

    // 右键菜单事件，为图形项添加一个右键菜单
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

    // 形状函数，用于碰撞检测
    QPainterPath shape() const override;
};

class ShortestPathPointToPointItem : public GraphItem
{
    Q_OBJECT

public:
    explicit ShortestPathPointToPointItem(const vector<Place> &path, const vector<Path> &paths, const function<QPointF(const QPointF &point)> &convertCoordinate, int id = 0, QGraphicsItem *parent = (QGraphicsItem *)nullptr);

    virtual ~ShortestPathPointToPointItem();

    // 路网点信息
    QVector<shared_ptr<TextItem>> placeInfo;

    // 路网项
    map<pair<int, int>, QGraphicsLineItem *> lineMap;

    // 路网项信息
    map<pair<int, int>, TextItem *> labelMap;

    // 最短路径
    QVector<QGraphicsLineItem *> shortestPathItems;

    // 点击次数
    int clickNum = 0;

    // 起点与终点
    Place start, end;

    // 初始化最短路径（点到点） Item
    void initShortestPathPointToPointItem(const vector<Place> &places, const vector<Path> &paths, const function<QPointF(const QPointF &point)> &convertCoordinate);

    // 重载纯虚函数，用来返回绘制图形项的矩形区域
    QRectF boundingRect() const override;

    // 重载纯虚函数，用来执行实际的绘图操作
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w) override;

    // 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标移动事件
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    // 鼠标施放事件
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    // 滚轮事件
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;

    // 键盘按下事件
    void keyPressEvent(QKeyEvent *event) override;

    // 悬停事件，设置光标外观和提示
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

    // 右键菜单事件，为图形项添加一个右键菜单
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

    // 形状函数，用于碰撞检测
    QPainterPath shape() const override;
};