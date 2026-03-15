#include "GraphItem.h"

GraphItem::GraphItem(int id, QGraphicsItem *parent) : QGraphicsItem(parent)
{
    // 初始化画笔和画刷
    this->setPen();
    this->setBrush();
    this->id = id;
}

// 设置画笔
void GraphItem::setPen()
{
    this->pen.setColor(this->penColor);
}

void GraphItem::setPen(const QColor &color)
{
    this->penColor = color;
    this->pen.setColor(this->penColor);
}

void GraphItem::setPen(const QPen &pen)
{
    this->pen = pen;
}

// 设置画刷
void GraphItem::setBrush()
{
    this->brush.setColor(this->brushColor);
    this->brush.setStyle(Qt::BDiagPattern);
}

void GraphItem::setBrush(const QColor &color)
{
    this->brushColor = color;
    this->brush.setColor(this->brushColor);
    this->brush.setStyle(Qt::BDiagPattern);
}

void GraphItem::setBrush(const QBrush &brush)
{
    this->brush = brush;
}

// 设置属性对话框
void GraphItem::setAttributeDialog()
{
    // 初始化属性对话框
    this->dialog = make_shared<AttributeDialog>(nullptr);
    // 初始化QSpinBox界面显示的值
    this->dialog->ui->penRSpinBox->setValue(this->penColor.red());
    this->dialog->ui->penGSpinBox->setValue(this->penColor.green());
    this->dialog->ui->penBSpinBox->setValue(this->penColor.blue());
    int h, s, v;
    this->penColor.getHsv(&h, &s, &v);
    this->dialog->ui->penHSpinBox->setValue(h);
    this->dialog->ui->penSSpinBox->setValue(s);
    this->dialog->ui->penVSpinBox->setValue(v);
    this->dialog->ui->penASpinBox->setValue(this->penColor.alpha());
    this->dialog->ui->brushRSpinBox->setValue(this->brushColor.red());
    this->dialog->ui->brushGSpinBox->setValue(this->brushColor.green());
    this->dialog->ui->brushBSpinBox->setValue(this->brushColor.blue());
    this->brushColor.getHsv(&h, &s, &v);
    this->dialog->ui->brushHSpinBox->setValue(h);
    this->dialog->ui->brushSSpinBox->setValue(s);
    this->dialog->ui->brushVSpinBox->setValue(v);
    this->dialog->ui->brushASpinBox->setValue(this->brushColor.alpha());
    void (QSpinBox::*valueChanged)(int) = &QSpinBox::valueChanged;
    // 设置绘制图形的颜色
    QObject::connect(this->dialog->ui->penRSpinBox, valueChanged, [=](int val)
                     {
            this->penColor.setRed(val);
            int h, s, v;
            this->penColor.getHsv(&h, &s, &v);
            this->dialog->ui->penHSpinBox->setValue(h);
            this->dialog->ui->penSSpinBox->setValue(s);
            this->dialog->ui->penVSpinBox->setValue(v);
            this->pen.setColor(this->penColor);
            update(); });
    QObject::connect(this->dialog->ui->penGSpinBox, valueChanged, [=](int val)
                     {
            this->penColor.setGreen(val);
            int h, s, v;
            this->penColor.getHsv(&h, &s, &v);
            this->dialog->ui->penHSpinBox->setValue(h);
            this->dialog->ui->penSSpinBox->setValue(s);
            this->dialog->ui->penVSpinBox->setValue(v);
            this->pen.setColor(this->penColor);
            update(); });
    QObject::connect(this->dialog->ui->penBSpinBox, valueChanged, [=](int val)
                     {
            this->penColor.setBlue(val);
            int h, s, v;
            this->penColor.getHsv(&h, &s, &v);
            this->dialog->ui->penHSpinBox->setValue(h);
            this->dialog->ui->penSSpinBox->setValue(s);
            this->dialog->ui->penVSpinBox->setValue(v);
            this->pen.setColor(this->penColor);
            update(); });
    QObject::connect(this->dialog->ui->penHSpinBox, valueChanged, [=](int val)
                     {
            this->penColor.setHsv(val, this->penColor.saturation(), this->penColor.value(), this->penColor.alpha());
            int r, g, b;
            this->penColor.getRgb(&r, &g, &b);
            this->dialog->ui->penRSpinBox->setValue(r);
            this->dialog->ui->penGSpinBox->setValue(g);
            this->dialog->ui->penBSpinBox->setValue(b);
            this->pen.setColor(this->penColor);
            update(); });
    QObject::connect(this->dialog->ui->penSSpinBox, valueChanged, [=](int val)
                     {
            this->penColor.setHsv(this->penColor.hue(), val, this->penColor.value(), this->penColor.alpha());
            int r, g, b;
            this->penColor.getRgb(&r, &g, &b);
            this->dialog->ui->penRSpinBox->setValue(r);
            this->dialog->ui->penGSpinBox->setValue(g);
            this->dialog->ui->penBSpinBox->setValue(b);
            this->pen.setColor(this->penColor);
            update(); });
    QObject::connect(this->dialog->ui->penVSpinBox, valueChanged, [=](int val)
                     {
            this->penColor.setHsv(this->penColor.hue(), this->penColor.saturation(), val, this->penColor.alpha());
            int r, g, b;
            this->penColor.getRgb(&r, &g, &b);
            this->dialog->ui->penRSpinBox->setValue(r);
            this->dialog->ui->penGSpinBox->setValue(g);
            this->dialog->ui->penBSpinBox->setValue(b);
            this->pen.setColor(this->penColor);
            update(); });
    QObject::connect(this->dialog->ui->penASpinBox, valueChanged, [=](int val)
                     {
            this->penColor.setAlpha(val);
            this->pen.setColor(this->penColor);
            update(); });
    QObject::connect(this->dialog->ui->brushRSpinBox, valueChanged, [=](int val)
                     {
            this->brushColor.setRed(val);
            int h, s, v;
            this->brushColor.getHsv(&h, &s, &v);
            this->dialog->ui->brushHSpinBox->setValue(h);
            this->dialog->ui->brushSSpinBox->setValue(s);
            this->dialog->ui->brushVSpinBox->setValue(v);
            this->brush.setColor(this->brushColor);
            update(); });
    QObject::connect(this->dialog->ui->brushGSpinBox, valueChanged, [=](int val)
                     {
            this->brushColor.setGreen(val);
            int h, s, v;
            this->brushColor.getHsv(&h, &s, &v);
            this->dialog->ui->brushHSpinBox->setValue(h);
            this->dialog->ui->brushSSpinBox->setValue(s);
            this->dialog->ui->brushVSpinBox->setValue(v);
            this->brush.setColor(this->brushColor);
            update(); });
    QObject::connect(this->dialog->ui->brushBSpinBox, valueChanged, [=](int val)
                     {
            this->brushColor.setBlue(val);
            int h, s, v;
            this->brushColor.getHsv(&h, &s, &v);
            this->dialog->ui->brushHSpinBox->setValue(h);
            this->dialog->ui->brushSSpinBox->setValue(s);
            this->dialog->ui->brushVSpinBox->setValue(v);
            this->brush.setColor(this->brushColor);
            update(); });
    QObject::connect(this->dialog->ui->brushHSpinBox, valueChanged, [=](int val)
                     {
            this->brushColor.setHsv(val, this->brushColor.saturation(), this->brushColor.value(), this->brushColor.alpha());
            int r, g, b;
            this->brushColor.getRgb(&r, &g, &b);
            this->dialog->ui->brushRSpinBox->setValue(r);
            this->dialog->ui->brushGSpinBox->setValue(g);
            this->dialog->ui->brushBSpinBox->setValue(b);
            this->brush.setColor(this->brushColor);
            update(); });
    QObject::connect(this->dialog->ui->brushSSpinBox, valueChanged, [=](int val)
                     {
            this->brushColor.setHsv(this->brushColor.hue(), val, this->brushColor.value(), this->brushColor.alpha());
            int r, g, b;
            this->brushColor.getRgb(&r, &g, &b);
            this->dialog->ui->brushRSpinBox->setValue(r);
            this->dialog->ui->brushGSpinBox->setValue(g);
            this->dialog->ui->brushBSpinBox->setValue(b);
            this->brush.setColor(this->brushColor);
            update(); });
    QObject::connect(this->dialog->ui->brushVSpinBox, valueChanged, [=](int val)
                     {
            this->brushColor.setHsv(this->brushColor.hue(), this->brushColor.saturation(), val, this->brushColor.alpha());
            int r, g, b;
            this->brushColor.getRgb(&r, &g, &b);
            this->dialog->ui->brushRSpinBox->setValue(r);
            this->dialog->ui->brushGSpinBox->setValue(g);
            this->dialog->ui->brushBSpinBox->setValue(b);
            this->brush.setColor(this->brushColor);
            update(); });
    QObject::connect(this->dialog->ui->brushASpinBox, valueChanged, [=](int val)
                     {
            this->brushColor.setAlpha(val);
            this->brush.setColor(this->brushColor);
            update(); });
}

GraphItem::~GraphItem()
{
}

PointItem::PointItem(const QPointF &pos, int id, QGraphicsItem *parent) : GraphItem(id, parent)
{
    this->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->setAcceptHoverEvents(true);
    this->pos = pos;
    // 初始化点实例
    this->pointItem = make_shared<QGraphicsEllipseItem>(QRectF(this->pos.x() - this->pen.width() / 2.0, this->pos.y() - this->pen.width() / 2.0, this->pen.width(), this->pen.width()));
    // 初始化点路径
    this->path = this->pointItem->shape();
}

void PointItem::setX(int val)
{
    int deltaX = val - this->pos.x();
    this->pos.setX(this->pos.x() + deltaX);
    // 更新点实例
    this->pointItem->setRect(QRectF(this->pos.x() - this->pen.width() / 2.0, this->pos.y() - this->pen.width() / 2.0, this->pen.width(), this->pen.width()));
    // 更新点路径
    this->path = this->pointItem->shape();
}

void PointItem::setY(int val)
{
    int deltaY = val - this->pos.y();
    this->pos.setY(this->pos.y() + deltaY);
    // 更新点实例
    this->pointItem->setRect(QRectF(this->pos.x() - this->pen.width() / 2.0, this->pos.y() - this->pen.width() / 2.0, this->pen.width(), this->pen.width()));
    // 更新点路径
    this->path = this->pointItem->shape();
}

void PointItem::setPos(int x, int y)
{
    this->setX(x);
    this->setY(y);
}

void PointItem::setSize(int val)
{
    this->pen.setWidth(val);
    // 更新点实例
    this->pointItem->setRect(QRectF(this->pos.x() - this->pen.width() / 2.0, this->pos.y() - this->pen.width() / 2.0, 2 * this->pen.width() / 2.0, 2 * this->pen.width() / 2.0));
    // 更新点路径
    this->path = this->pointItem->shape();
}

// 重载纯虚函数，用来返回绘制图形项的矩形区域
QRectF PointItem::boundingRect() const
{
    // 由于在connect()中增加this->pen.width()时，先调用update()函数，就会导致在没有扩大path.boundingRect()时就绘制一个增大后的图像，所以这里需要将path.boundingRect()增大一个单位，避免在较小图层中绘制较大图像
    return (this->path.boundingRect().adjusted(-this->pen.width() / 2.0, -this->pen.width() / 2.0, this->pen.width() / 2.0, this->pen.width() / 2.0));
}

// 重载纯虚函数，用来执行实际的绘图操作
void PointItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    painter->setPen(this->pen);
    painter->setBrush(this->brush);
    // 若碰撞列表不为空，将其图形项边框变为青色
    if (!this->collidingItems().isEmpty())
    {
        this->pen.setColor(Qt::cyan);
    }
    else
    {
        this->pen.setColor(this->penColor);
    }
    painter->drawPath(this->path);
    update();
}

// 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
void PointItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setFocus();
    this->setCursor(Qt::ClosedHandCursor);
    return (QGraphicsItem::mousePressEvent(event));
}

// 鼠标移动事件
void PointItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseMoveEvent(event));
}

// 鼠标施放事件
void PointItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseReleaseEvent(event));
}

// 滚轮事件
void PointItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    // 检测是否按下Shift键
    if (event->modifiers() & Qt::ShiftModifier)
    {
        // 最大放大到原始图像的50倍
        if (event->delta() > 0 && this->scaleValue >= this->scaleMax)
        {
            return;
        }
        // 图像缩小到最小缩小倍数大小之后就不继续缩小
        else if (event->delta() < 0 && (this->scaleValue <= this->scaleMin))
        {
            return;
        }
        else
        {
            // 因为图元默认的缩放原点为(0,0)，所以设置图元中心点为缩放原点
            this->setTransformOriginPoint(this->path.boundingRect().center());
            // 鼠标滚轮向前滚动
            if (event->delta() > 0)
            {
                // 每次放大10%
                this->scaleValue *= 1.1;
            }
            else
            {
                // 每次缩小10%
                this->scaleValue *= 0.9;
            }
            this->setScale(this->scaleValue);
            update();
        }
    }
    // 检测是否按下Alt键
    if (event->modifiers() & Qt::AltModifier)
    {
        // 因为图元默认的旋转原点为(0,0)，所以设置图元中心点为旋转原点
        this->setTransformOriginPoint(this->path.boundingRect().center());
        // 逆时针
        if (event->delta() > 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() + 1);
        }
        // 顺时针
        else if (event->delta() < 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() - 1);
        }
    }
    return (QGraphicsItem::wheelEvent(event));
}

// 键盘按下事件
void PointItem::keyPressEvent(QKeyEvent *event)
{
    // W键向上位移
    if (event->key() == Qt::Key_W)
    {
        this->moveBy(0, -10);
    }
    // S键向下位移
    if (event->key() == Qt::Key_S)
    {
        this->moveBy(0, 10);
    }
    // A键向左位移
    if (event->key() == Qt::Key_A)
    {
        this->moveBy(-10, 0);
    }
    // D键向右位移
    if (event->key() == Qt::Key_D)
    {
        this->moveBy(10, 0);
    }
    // 1键设置模糊效果
    if (event->key() == Qt::Key_1)
    {
        // 模糊效果
        this->blurEffect = new QGraphicsBlurEffect();
        // 设置模糊怎样来执行
        blurEffect->setBlurHints(QGraphicsBlurEffect::QualityHint);
        // 设置模糊半径
        blurEffect->setBlurRadius(8);
        this->setGraphicsEffect(blurEffect);
    }
    // 2键设置染色效果
    if (event->key() == Qt::Key_2)
    {
        // 染色效果
        this->colorizeEffect = new QGraphicsColorizeEffect();
        // 设置染色颜色
        colorizeEffect->setColor(Qt::red);
        // 设置染色效果强弱
        colorizeEffect->setStrength(0.6);
        this->setGraphicsEffect(colorizeEffect);
    }
    // 3键设置阴影效果
    if (event->key() == Qt::Key_3)
    {
        // 阴影效果
        this->dropShadowEffect = new QGraphicsDropShadowEffect();
        // 设置阴影的颜色
        dropShadowEffect->setColor(QColor(63, 63, 63, 100));
        // 设置阴影的模糊半径
        dropShadowEffect->setBlurRadius(2);
        // 设置阴影的偏移值
        dropShadowEffect->setOffset(5);
        this->setGraphicsEffect(dropShadowEffect);
    }
    // 4键设置不透明度
    if (event->key() == Qt::Key_4)
    {
        // 透明效果
        this->opacityEffect = new QGraphicsOpacityEffect();
        // 设置不透明度
        opacityEffect->setOpacity(0.4);
        this->setGraphicsEffect(opacityEffect);
    }
    // 5键停止使用图形效果
    if (event->key() == Qt::Key_5)
    {
        // 停止使用图形效果
        this->graphicsEffect()->setEnabled(false);
    }
}

// 悬停事件，设置光标外观和提示
void PointItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    this->setCursor(Qt::WhatsThisCursor);
    this->setToolTip("Point");
}

// 右键菜单事件，为图形项添加一个右键菜单
void PointItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    // 添加菜单
    QMenu menu;
    QAction *moveAction = menu.addAction("移动至起始点");
    QAction *setAttributeAction = menu.addAction("设置属性");
    QAction *pointSelectedAction = menu.addAction("选择图形");
    QAction *setZIndexAction = menu.addAction("设置图形 Z-Index");
    QAction *removeAction = menu.addAction("删除图形");
    moveAction->setIcon(QIcon(":/撤回.png"));
    setAttributeAction->setIcon(QIcon(":/属性.png"));
    pointSelectedAction->setIcon(QIcon(":/选择.png"));
    setZIndexAction->setIcon(QIcon(":/设置图形 Z-Index.png"));
    removeAction->setIcon(QIcon(":/删除图形.png"));
    // 使用exec()函数在指定位置弹出菜单，并等待用户进行选择
    QAction *selectedAction = menu.exec(event->screenPos());
    if (selectedAction == moveAction)
    {
        this->setPos(0, 0);
    }
    if (selectedAction == setAttributeAction)
    {
        // 初始化属性对话框
        this->setAttributeDialog();
        // 初始化属性栏点位
        this->dialog->ui->pointXSpinBox->setValue(this->pos.x());
        this->dialog->ui->pointYSpinBox->setValue(this->pos.y());
        // 初始化点大小
        this->dialog->ui->pointSizeSpinBox->setValue(this->pen.width());
        void (QSpinBox::*valueChanged)(int) = &QSpinBox::valueChanged;
        // 设置点位
        QObject::connect(dialog->ui->pointXSpinBox, valueChanged, [=](int val)
                         {
                this->setX(val);
            update(); });
        QObject::connect(dialog->ui->pointYSpinBox, valueChanged, [=](int val)
                         {
                this->setY(val);
            update(); });
        // 设置点的大小
        QObject::connect(dialog->ui->pointSizeSpinBox, valueChanged, [=](int val)
                         {
                this->setSize(val);
            update(); });
        this->dialog->setState(AttributeDialog::DrawPointState);
        this->dialog->exec();
    }
    if (selectedAction == pointSelectedAction)
    {
        emit this->PointSelected(this->id);
    }
    if (selectedAction == setZIndexAction)
    {
        bool ok;
        double zIndex = QInputDialog::getDouble(nullptr, "设置图形 Z-Index", "请输入图形 Z-Index: ", this->zValue(), -2147483647, 2147483647, 2, &ok);
        if (ok)
        {
            this->setZValue(zIndex);
        }
    }
    if (selectedAction == removeAction)
    {
        this->~PointItem();
    }
}

// 形状函数，用于碰撞检测
QPainterPath PointItem::shape() const
{
    // 这里需要在shape()函数中包含1 / 2.0 * QPen.width()，是为了保证图形的碰撞检测更加精确
    // 因为shape()函数所返回的QPainterPath会自动将边界设定为QPen.width()的一半，而这里绘制的点是以QPen的宽度为大小绘制的，如果在形状函数中不包含1 / 2.0 * QPen的宽度，则当发生碰撞检测时，由于QPen的宽度未被考虑，会导致检测结果不准确
    QPainterPath newPath;
    newPath.addRect(this->path.boundingRect().adjusted(-this->pen.width() / 2.0, -this->pen.width() / 2.0, this->pen.width() / 2.0, this->pen.width() / 2.0));
    return (newPath);
}

PointItem::~PointItem()
{
}

LineItem::LineItem(const QPointF &start, const QPointF &end, int id, QGraphicsItem *parent) : GraphItem(id, parent)
{
    this->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->setAcceptHoverEvents(true);
    this->start = start;
    this->end = end;
    // 初始化线实例
    this->lineItem = make_shared<QGraphicsLineItem>(QLineF(this->start, this->end));
    // 初始化路径
    this->path = this->lineItem->shape();
}

// 重载纯虚函数，用来返回绘制图形项的矩形区域
QRectF LineItem::boundingRect() const
{
    return (this->path.boundingRect());
}

// 重载纯虚函数，用来执行实际的绘图操作
void LineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    painter->setPen(this->pen);
    painter->setBrush(this->brush);
    // 若碰撞列表不为空，将其图形项边框变为青色
    if (!this->collidingItems().isEmpty())
    {
        this->pen.setColor(Qt::cyan);
    }
    else
    {
        this->pen.setColor(this->penColor);
    }
    painter->drawPath(this->path);
    update();
}

// 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
void LineItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setFocus();
    this->setCursor(Qt::ClosedHandCursor);
    return (QGraphicsItem::mousePressEvent(event));
}

// 鼠标移动事件
void LineItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseMoveEvent(event));
}

// 鼠标施放事件
void LineItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseReleaseEvent(event));
}

// 滚轮事件
void LineItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    // 检测是否按下Shift键
    if (event->modifiers() & Qt::ShiftModifier)
    {
        // 最大放大到原始图像的50倍
        if (event->delta() > 0 && this->scaleValue >= this->scaleMax)
        {
            return;
        }
        // 图像缩小到最小缩小倍数大小之后就不继续缩小
        else if (event->delta() < 0 && (this->scaleValue <= this->scaleMin))
        {
            return;
        }
        else
        {
            // 因为图元默认的缩放原点为(0,0)，所以设置图元中心点为缩放原点
            this->setTransformOriginPoint(this->path.boundingRect().center());
            // 鼠标滚轮向前滚动
            if (event->delta() > 0)
            {
                // 每次放大10%
                this->scaleValue *= 1.1;
            }
            else
            {
                // 每次缩小10%
                this->scaleValue *= 0.9;
            }
            this->setScale(this->scaleValue);
        }
    }
    // 检测是否按下Alt键
    if (event->modifiers() & Qt::AltModifier)
    {
        // 因为图元默认的旋转原点为(0,0)，所以设置图元中心点为旋转原点
        this->setTransformOriginPoint(this->path.boundingRect().center());
        // 逆时针
        if (event->delta() > 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() + 1);
        }
        // 顺时针
        else if (event->delta() < 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() - 1);
        }
    }
    return (QGraphicsItem::wheelEvent(event));
}

// 键盘按下事件
void LineItem::keyPressEvent(QKeyEvent *event)
{
    // W键向上位移
    if (event->key() == Qt::Key_W)
    {
        this->moveBy(0, -10);
    }
    // S键向下位移
    if (event->key() == Qt::Key_S)
    {
        this->moveBy(0, 10);
    }
    // A键向左位移
    if (event->key() == Qt::Key_A)
    {
        this->moveBy(-10, 0);
    }
    // D键向右位移
    if (event->key() == Qt::Key_D)
    {
        this->moveBy(10, 0);
    }
    // 1键设置模糊效果
    if (event->key() == Qt::Key_1)
    {
        // 模糊效果
        this->blurEffect = new QGraphicsBlurEffect();
        // 设置模糊怎样来执行
        blurEffect->setBlurHints(QGraphicsBlurEffect::QualityHint);
        // 设置模糊半径
        blurEffect->setBlurRadius(8);
        this->setGraphicsEffect(blurEffect);
    }
    // 2键设置染色效果
    if (event->key() == Qt::Key_2)
    {
        // 染色效果
        this->colorizeEffect = new QGraphicsColorizeEffect();
        // 设置染色颜色
        colorizeEffect->setColor(Qt::red);
        // 设置染色效果强弱
        colorizeEffect->setStrength(0.6);
        this->setGraphicsEffect(colorizeEffect);
    }
    // 3键设置阴影效果
    if (event->key() == Qt::Key_3)
    {
        // 阴影效果
        this->dropShadowEffect = new QGraphicsDropShadowEffect();
        // 设置阴影的颜色
        dropShadowEffect->setColor(QColor(63, 63, 63, 100));
        // 设置阴影的模糊半径
        dropShadowEffect->setBlurRadius(2);
        // 设置阴影的偏移值
        dropShadowEffect->setOffset(5);
        this->setGraphicsEffect(dropShadowEffect);
    }
    // 4键设置不透明度
    if (event->key() == Qt::Key_4)
    {
        // 透明效果
        this->opacityEffect = new QGraphicsOpacityEffect();
        // 设置不透明度
        opacityEffect->setOpacity(0.4);
        this->setGraphicsEffect(opacityEffect);
    }
    // 5键停止使用图形效果
    if (event->key() == Qt::Key_5)
    {
        // 停止使用图形效果
        this->graphicsEffect()->setEnabled(false);
    }
}

// 悬停事件，设置光标外观和提示
void LineItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    this->setCursor(Qt::WhatsThisCursor);
    this->setToolTip("Line");
}

// 右键菜单事件，为图形项添加一个右键菜单
void LineItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    // 添加菜单
    QMenu menu;
    QAction *moveAction = menu.addAction("移动至起始点");
    QAction *setAttributeAction = menu.addAction("设置属性");
    QAction *setZIndexAction = menu.addAction("设置图形 Z-Index");
    QAction *removeAction = menu.addAction("删除图形");
    moveAction->setIcon(QIcon(":/撤回.png"));
    setAttributeAction->setIcon(QIcon(":/属性.png"));
    setZIndexAction->setIcon(QIcon(":/设置图形 Z-Index.png"));
    removeAction->setIcon(QIcon(":/删除图形.png"));
    // 使用exec()函数在指定位置弹出菜单，并等待用户进行选择
    QAction *selectedAction = menu.exec(event->screenPos());
    if (selectedAction == moveAction)
    {
        this->setPos(0, 0);
    }
    if (selectedAction == setAttributeAction)
    {
        // 初始化属性对话框
        this->setAttributeDialog();
        // 初始化属性栏
        this->dialog->ui->lineStartXSpinBox->setValue(this->start.x());
        this->dialog->ui->lineStartYSpinBox->setValue(this->start.y());
        this->dialog->ui->lineEndXSpinBox->setValue(this->end.x());
        this->dialog->ui->lineEndYSpinBox->setValue(this->end.y());
        void (QSpinBox::*valueChanged)(int) = &QSpinBox::valueChanged;
        // 设置线的大小
        QObject::connect(dialog->ui->lineStartXSpinBox, valueChanged, [=](int val)
                         {
            this->start.setX(val);
            this->lineItem->setLine(QLineF(this->start, this->end));
            this->path = this->lineItem->shape();
            update(); });
        QObject::connect(dialog->ui->lineStartYSpinBox, valueChanged, [=](int val)
                         {
            this->start.setY(val);
            this->lineItem->setLine(QLineF(this->start, this->end));
            this->path = this->lineItem->shape();
            update(); });
        QObject::connect(dialog->ui->lineEndXSpinBox, valueChanged, [=](int val)
                         {
            this->end.setX(val);
            this->lineItem->setLine(QLineF(this->start, this->end));
            this->path = this->lineItem->shape();
            update(); });
        QObject::connect(dialog->ui->lineEndYSpinBox, valueChanged, [=](int val)
                         {
            this->end.setY(val);
            this->lineItem->setLine(QLineF(this->start, this->end));
            this->path = this->lineItem->shape();
            update(); });
        this->dialog->setState(AttributeDialog::DrawLineState);
        this->dialog->exec();
    }
    if (selectedAction == setZIndexAction)
    {
        bool ok;
        double zIndex = QInputDialog::getDouble(nullptr, "设置图形 Z-Index", "请输入图形 Z-Index: ", this->zValue(), -2147483647, 2147483647, 2, &ok);
        if (ok)
        {
            this->setZValue(zIndex);
        }
    }
    if (selectedAction == removeAction)
    {
        this->~LineItem();
    }
}

// 形状函数，用于碰撞检测
QPainterPath LineItem::shape() const
{
    return (this->path);
}

LineItem::~LineItem()
{
}

PolylineItem::PolylineItem(const QVector<QPointF> &points, int id, QGraphicsItem *parent) : GraphItem(id, parent)
{
    this->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->setAcceptHoverEvents(true);
    // 初始化路径
    if (!points.isEmpty())
    {
        this->path.moveTo(points[0]);
        foreach (const QPointF &point, points)
        {
            this->points.append(point);
            this->path.lineTo(point);
        }
    }
    // 初始化折线实例
    this->polylineItem = make_shared<QGraphicsPathItem>(this->path);
}

// 重载纯虚函数，用来返回绘制图形项的矩形区域
QRectF PolylineItem::boundingRect() const
{
    // 检测折线是否为空
    if (this->points.isEmpty())
    {
        return (QRectF());
    }
    return (this->path.boundingRect());
}

// 重载纯虚函数，用来执行实际的绘图操作
void PolylineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    painter->setPen(this->pen);
    painter->setBrush(this->brush);
    // 若碰撞列表不为空，将其图形项边框变为青色
    if (!this->collidingItems().isEmpty())
    {
        this->pen.setColor(Qt::cyan);
    }
    else
    {
        this->pen.setColor(this->penColor);
    }
    painter->drawPath(this->path);
    update();
}

// 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
void PolylineItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setFocus();
    this->setCursor(Qt::ClosedHandCursor);
    return (QGraphicsItem::mousePressEvent(event));
}

// 鼠标移动事件
void PolylineItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseMoveEvent(event));
}

// 鼠标施放事件
void PolylineItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseReleaseEvent(event));
}

// 滚轮事件
void PolylineItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    // 检测是否按下Shift键
    if (event->modifiers() & Qt::ShiftModifier)
    {
        // 最大放大到原始图像的50倍
        if (event->delta() > 0 && this->scaleValue >= this->scaleMax)
        {
            return;
        }
        // 图像缩小到最小缩小倍数大小之后就不继续缩小
        else if (event->delta() < 0 && (this->scaleValue <= this->scaleMin))
        {
            return;
        }
        else
        {
            // 因为图元默认的缩放原点为(0,0)，所以设置图元中心点为缩放原点
            this->setTransformOriginPoint(this->path.boundingRect().center());
            // 鼠标滚轮向前滚动
            if (event->delta() > 0)
            {
                // 每次放大10%
                this->scaleValue *= 1.1;
            }
            else
            {
                // 每次缩小10%
                this->scaleValue *= 0.9;
            }
            this->setScale(this->scaleValue);
        }
    }
    // 检测是否按下Alt键
    if (event->modifiers() & Qt::AltModifier)
    {
        // 因为图元默认的旋转原点为(0,0)，所以设置图元中心点为旋转原点
        this->setTransformOriginPoint(this->path.boundingRect().center());
        // 逆时针
        if (event->delta() > 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() + 1);
        }
        // 顺时针
        else if (event->delta() < 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() - 1);
        }
    }
    return (QGraphicsItem::wheelEvent(event));
}

// 键盘按下事件
void PolylineItem::keyPressEvent(QKeyEvent *event)
{
    // W键向上位移
    if (event->key() == Qt::Key_W)
    {
        this->moveBy(0, -10);
    }
    // S键向下位移
    if (event->key() == Qt::Key_S)
    {
        this->moveBy(0, 10);
    }
    // A键向左位移
    if (event->key() == Qt::Key_A)
    {
        this->moveBy(-10, 0);
    }
    // D键向右位移
    if (event->key() == Qt::Key_D)
    {
        this->moveBy(10, 0);
    }
    // 1键设置模糊效果
    if (event->key() == Qt::Key_1)
    {
        // 模糊效果
        this->blurEffect = new QGraphicsBlurEffect();
        // 设置模糊怎样来执行
        blurEffect->setBlurHints(QGraphicsBlurEffect::QualityHint);
        // 设置模糊半径
        blurEffect->setBlurRadius(8);
        this->setGraphicsEffect(blurEffect);
    }
    // 2键设置染色效果
    if (event->key() == Qt::Key_2)
    {
        // 染色效果
        this->colorizeEffect = new QGraphicsColorizeEffect();
        // 设置染色颜色
        colorizeEffect->setColor(Qt::red);
        // 设置染色效果强弱
        colorizeEffect->setStrength(0.6);
        this->setGraphicsEffect(colorizeEffect);
    }
    // 3键设置阴影效果
    if (event->key() == Qt::Key_3)
    {
        // 阴影效果
        this->dropShadowEffect = new QGraphicsDropShadowEffect();
        // 设置阴影的颜色
        dropShadowEffect->setColor(QColor(63, 63, 63, 100));
        // 设置阴影的模糊半径
        dropShadowEffect->setBlurRadius(2);
        // 设置阴影的偏移值
        dropShadowEffect->setOffset(5);
        this->setGraphicsEffect(dropShadowEffect);
    }
    // 4键设置不透明度
    if (event->key() == Qt::Key_4)
    {
        // 透明效果
        this->opacityEffect = new QGraphicsOpacityEffect();
        // 设置不透明度
        opacityEffect->setOpacity(0.4);
        this->setGraphicsEffect(opacityEffect);
    }
    // 5键停止使用图形效果
    if (event->key() == Qt::Key_5)
    {
        // 停止使用图形效果
        this->graphicsEffect()->setEnabled(false);
    }
}

// 悬停事件，设置光标外观和提示
void PolylineItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    this->setCursor(Qt::WhatsThisCursor);
    this->setToolTip("Polyline");
}

// 右键菜单事件，为图形项添加一个右键菜单
void PolylineItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    // 添加菜单
    QMenu menu;
    QAction *moveAction = menu.addAction("移动至起始点");
    QAction *setZIndexAction = menu.addAction("设置图形 Z-Index");
    QAction *removeAction = menu.addAction("删除图形");
    moveAction->setIcon(QIcon(":/撤回.png"));
    setZIndexAction->setIcon(QIcon(":/设置图形 Z-Index.png"));
    removeAction->setIcon(QIcon(":/删除图形.png"));
    // 使用exec()函数在指定位置弹出菜单，并等待用户进行选择
    QAction *selectedAction = menu.exec(event->screenPos());
    if (selectedAction == moveAction)
    {
        this->setPos(0, 0);
    }
    if (selectedAction == setZIndexAction)
    {
        bool ok;
        double zIndex = QInputDialog::getDouble(nullptr, "设置图形 Z-Index", "请输入图形 Z-Index: ", this->zValue(), -2147483647, 2147483647, 2, &ok);
        if (ok)
        {
            this->setZValue(zIndex);
        }
    }
    if (selectedAction == removeAction)
    {
        this->~PolylineItem();
    }
}

// 形状函数，用于碰撞检测
QPainterPath PolylineItem::shape() const
{ // 为空返回空的shape
    if (this->points.isEmpty())
    {
        return (QPainterPath());
    }
    // 返回此路径的简化版本。这意味着合并所有相交的子路径，并返回不包含相交边的路径。连续的平行线也将合并
    // 简化路径将始终使用默认填充规则 Qt::OddEvenFill。由于进行贝塞尔曲线相交的数值不稳定，贝塞尔曲线可能会展平为线段
    return (this->path.simplified());
}

PolylineItem::~PolylineItem()
{
}

RectangleItem::RectangleItem(const QPointF &start, const QPointF &end, int id, QGraphicsItem *parent) : GraphItem(id, parent)
{
    this->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->setAcceptHoverEvents(true);
    this->lastPos = start;
    this->endPos = end;
    this->width = this->endPos.x() - this->lastPos.x();
    this->height = this->endPos.y() - this->lastPos.y();
    // 初始化矩形控制点、矩形实例和矩形路径
    if (this->width > 0 && this->height > 0)
    {
        this->topLeft = QPointF(this->lastPos.x(), this->lastPos.y());
        this->topRight = QPointF(this->endPos.x() + width, this->lastPos.y());
        this->bottomLeft = QPointF(this->lastPos.x(), this->endPos.y());
        this->bottomRight = QPointF(this->endPos.x(), this->endPos.y());
        this->rectangleItem = make_shared<QGraphicsRectItem>(QRectF(this->lastPos, QSizeF(this->width, this->height)));
        this->path.addRect(this->rectangleItem->rect());
    }
    else if (this->width < 0 && this->height > 0)
    {
        this->topLeft = QPointF(this->endPos.x(), this->lastPos.y());
        this->topRight = QPointF(this->lastPos.x(), this->lastPos.y());
        this->bottomLeft = QPointF(this->endPos.x(), this->endPos.y());
        this->bottomRight = QPointF(this->lastPos.x(), this->endPos.y());
        this->rectangleItem = make_shared<QGraphicsRectItem>(QRectF(topLeft, QSizeF(qAbs(this->width), this->height)));
        this->path.addRect(this->rectangleItem->rect());
    }
    else if (this->width > 0 && this->height < 0)
    {
        this->topLeft = QPointF(this->lastPos.x(), this->endPos.y());
        this->topRight = QPointF(this->endPos.x(), this->endPos.y());
        this->bottomLeft = QPointF(this->lastPos.x(), this->lastPos.y());
        this->bottomRight = QPointF(this->endPos.x(), this->lastPos.y());
        this->rectangleItem = make_shared<QGraphicsRectItem>(QRectF(topLeft, QSizeF(this->width, qAbs(this->height))));
        this->path.addRect(this->rectangleItem->rect());
    }
    else
    {
        this->topLeft = QPointF(this->endPos.x(), this->endPos.y());
        this->topRight = QPointF(this->lastPos.x(), this->endPos.y());
        this->bottomLeft = QPointF(this->endPos.x(), this->lastPos.y());
        this->bottomRight = QPointF(this->lastPos.x(), this->lastPos.y());
        this->rectangleItem = make_shared<QGraphicsRectItem>(QRectF(this->endPos, QSizeF(qAbs(this->width), qAbs(this->height))));
        this->path.addRect(this->rectangleItem->rect());
    }
}

// 重载纯虚函数，用来返回绘制图形项的矩形区域
QRectF RectangleItem::boundingRect() const
{
    return (this->path.boundingRect());
}

// 重载纯虚函数，用来执行实际的绘图操作
void RectangleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    painter->setPen(this->pen);
    painter->setBrush(this->brush);
    // 若碰撞列表不为空，将其图形项边框变为青色
    if (!this->collidingItems().isEmpty())
    {
        this->pen.setColor(Qt::cyan);
    }
    else
    {
        this->pen.setColor(this->penColor);
    }
    painter->drawPath(this->path);
    update();
}

// 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
void RectangleItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setFocus();
    this->setCursor(Qt::ClosedHandCursor);
    return (QGraphicsItem::mousePressEvent(event));
}

// 鼠标移动事件
void RectangleItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseMoveEvent(event));
}

// 鼠标施放事件
void RectangleItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseReleaseEvent(event));
}

// 滚轮事件
void RectangleItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    // 检测是否按下Shift键
    if (event->modifiers() & Qt::ShiftModifier)
    {
        // 最大放大到原始图像的50倍
        if (event->delta() > 0 && this->scaleValue >= this->scaleMax)
        {
            return;
        }
        // 图像缩小到最小缩小倍数大小之后就不继续缩小
        else if (event->delta() < 0 && (this->scaleValue <= this->scaleMin))
        {
            return;
        }
        else
        {
            // 因为图元默认的缩放原点为(0,0)，所以设置图元中心点为缩放原点
            this->setTransformOriginPoint(this->path.boundingRect().center());
            // 鼠标滚轮向前滚动
            if (event->delta() > 0)
            {
                // 每次放大10%
                this->scaleValue *= 1.1;
            }
            else
            {
                // 每次缩小10%
                this->scaleValue *= 0.9;
            }
            this->setScale(this->scaleValue);
        }
    }
    // 检测是否按下Alt键
    if (event->modifiers() & Qt::AltModifier)
    {
        // 因为图元默认的旋转原点为(0,0)，所以设置图元中心点为旋转原点
        this->setTransformOriginPoint(this->path.boundingRect().center());
        // 逆时针
        if (event->delta() > 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() + 1);
        }
        // 顺时针
        else if (event->delta() < 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() - 1);
        }
    }
    return (QGraphicsItem::wheelEvent(event));
}

// 键盘按下事件
void RectangleItem::keyPressEvent(QKeyEvent *event)
{
    // W键向上位移
    if (event->key() == Qt::Key_W)
    {
        this->moveBy(0, -10);
    }
    // S键向下位移
    if (event->key() == Qt::Key_S)
    {
        this->moveBy(0, 10);
    }
    // A键向左位移
    if (event->key() == Qt::Key_A)
    {
        this->moveBy(-10, 0);
    }
    // D键向右位移
    if (event->key() == Qt::Key_D)
    {
        this->moveBy(10, 0);
    }
    // 1键设置模糊效果
    if (event->key() == Qt::Key_1)
    {
        // 模糊效果
        this->blurEffect = new QGraphicsBlurEffect();
        // 设置模糊怎样来执行
        blurEffect->setBlurHints(QGraphicsBlurEffect::QualityHint);
        // 设置模糊半径
        blurEffect->setBlurRadius(8);
        this->setGraphicsEffect(blurEffect);
    }
    // 2键设置染色效果
    if (event->key() == Qt::Key_2)
    {
        // 染色效果
        this->colorizeEffect = new QGraphicsColorizeEffect();
        // 设置染色颜色
        colorizeEffect->setColor(Qt::red);
        // 设置染色效果强弱
        colorizeEffect->setStrength(0.6);
        this->setGraphicsEffect(colorizeEffect);
    }
    // 3键设置阴影效果
    if (event->key() == Qt::Key_3)
    {
        // 阴影效果
        this->dropShadowEffect = new QGraphicsDropShadowEffect();
        // 设置阴影的颜色
        dropShadowEffect->setColor(QColor(63, 63, 63, 100));
        // 设置阴影的模糊半径
        dropShadowEffect->setBlurRadius(2);
        // 设置阴影的偏移值
        dropShadowEffect->setOffset(5);
        this->setGraphicsEffect(dropShadowEffect);
    }
    // 4键设置不透明度
    if (event->key() == Qt::Key_4)
    {
        // 透明效果
        this->opacityEffect = new QGraphicsOpacityEffect();
        // 设置不透明度
        opacityEffect->setOpacity(0.4);
        this->setGraphicsEffect(opacityEffect);
    }
    // 5键停止使用图形效果
    if (event->key() == Qt::Key_5)
    {
        // 停止使用图形效果
        this->graphicsEffect()->setEnabled(false);
    }
}

// 悬停事件，设置光标外观和提示
void RectangleItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    this->setCursor(Qt::WhatsThisCursor);
    this->setToolTip("Rectangle");
}

// 右键菜单事件，为图形项添加一个右键菜单
void RectangleItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    // 添加菜单
    QMenu menu;
    QAction *moveAction = menu.addAction("移动至起始点");
    QAction *setAttributeAction = menu.addAction("设置属性");
    QAction *setZIndexAction = menu.addAction("设置图形 Z-Index");
    QAction *removeAction = menu.addAction("删除图形");
    moveAction->setIcon(QIcon(":/撤回.png"));
    setAttributeAction->setIcon(QIcon(":/属性.png"));
    setZIndexAction->setIcon(QIcon(":/设置图形 Z-Index.png"));
    removeAction->setIcon(QIcon(":/删除图形.png"));
    // 使用exec()函数在指定位置弹出菜单，并等待用户进行选择
    QAction *selectedAction = menu.exec(event->screenPos());
    if (selectedAction == moveAction)
    {
        this->setPos(0, 0);
    }
    if (selectedAction == setAttributeAction)
    {
        // 初始化属性对话框
        this->setAttributeDialog();
        // 初始化属性栏中矩形点位
        this->dialog->ui->rectangleTopLeftXSpinBox->setValue(this->topLeft.x());
        this->dialog->ui->rectangleTopLeftYSpinBox->setValue(this->topLeft.y());
        this->dialog->ui->rectangleBottomRightXSpinBox->setValue(this->bottomRight.x());
        this->dialog->ui->rectangleBottomRightYSpinBox->setValue(this->bottomRight.y());
        void (QSpinBox::*valueChanged)(int) = &QSpinBox::valueChanged;
        // 设置矩形的大小
        QObject::connect(dialog->ui->rectangleTopLeftXSpinBox, valueChanged, [=](int val)
                         {
            this->topLeft.setX(val);
            this->topRight.setX(val);
            int deltaWidth = val - this->topLeft.x();
            this->width += deltaWidth;
            this->rectangleItem->setRect(QRectF(this->topLeft, this->bottomRight));
            this->path = this->rectangleItem->shape();
            update(); });
        QObject::connect(dialog->ui->rectangleTopLeftYSpinBox, valueChanged, [=](int val)
                         {
            this->topLeft.setY(val);
            this->topRight.setY(val);
            int deltaWidth = val - this->topLeft.y();
            this->width += deltaWidth;
            this->rectangleItem->setRect(QRectF(this->topLeft, this->bottomRight));
            this->path = this->rectangleItem->shape();
            update(); });
        QObject::connect(dialog->ui->rectangleBottomRightXSpinBox, valueChanged, [=](int val)
                         {
            this->bottomRight.setX(val);
            this->bottomRight.setX(val);
            int deltaWidth = val - this->bottomRight.x();
            this->height += deltaWidth;
            this->rectangleItem->setRect(QRectF(this->topLeft, this->bottomRight));
            this->path = this->rectangleItem->shape();
            update(); });
        QObject::connect(dialog->ui->rectangleBottomRightYSpinBox, valueChanged, [=](int val)
                         {
            this->bottomRight.setY(val);
            this->bottomRight.setY(val);
            int deltaWidth = val - this->bottomRight.y();
            this->height += deltaWidth;
            this->rectangleItem->setRect(QRectF(this->topLeft, this->bottomRight));
            this->path = this->rectangleItem->shape();
            update(); });
        this->dialog->setState(AttributeDialog::DrawRectangleState);
        this->dialog->exec();
    }
    if (selectedAction == setZIndexAction)
    {
        bool ok;
        double zIndex = QInputDialog::getDouble(nullptr, "设置图形 Z-Index", "请输入图形 Z-Index: ", this->zValue(), -2147483647, 2147483647, 2, &ok);
        if (ok)
        {
            this->setZValue(zIndex);
        }
    }
    if (selectedAction == removeAction)
    {
        this->~RectangleItem();
    }
}

// 形状函数，用于碰撞检测
QPainterPath RectangleItem::shape() const
{
    return (this->path);
}

RectangleItem::~RectangleItem()
{
}

CircleItem::CircleItem(const QPointF &lastPos, const QPointF &endPos, int id, QGraphicsItem *parent) : GraphItem(id, parent)
{
    this->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->setAcceptHoverEvents(true);
    this->lastPos = lastPos;
    this->endPos = endPos;
    this->center = this->lastPos;
    this->radius = this->getRadius();
    // 初始化圆实例
    this->circleItem = make_shared<QGraphicsEllipseItem>(QRectF(QPointF((this->center.x() - this->radius), (this->center.y() - this->radius)), QSizeF(2 * this->radius, 2 * this->radius)));
    // 初始化路径
    this->path.addEllipse(this->center, this->radius, this->radius);
}

double CircleItem::getRadius() const
{
    return (sqrt((qPow((this->lastPos.x() - this->endPos.x()), 2) + qPow((this->lastPos.y() - this->endPos.y()), 2))));
}

// 重载纯虚函数，用来返回绘制图形项的矩形区域
QRectF CircleItem::boundingRect() const
{
    return (this->path.boundingRect());
}

// 重载纯虚函数，用来执行实际的绘图操作
void CircleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    painter->setPen(this->pen);
    painter->setBrush(this->brush);
    // 若碰撞列表不为空，将其图形项边框变为青色
    if (!this->collidingItems().isEmpty())
    {
        this->pen.setColor(Qt::cyan);
    }
    else
    {
        this->pen.setColor(this->penColor);
    }
    painter->drawPath(this->path);
    update();
}

// 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
void CircleItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setFocus();
    this->setCursor(Qt::ClosedHandCursor);
    return (QGraphicsItem::mousePressEvent(event));
}

// 鼠标移动事件
void CircleItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseMoveEvent(event));
}

// 鼠标施放事件
void CircleItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseReleaseEvent(event));
}

// 滚轮事件
void CircleItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    // 检测是否按下Shift键
    if (event->modifiers() & Qt::ShiftModifier)
    {
        // 最大放大到原始图像的50倍
        if (event->delta() > 0 && this->scaleValue >= this->scaleMax)
        {
            return;
        }
        // 图像缩小到最小缩小倍数大小之后就不继续缩小
        else if (event->delta() < 0 && (this->scaleValue <= this->scaleMin))
        {
            return;
        }
        else
        {
            // 因为图元默认的缩放原点为(0,0)，所以设置图元中心点为缩放原点
            this->setTransformOriginPoint(this->path.boundingRect().center());
            // 鼠标滚轮向前滚动
            if (event->delta() > 0)
            {
                // 每次放大10%
                this->scaleValue *= 1.1;
            }
            else
            {
                // 每次缩小10%
                this->scaleValue *= 0.9;
            }
            this->setScale(this->scaleValue);
        }
    }
    // 检测是否按下Alt键
    if (event->modifiers() & Qt::AltModifier)
    {
        // 因为图元默认的旋转原点为(0,0)，所以设置图元中心点为旋转原点
        this->setTransformOriginPoint(this->path.boundingRect().center());
        // 逆时针
        if (event->delta() > 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() + 1);
        }
        // 顺时针
        else if (event->delta() < 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() - 1);
        }
    }
    return (QGraphicsItem::wheelEvent(event));
}

// 键盘按下事件
void CircleItem::keyPressEvent(QKeyEvent *event)
{
    // W键向上位移
    if (event->key() == Qt::Key_W)
    {
        this->moveBy(0, -10);
    }
    // S键向下位移
    if (event->key() == Qt::Key_S)
    {
        this->moveBy(0, 10);
    }
    // A键向左位移
    if (event->key() == Qt::Key_A)
    {
        this->moveBy(-10, 0);
    }
    // D键向右位移
    if (event->key() == Qt::Key_D)
    {
        this->moveBy(10, 0);
    }
    // 1键设置模糊效果
    if (event->key() == Qt::Key_1)
    {
        // 模糊效果
        this->blurEffect = new QGraphicsBlurEffect();
        // 设置模糊怎样来执行
        blurEffect->setBlurHints(QGraphicsBlurEffect::QualityHint);
        // 设置模糊半径
        blurEffect->setBlurRadius(8);
        this->setGraphicsEffect(blurEffect);
    }
    // 2键设置染色效果
    if (event->key() == Qt::Key_2)
    {
        // 染色效果
        this->colorizeEffect = new QGraphicsColorizeEffect();
        // 设置染色颜色
        colorizeEffect->setColor(Qt::red);
        // 设置染色效果强弱
        colorizeEffect->setStrength(0.6);
        this->setGraphicsEffect(colorizeEffect);
    }
    // 3键设置阴影效果
    if (event->key() == Qt::Key_3)
    {
        // 阴影效果
        this->dropShadowEffect = new QGraphicsDropShadowEffect();
        // 设置阴影的颜色
        dropShadowEffect->setColor(QColor(63, 63, 63, 100));
        // 设置阴影的模糊半径
        dropShadowEffect->setBlurRadius(2);
        // 设置阴影的偏移值
        dropShadowEffect->setOffset(5);
        this->setGraphicsEffect(dropShadowEffect);
    }
    // 4键设置不透明度
    if (event->key() == Qt::Key_4)
    {
        // 透明效果
        this->opacityEffect = new QGraphicsOpacityEffect();
        // 设置不透明度
        opacityEffect->setOpacity(0.4);
        this->setGraphicsEffect(opacityEffect);
    }
    // 5键停止使用图形效果
    if (event->key() == Qt::Key_5)
    {
        // 停止使用图形效果
        this->graphicsEffect()->setEnabled(false);
    }
}

// 悬停事件，设置光标外观和提示
void CircleItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    this->setCursor(Qt::WhatsThisCursor);
    this->setToolTip("Circle");
}

// 右键菜单事件，为图形项添加一个右键菜单
void CircleItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    // 添加菜单
    QMenu menu;
    QAction *moveAction = menu.addAction("移动至起始点");
    QAction *setAttributeAction = menu.addAction("设置属性");
    QAction *setZIndexAction = menu.addAction("设置图形 Z-Index");
    QAction *removeAction = menu.addAction("删除图形");
    moveAction->setIcon(QIcon(":/撤回.png"));
    setAttributeAction->setIcon(QIcon(":/属性.png"));
    setZIndexAction->setIcon(QIcon(":/设置图形 Z-Index.png"));
    removeAction->setIcon(QIcon(":/删除图形.png"));
    // 使用exec()函数在指定位置弹出菜单，并等待用户进行选择
    QAction *selectedAction = menu.exec(event->screenPos());
    if (selectedAction == moveAction)
    {
        this->setPos(0, 0);
    }
    if (selectedAction == setAttributeAction)
    {
        // 初始化属性对话框
        this->setAttributeDialog();
        // 初始化属性栏中圆点位
        this->dialog->ui->circleCenterXSpinBox->setValue(this->lastPos.x());
        this->dialog->ui->circleCenterYSpinBox->setValue(this->lastPos.y());
        this->dialog->ui->circleRadiusSpinBox->setValue(this->radius);
        void (QSpinBox::*valueChanged)(int) = &QSpinBox::valueChanged;
        // 设置圆的大小
        QObject::connect(dialog->ui->circleCenterXSpinBox, valueChanged, [=](int val)
                         {
            int deltaX = val - this->lastPos.x();
            this->lastPos.setX(val);
            this->endPos.setX(this->endPos.x() + deltaX);
            this->center = this->lastPos;
            this->radius = this->getRadius();
            this->circleItem->setRect(QRectF(QPointF((this->center.x() - this->radius), (this->center.y() - this->radius)), QSizeF(2 * this->radius, 2 * this->radius)));
            this->path = this->circleItem->shape();
            update(); });
        QObject::connect(dialog->ui->circleCenterYSpinBox, valueChanged, [=](int val)
                         {
            int deltaY = val - this->lastPos.y();
            this->lastPos.setY(val);
            this->endPos.setY(this->endPos.y() + deltaY);
            this->center = this->lastPos;
            this->radius = this->getRadius();
            this->circleItem->setRect(QRectF(QPointF((this->center.x() - this->radius), (this->center.y() - this->radius)), QSizeF(2 * this->radius, 2 * this->radius)));
            this->path = this->circleItem->shape();
            update(); });
        QObject::connect(dialog->ui->circleRadiusSpinBox, valueChanged, [=](int val)
                         {
            this->radius = val;
            this->circleItem->setRect(QRectF(QPointF((this->center.x() - this->radius), (this->center.y() - this->radius)), QSizeF(2 * this->radius, 2 * this->radius)));
            this->path = this->circleItem->shape();
            update(); });
        this->dialog->setState(AttributeDialog::DrawCircleState);
        this->dialog->exec();
    }
    if (selectedAction == setZIndexAction)
    {
        bool ok;
        double zIndex = QInputDialog::getDouble(nullptr, "设置图形 Z-Index", "请输入图形 Z-Index: ", this->zValue(), -2147483647, 2147483647, 2, &ok);
        if (ok)
        {
            this->setZValue(zIndex);
        }
    }
    if (selectedAction == removeAction)
    {
        this->~CircleItem();
    }
}

// 形状函数，用于碰撞检测
QPainterPath CircleItem::shape() const
{
    return (this->path);
}

CircleItem::~CircleItem()
{
}

SectorItem::SectorItem(const QPointF &start, const QPointF &center, const QPointF &end, int id, QGraphicsItem *parent) : GraphItem(id, parent)
{
    this->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->setAcceptHoverEvents(true);
    // 初始化扇形的第一条线的起点，最后一条线的终点，圆心
    this->start = start;
    this->center = center;
    this->end = end;
    this->benchmark = QLineF(QPointF(this->center.x() + 1, this->center.y()), QPointF(this->center));
    this->line1 = QLineF(this->start, this->center);
    this->line2 = QLineF(this->end, this->center);
    this->startAngle = this->benchmark.angleTo(line1);
    this->spanAngle = this->line1.angleTo(line2);
    double radius1 = this->getRadius(this->start, this->center);
    double radius2 = this->getRadius(this->center, this->end);
    this->halfRect = radius1 < radius2 ? radius1 : radius2;
    this->topLeft = QPointF(this->center.x() - halfRect, this->center.y() - halfRect);
    this->bottomRight = QPointF(this->center.x() + halfRect, this->center.y() + halfRect);
    // 实例化扇形实体
    this->sectorItem = make_shared<QGraphicsEllipseItem>(QRectF(topLeft, bottomRight));
    this->sectorItem->setStartAngle(this->startAngle * 16);
    this->sectorItem->setSpanAngle(this->spanAngle * 16);
    // 初始化扇形路径
    this->path = this->sectorItem->shape();
}

double SectorItem::getRadius(const QPointF &p1, const QPointF &p2) const
{
    return (sqrt((qPow((p1.x() - p2.x()), 2) + qPow((p1.y() - p2.y()), 2))));
}

// 重载纯虚函数，用来返回绘制图形项的矩形区域
QRectF SectorItem::boundingRect() const
{
    return (this->path.boundingRect());
}

// 重载纯虚函数，用来执行实际的绘图操作
void SectorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    painter->setPen(this->pen);
    painter->setBrush(this->brush);
    // 若碰撞列表不为空，将其图形项边框变为青色
    if (!this->collidingItems().isEmpty())
    {
        this->pen.setColor(Qt::cyan);
    }
    else
    {
        this->pen.setColor(this->penColor);
    }
    painter->drawPath(this->path);
    update();
}

// 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
void SectorItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setFocus();
    this->setCursor(Qt::ClosedHandCursor);
    return (QGraphicsItem::mousePressEvent(event));
}

// 鼠标移动事件
void SectorItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseMoveEvent(event));
}

// 鼠标施放事件
void SectorItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseReleaseEvent(event));
}

// 滚轮事件
void SectorItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    // 检测是否按下Shift键
    if (event->modifiers() & Qt::ShiftModifier)
    {
        // 最大放大到原始图像的50倍
        if (event->delta() > 0 && this->scaleValue >= this->scaleMax)
        {
            return;
        }
        // 图像缩小到最小缩小倍数大小之后就不继续缩小
        else if (event->delta() < 0 && (this->scaleValue <= this->scaleMin))
        {
            return;
        }
        else
        {
            // 因为图元默认的缩放原点为(0,0)，所以设置图元中心点为缩放原点
            this->setTransformOriginPoint(this->path.boundingRect().center());
            // 鼠标滚轮向前滚动
            if (event->delta() > 0)
            {
                // 每次放大10%
                this->scaleValue *= 1.1;
            }
            else
            {
                // 每次缩小10%
                this->scaleValue *= 0.9;
            }
            this->setScale(this->scaleValue);
        }
    }
    // 检测是否按下Alt键
    if (event->modifiers() & Qt::AltModifier)
    {
        // 因为图元默认的旋转原点为(0,0)，所以设置图元中心点为旋转原点
        this->setTransformOriginPoint(this->path.boundingRect().center());
        // 逆时针
        if (event->delta() > 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() + 1);
        }
        // 顺时针
        else if (event->delta() < 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() - 1);
        }
    }
    return (QGraphicsItem::wheelEvent(event));
}

// 键盘按下事件
void SectorItem::keyPressEvent(QKeyEvent *event)
{
    // W键向上位移
    if (event->key() == Qt::Key_W)
    {
        this->moveBy(0, -10);
    }
    // S键向下位移
    if (event->key() == Qt::Key_S)
    {
        this->moveBy(0, 10);
    }
    // A键向左位移
    if (event->key() == Qt::Key_A)
    {
        this->moveBy(-10, 0);
    }
    // D键向右位移
    if (event->key() == Qt::Key_D)
    {
        this->moveBy(10, 0);
    }
    // 1键设置模糊效果
    if (event->key() == Qt::Key_1)
    {
        // 模糊效果
        this->blurEffect = new QGraphicsBlurEffect();
        // 设置模糊怎样来执行
        blurEffect->setBlurHints(QGraphicsBlurEffect::QualityHint);
        // 设置模糊半径
        blurEffect->setBlurRadius(8);
        this->setGraphicsEffect(blurEffect);
    }
    // 2键设置染色效果
    if (event->key() == Qt::Key_2)
    {
        // 染色效果
        this->colorizeEffect = new QGraphicsColorizeEffect();
        // 设置染色颜色
        colorizeEffect->setColor(Qt::red);
        // 设置染色效果强弱
        colorizeEffect->setStrength(0.6);
        this->setGraphicsEffect(colorizeEffect);
    }
    // 3键设置阴影效果
    if (event->key() == Qt::Key_3)
    {
        // 阴影效果
        this->dropShadowEffect = new QGraphicsDropShadowEffect();
        // 设置阴影的颜色
        dropShadowEffect->setColor(QColor(63, 63, 63, 100));
        // 设置阴影的模糊半径
        dropShadowEffect->setBlurRadius(2);
        // 设置阴影的偏移值
        dropShadowEffect->setOffset(5);
        this->setGraphicsEffect(dropShadowEffect);
    }
    // 4键设置不透明度
    if (event->key() == Qt::Key_4)
    {
        // 透明效果
        this->opacityEffect = new QGraphicsOpacityEffect();
        // 设置不透明度
        opacityEffect->setOpacity(0.4);
        this->setGraphicsEffect(opacityEffect);
    }
    // 5键停止使用图形效果
    if (event->key() == Qt::Key_5)
    {
        // 停止使用图形效果
        this->graphicsEffect()->setEnabled(false);
    }
}

// 悬停事件，设置光标外观和提示
void SectorItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    this->setCursor(Qt::WhatsThisCursor);
    this->setToolTip("Sector");
}

// 右键菜单事件，为图形项添加一个右键菜单
void SectorItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    // 添加菜单
    QMenu menu;
    QAction *moveAction = menu.addAction("移动至起始点");
    QAction *setAttributeAction = menu.addAction("设置属性");
    QAction *setZIndexAction = menu.addAction("设置图形 Z-Index");
    QAction *removeAction = menu.addAction("删除图形");
    moveAction->setIcon(QIcon(":/撤回.png"));
    setAttributeAction->setIcon(QIcon(":/属性.png"));
    setZIndexAction->setIcon(QIcon(":/设置图形 Z-Index.png"));
    removeAction->setIcon(QIcon(":/删除图形.png"));
    // 使用exec()函数在指定位置弹出菜单，并等待用户进行选择
    QAction *selectedAction = menu.exec(event->screenPos());
    if (selectedAction == moveAction)
    {
        this->setPos(0, 0);
    }
    if (selectedAction == setAttributeAction)
    {
        // 初始化属性对话框
        this->setAttributeDialog();
        // 初始化属性栏中扇形中心点位
        this->dialog->ui->sectorCenterXSpinBox->setValue(this->center.x());
        this->dialog->ui->sectorCenterYSpinBox->setValue(this->center.y());
        this->dialog->ui->sectorStartAngleSpinBox->setValue(this->startAngle);
        this->dialog->ui->sectorEndAngleSpinBox->setValue(this->spanAngle);
        void (QSpinBox::*valueChanged)(int) = &QSpinBox::valueChanged;
        // 设置扇形中心点位
        QObject::connect(dialog->ui->sectorCenterXSpinBox, valueChanged, [=](int val)
                         {
            this->center.setX(val);
            this->benchmark = QLineF(QPointF(this->center.x() + 1, this->center.y()), QPointF(this->center));
            this->line1 = QLineF(this->start, this->center);
            this->line2 = QLineF(this->end, this->center);
            this->startAngle = this->benchmark.angleTo(line1);
            this->spanAngle = this->line1.angleTo(line2);
            double radius1 = this->getRadius(this->start, this->center);
            double radius2 = this->getRadius(this->center, this->end);
            this->halfRect = radius1 < radius2 ? radius1 : radius2;
            this->topLeft = QPointF(this->center.x() - halfRect, this->center.y() - halfRect);
            this->bottomRight = QPointF(this->center.x() + halfRect, this->center.y() + halfRect);
            this->sectorItem = make_shared<QGraphicsEllipseItem>(QRectF(topLeft, bottomRight));
            this->sectorItem->setStartAngle(this->startAngle * 16);
            this->sectorItem->setSpanAngle(this->spanAngle * 16);
            this->path = this->sectorItem->shape();
            update(); });
        QObject::connect(dialog->ui->sectorCenterYSpinBox, valueChanged, [=](int val)
                         {
            this->center.setY(val);
            this->benchmark = QLineF(QPointF(this->center.x() + 1, this->center.y()), QPointF(this->center));
            this->line1 = QLineF(this->start, this->center);
            this->line2 = QLineF(this->end, this->center);
            this->startAngle = this->benchmark.angleTo(line1);
            this->spanAngle = this->line1.angleTo(line2);
            double radius1 = this->getRadius(this->start, this->center);
            double radius2 = this->getRadius(this->center, this->end);
            this->halfRect = radius1 < radius2 ? radius1 : radius2;
            this->topLeft = QPointF(this->center.x() - halfRect, this->center.y() - halfRect);
            this->bottomRight = QPointF(this->center.x() + halfRect, this->center.y() + halfRect);
            this->sectorItem = make_shared<QGraphicsEllipseItem>(QRectF(topLeft, bottomRight));
            this->sectorItem->setStartAngle(this->startAngle * 16);
            this->sectorItem->setSpanAngle(this->spanAngle * 16);
            this->path = this->sectorItem->shape();
            update(); });
        // 设置扇形旋转角
        QObject::connect(dialog->ui->sectorStartAngleSpinBox, valueChanged, [=](int val)
                         {
            double acceptVal = val * 1.0;
            double deltaX = this->line1.length() * qCos(qDegreesToRadians(acceptVal)) - this->line1.length() * qCos(qDegreesToRadians(this->startAngle));
            double deltaY = this->line1.length() * qSin(qDegreesToRadians(acceptVal)) - this->line1.length() * qSin(qDegreesToRadians(this->startAngle));
            this->start = QPointF((this->start.x() + deltaX), (this->start.y() - deltaY));
            this->line1 = QLineF(this->start, this->center);
            this->line2 = QLineF(this->end, this->center);
            this->startAngle = this->benchmark.angleTo(line1);
            this->spanAngle = this->line1.angleTo(line2);
            this->sectorItem->setStartAngle(this->startAngle * 16);
            this->sectorItem->setSpanAngle(this->spanAngle * 16);
            this->path = this->sectorItem->shape();
            update(); });
        QObject::connect(dialog->ui->sectorEndAngleSpinBox, valueChanged, [=](int val)
                         {
            double acceptVal = val * 1.0;
            double deltaX = this->line2.length() * qCos(qDegreesToRadians(acceptVal)) - this->line2.length() * qCos(qDegreesToRadians(this->spanAngle));
            double deltaY = this->line2.length() * qSin(qDegreesToRadians(acceptVal)) - this->line2.length() * qSin(qDegreesToRadians(this->spanAngle));
            this->end = QPointF((this->end.x() + deltaX), (this->end.y() - deltaY));
            this->line1 = QLineF(this->start, this->center);
            this->line2 = QLineF(this->end, this->center);
            this->startAngle = this->benchmark.angleTo(line1);
            this->spanAngle = this->line1.angleTo(line2);
            this->sectorItem->setStartAngle(this->startAngle * 16);
            this->sectorItem->setSpanAngle(this->spanAngle * 16);
            this->path = this->sectorItem->shape();
            update(); });
        this->dialog->setState(AttributeDialog::DrawSectorState);
        this->dialog->exec();
    }
    if (selectedAction == setZIndexAction)
    {
        bool ok;
        double zIndex = QInputDialog::getDouble(nullptr, "设置图形 Z-Index", "请输入图形 Z-Index: ", this->zValue(), -2147483647, 2147483647, 2, &ok);
        if (ok)
        {
            this->setZValue(zIndex);
        }
    }
    if (selectedAction == removeAction)
    {
        this->~SectorItem();
    }
}

// 形状函数，用于碰撞检测
QPainterPath SectorItem::shape() const
{
    return (this->path);
}

SectorItem::~SectorItem()
{
}

PolygonItem::PolygonItem(const QVector<QPointF> &points, int id, QGraphicsItem *parent) : GraphItem(id, parent)
{
    this->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->setAcceptHoverEvents(true);
    // 初始化存储多边形节点
    foreach (const QPointF &point, points)
    {
        this->points.append(point);
    }
    // 初始化多边形实例
    this->polygonItem = make_shared<QGraphicsPolygonItem>(this->points);
    // 初始化多边形路径
    this->path = polygonItem->shape();
}

// 重载纯虚函数，用来返回绘制图形项的矩形区域
QRectF PolygonItem::boundingRect() const
{
    return (this->path.boundingRect());
}

// 重载纯虚函数，用来执行实际的绘图操作
void PolygonItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    painter->setPen(this->pen);
    painter->setBrush(this->brush);
    // 若碰撞列表不为空，将其图形项边框变为青色
    if (!this->collidingItems().isEmpty())
    {
        this->pen.setColor(Qt::cyan);
    }
    else
    {
        this->pen.setColor(this->penColor);
    }
    painter->drawPath(this->path);
    update();
}

// 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
void PolygonItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setFocus();
    this->setCursor(Qt::ClosedHandCursor);
    return (QGraphicsItem::mousePressEvent(event));
}

// 鼠标移动事件
void PolygonItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseMoveEvent(event));
}

// 鼠标施放事件
void PolygonItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseReleaseEvent(event));
}

// 滚轮事件
void PolygonItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    // 检测是否按下Shift键
    if (event->modifiers() & Qt::ShiftModifier)
    {
        // 最大放大到原始图像的50倍
        if (event->delta() > 0 && this->scaleValue >= this->scaleMax)
        {
            return;
        }
        // 图像缩小到最小缩小倍数大小之后就不继续缩小
        else if (event->delta() < 0 && (this->scaleValue <= this->scaleMin))
        {
            return;
        }
        else
        {
            // 因为图元默认的缩放原点为(0,0)，所以设置图元中心点为缩放原点
            this->setTransformOriginPoint(this->path.boundingRect().center());
            // 鼠标滚轮向前滚动
            if (event->delta() > 0)
            { // 每次放大10%
                this->scaleValue *= 1.1;
            }
            else
            { // 每次缩小10%
                this->scaleValue *= 0.9;
            }
            this->setScale(this->scaleValue);
        }
    }
    // 检测是否按下Alt键
    if (event->modifiers() & Qt::AltModifier)
    {
        // 因为图元默认的旋转原点为(0,0)，所以设置图元中心点为旋转原点
        this->setTransformOriginPoint(this->path.boundingRect().center());
        // 逆时针
        if (event->delta() > 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() + 1);
        }
        // 顺时针
        else if (event->delta() < 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() - 1);
        }
    }
    return (QGraphicsItem::wheelEvent(event));
}

// 键盘按下事件
void PolygonItem::keyPressEvent(QKeyEvent *event)
{
    // W键向上位移
    if (event->key() == Qt::Key_W)
    {
        this->moveBy(0, -10);
    }
    // S键向下位移
    if (event->key() == Qt::Key_S)
    {
        this->moveBy(0, 10);
    }
    // A键向左位移
    if (event->key() == Qt::Key_A)
    {
        this->moveBy(-10, 0);
    }
    // D键向右位移
    if (event->key() == Qt::Key_D)
    {
        this->moveBy(10, 0);
    }
    // 1键设置模糊效果
    if (event->key() == Qt::Key_1)
    {
        // 模糊效果
        this->blurEffect = new QGraphicsBlurEffect();
        // 设置模糊怎样来执行
        blurEffect->setBlurHints(QGraphicsBlurEffect::QualityHint);
        // 设置模糊半径
        blurEffect->setBlurRadius(8);
        this->setGraphicsEffect(blurEffect);
    }
    // 2键设置染色效果
    if (event->key() == Qt::Key_2)
    {
        // 染色效果
        this->colorizeEffect = new QGraphicsColorizeEffect();
        // 设置染色颜色
        colorizeEffect->setColor(Qt::red);
        // 设置染色效果强弱
        colorizeEffect->setStrength(0.6);
        this->setGraphicsEffect(colorizeEffect);
    }
    // 3键设置阴影效果
    if (event->key() == Qt::Key_3)
    {
        // 阴影效果
        this->dropShadowEffect = new QGraphicsDropShadowEffect();
        // 设置阴影的颜色
        dropShadowEffect->setColor(QColor(63, 63, 63, 100));
        // 设置阴影的模糊半径
        dropShadowEffect->setBlurRadius(2);
        // 设置阴影的偏移值
        dropShadowEffect->setOffset(5);
        this->setGraphicsEffect(dropShadowEffect);
    }
    // 4键设置不透明度
    if (event->key() == Qt::Key_4)
    {
        // 透明效果
        this->opacityEffect = new QGraphicsOpacityEffect();
        // 设置不透明度
        opacityEffect->setOpacity(0.4);
        this->setGraphicsEffect(opacityEffect);
    }
    // 5键停止使用图形效果
    if (event->key() == Qt::Key_5)
    {
        // 停止使用图形效果
        this->graphicsEffect()->setEnabled(false);
    }
}

// 悬停事件，设置光标外观和提示
void PolygonItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    this->setCursor(Qt::WhatsThisCursor);
    this->setToolTip("Polygon");
}

// 右键菜单事件，为图形项添加一个右键菜单
void PolygonItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    // 添加菜单
    QMenu menu;
    QAction *moveAction = menu.addAction("移动至起始点");
    QAction *setZIndexAction = menu.addAction("设置图形 Z-Index");
    QAction *removeAction = menu.addAction("删除图形");
    moveAction->setIcon(QIcon(":/撤回.png"));
    setZIndexAction->setIcon(QIcon(":/设置图形 Z-Index.png"));
    removeAction->setIcon(QIcon(":/删除图形.png"));
    // 使用exec()函数在指定位置弹出菜单，并等待用户进行选择
    QAction *selectedAction = menu.exec(event->screenPos());
    if (selectedAction == moveAction)
    {
        this->setPos(0, 0);
    }
    if (selectedAction == setZIndexAction)
    {
        bool ok;
        double zIndex = QInputDialog::getDouble(nullptr, "设置图形 Z-Index", "请输入图形 Z-Index: ", this->zValue(), -2147483647, 2147483647, 2, &ok);
        if (ok)
        {
            this->setZValue(zIndex);
        }
    }
    if (selectedAction == removeAction)
    {
        this->~PolygonItem();
    }
}

// 形状函数，用于碰撞检测
QPainterPath PolygonItem::shape() const
{
    return (this->path);
}

PolygonItem::~PolygonItem()
{
}

CurveItem::CurveItem(const QPointF &start, const QPointF &fisrtControl, const QPointF &secondControl, const QPointF &end, int id, QGraphicsItem *parent) : GraphItem(id, parent)
{
    this->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->setAcceptHoverEvents(true);
    this->start = start;
    this->fisrtControl = fisrtControl;
    this->secondControl = secondControl;
    this->end = end;
    // 初始化路径
    this->path.moveTo(this->start);
    this->path.cubicTo(this->fisrtControl, this->secondControl, this->end);
    // 实例化三次贝塞尔曲线实体
    this->curveItem = make_shared<QGraphicsPathItem>(this->path);
}

// 重载纯虚函数，用来返回绘制图形项的矩形区域
QRectF CurveItem::boundingRect() const
{
    return (this->path.boundingRect());
}

// 重载纯虚函数，用来执行实际的绘图操作
void CurveItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    painter->setPen(this->pen);
    painter->setBrush(this->brush);
    // 若碰撞列表不为空，将其图形项边框变为青色
    if (!this->collidingItems().isEmpty())
    {
        this->pen.setColor(Qt::cyan);
    }
    else
    {
        this->pen.setColor(this->penColor);
    }
    painter->drawPath(this->path);
    update();
}

// 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
void CurveItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setFocus();
    this->setCursor(Qt::ClosedHandCursor);
    return (QGraphicsItem::mousePressEvent(event));
}

// 鼠标移动事件
void CurveItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseMoveEvent(event));
}

// 鼠标施放事件
void CurveItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseReleaseEvent(event));
}

// 滚轮事件
void CurveItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    // 检测是否按下Shift键
    if (event->modifiers() & Qt::ShiftModifier)
    {
        // 最大放大到原始图像的50倍
        if (event->delta() > 0 && this->scaleValue >= this->scaleMax)
        {
            return;
        }
        // 图像缩小到最小缩小倍数大小之后就不继续缩小
        else if (event->delta() < 0 && (this->scaleValue <= this->scaleMin))
        {
            return;
        }
        else
        {
            // 因为图元默认的缩放原点为(0,0)，所以设置图元中心点为缩放原点
            this->setTransformOriginPoint(this->path.boundingRect().center());
            // 鼠标滚轮向前滚动
            if (event->delta() > 0)
            {
                // 每次放大10%
                this->scaleValue *= 1.1;
            }
            else
            {
                // 每次缩小10%
                this->scaleValue *= 0.9;
            }
            this->setScale(this->scaleValue);
        }
    }
    // 检测是否按下Alt键
    if (event->modifiers() & Qt::AltModifier)
    {
        // 因为图元默认的旋转原点为(0,0)，所以设置图元中心点为旋转原点
        this->setTransformOriginPoint(this->path.boundingRect().center());
        // 逆时针
        if (event->delta() > 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() + 1);
        }
        // 顺时针
        else if (event->delta() < 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() - 1);
        }
    }
    return (QGraphicsItem::wheelEvent(event));
}

// 键盘按下事件
void CurveItem::keyPressEvent(QKeyEvent *event)
{
    // W键向上位移
    if (event->key() == Qt::Key_W)
    {
        this->moveBy(0, -10);
    }
    // S键向下位移
    if (event->key() == Qt::Key_S)
    {
        this->moveBy(0, 10);
    }
    // A键向左位移
    if (event->key() == Qt::Key_A)
    {
        this->moveBy(-10, 0);
    }
    // D键向右位移
    if (event->key() == Qt::Key_D)
    {
        this->moveBy(10, 0);
    }
    // 1键设置模糊效果
    if (event->key() == Qt::Key_1)
    {
        // 模糊效果
        this->blurEffect = new QGraphicsBlurEffect();
        // 设置模糊怎样来执行
        blurEffect->setBlurHints(QGraphicsBlurEffect::QualityHint);
        // 设置模糊半径
        blurEffect->setBlurRadius(8);
        this->setGraphicsEffect(blurEffect);
    }
    // 2键设置染色效果
    if (event->key() == Qt::Key_2)
    {
        // 染色效果
        this->colorizeEffect = new QGraphicsColorizeEffect();
        // 设置染色颜色
        colorizeEffect->setColor(Qt::red);
        // 设置染色效果强弱
        colorizeEffect->setStrength(0.6);
        this->setGraphicsEffect(colorizeEffect);
    }
    // 3键设置阴影效果
    if (event->key() == Qt::Key_3)
    {
        // 阴影效果
        this->dropShadowEffect = new QGraphicsDropShadowEffect();
        // 设置阴影的颜色
        dropShadowEffect->setColor(QColor(63, 63, 63, 100));
        // 设置阴影的模糊半径
        dropShadowEffect->setBlurRadius(2);
        // 设置阴影的偏移值
        dropShadowEffect->setOffset(5);
        this->setGraphicsEffect(dropShadowEffect);
    }
    // 4键设置不透明度
    if (event->key() == Qt::Key_4)
    {
        // 透明效果
        this->opacityEffect = new QGraphicsOpacityEffect();
        // 设置不透明度
        opacityEffect->setOpacity(0.4);
        this->setGraphicsEffect(opacityEffect);
    }
    // 5键停止使用图形效果
    if (event->key() == Qt::Key_5)
    {
        // 停止使用图形效果
        this->graphicsEffect()->setEnabled(false);
    }
}

// 悬停事件，设置光标外观和提示
void CurveItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    this->setCursor(Qt::WhatsThisCursor);
    this->setToolTip("Curve");
}

// 右键菜单事件，为图形项添加一个右键菜单
void CurveItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    // 添加菜单
    QMenu menu;
    QAction *moveAction = menu.addAction("移动至起始点");
    QAction *setAttributeAction = menu.addAction("设置属性");
    QAction *setZIndexAction = menu.addAction("设置图形 Z-Index");
    QAction *removeAction = menu.addAction("删除图形");
    moveAction->setIcon(QIcon(":/撤回.png"));
    setAttributeAction->setIcon(QIcon(":/属性.png"));
    setZIndexAction->setIcon(QIcon(":/设置图形 Z-Index.png"));
    removeAction->setIcon(QIcon(":/删除图形.png"));
    // 使用exec()函数在指定位置弹出菜单，并等待用户进行选择
    QAction *selectedAction = menu.exec(event->screenPos());
    if (selectedAction == moveAction)
    {
        this->setPos(0, 0);
    }
    if (selectedAction == setAttributeAction)
    {
        // 初始化属性对话框
        this->setAttributeDialog();
        // 初始化属性栏中曲线点位
        this->dialog->ui->curveStartXSpinBox->setValue(this->start.x());
        this->dialog->ui->curveStartYSpinBox->setValue(this->start.y());
        this->dialog->ui->curveControl1XSpinBox->setValue(this->fisrtControl.x());
        this->dialog->ui->curveControl1YSpinBox->setValue(this->fisrtControl.y());
        this->dialog->ui->curveControl2XSpinBox->setValue(this->secondControl.x());
        this->dialog->ui->curveControl2YSpinBox->setValue(this->secondControl.y());
        this->dialog->ui->curveEndXSpinBox->setValue(this->end.x());
        this->dialog->ui->curveEndYSpinBox->setValue(this->end.y());
        void (QSpinBox::*valueChanged)(int) = &QSpinBox::valueChanged;
        // 设置曲线点位
        QObject::connect(dialog->ui->curveStartXSpinBox, valueChanged, [=](int val)
                         {
            this->start.setX(val);
            QPainterPath().swap(this->path);
            this->path.moveTo(this->start);
            this->path.cubicTo(this->fisrtControl, this->secondControl, this->end);
            this->curveItem->setPath(this->path);
            update(); });
        QObject::connect(dialog->ui->curveStartYSpinBox, valueChanged, [=](int val)
                         {
            this->start.setY(val);
            QPainterPath().swap(this->path);
            this->path.moveTo(this->start);
            this->path.cubicTo(this->fisrtControl, this->secondControl, this->end);
            this->curveItem->setPath(this->path);
            update(); });
        QObject::connect(dialog->ui->curveControl1XSpinBox, valueChanged, [=](int val)
                         {
            this->fisrtControl.setX(val);
            QPainterPath().swap(this->path);
            this->path.moveTo(this->start);
            this->path.cubicTo(this->fisrtControl, this->secondControl, this->end);
            this->curveItem->setPath(this->path);
            update(); });
        QObject::connect(dialog->ui->curveControl1YSpinBox, valueChanged, [=](int val)
                         {
            this->fisrtControl.setY(val);
            QPainterPath().swap(this->path);
            this->path.moveTo(this->start);
            this->path.cubicTo(this->fisrtControl, this->secondControl, this->end);
            this->curveItem->setPath(this->path);
            update(); });
        QObject::connect(dialog->ui->curveControl2XSpinBox, valueChanged, [=](int val)
                         {
            this->secondControl.setX(val);
            this->path.moveTo(this->start);
            this->path.cubicTo(this->fisrtControl, this->secondControl, this->end);
            this->curveItem->setPath(this->path);
            update(); });
        QObject::connect(dialog->ui->curveControl2YSpinBox, valueChanged, [=](int val)
                         {
            this->secondControl.setY(val);
            QPainterPath().swap(this->path);
            this->path.moveTo(this->start);
            this->path.cubicTo(this->fisrtControl, this->secondControl, this->end);
            this->curveItem->setPath(this->path);
            update(); });
        QObject::connect(dialog->ui->curveEndXSpinBox, valueChanged, [=](int val)
                         {
            this->end.setX(val);
            QPainterPath().swap(this->path);
            this->path.moveTo(this->start);
            this->path.cubicTo(this->fisrtControl, this->secondControl, this->end);
            this->curveItem->setPath(this->path);
            update(); });
        QObject::connect(dialog->ui->curveEndYSpinBox, valueChanged, [=](int val)
                         {
            this->end.setY(val);
            QPainterPath().swap(this->path);
            this->path.moveTo(this->start);
            this->path.cubicTo(this->fisrtControl, this->secondControl, this->end);
            this->curveItem->setPath(this->path);
            update(); });
        this->dialog->setState(AttributeDialog::DrawCurveState);
        this->dialog->exec();
    }
    if (selectedAction == setZIndexAction)
    {
        bool ok;
        double zIndex = QInputDialog::getDouble(nullptr, "设置图形 Z-Index", "请输入图形 Z-Index: ", this->zValue(), -2147483647, 2147483647, 2, &ok);
        if (ok)
        {
            this->setZValue(zIndex);
        }
    }
    if (selectedAction == removeAction)
    {
        this->~CurveItem();
    }
}

// 形状函数，用于碰撞检测
QPainterPath CurveItem::shape() const
{
    return (this->path);
}

CurveItem::~CurveItem()
{
}

TextItem::TextItem(const QPointF &start, const QPointF &end, const QString &textContext, int id, QGraphicsItem *parent) : GraphItem(id, parent)
{
    this->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->setAcceptHoverEvents(true);
    this->textContext = textContext;
    this->font = QFont("幼圆", 9);
    this->lastPos = start;
    this->endPos = end;
    this->width = this->endPos.x() - this->lastPos.x();
    this->height = this->endPos.y() - this->lastPos.y();
    // 初始化矩形控制点、矩形实例和矩形路径
    if (this->width > 0 && this->height > 0)
    {
        this->topLeft = QPointF(this->lastPos.x(), this->lastPos.y());
        this->topRight = QPointF(this->endPos.x() + width, this->lastPos.y());
        this->bottomLeft = QPointF(this->lastPos.x(), this->endPos.y());
        this->bottomRight = QPointF(this->endPos.x(), this->endPos.y());
        this->textItem = make_shared<QGraphicsRectItem>(QRectF(this->lastPos, QSizeF(this->width, this->height)));
        this->path.addRect(this->textItem->rect());
    }
    else if (this->width < 0 && this->height > 0)
    {
        this->topLeft = QPointF(this->endPos.x(), this->lastPos.y());
        this->topRight = QPointF(this->lastPos.x(), this->lastPos.y());
        this->bottomLeft = QPointF(this->endPos.x(), this->endPos.y());
        this->bottomRight = QPointF(this->lastPos.x(), this->endPos.y());
        this->textItem = make_shared<QGraphicsRectItem>(QRectF(topLeft, QSizeF(qAbs(this->width), this->height)));
        this->path.addRect(this->textItem->rect());
    }
    else if (this->width > 0 && this->height < 0)
    {
        this->topLeft = QPointF(this->lastPos.x(), this->endPos.y());
        this->topRight = QPointF(this->endPos.x(), this->endPos.y());
        this->bottomLeft = QPointF(this->lastPos.x(), this->lastPos.y());
        this->bottomRight = QPointF(this->endPos.x(), this->lastPos.y());
        this->textItem = make_shared<QGraphicsRectItem>(QRectF(topLeft, QSizeF(this->width, qAbs(this->height))));
        this->path.addRect(this->textItem->rect());
    }
    else
    {
        this->topLeft = QPointF(this->endPos.x(), this->endPos.y());
        this->topRight = QPointF(this->lastPos.x(), this->endPos.y());
        this->bottomLeft = QPointF(this->endPos.x(), this->lastPos.y());
        this->bottomRight = QPointF(this->lastPos.x(), this->lastPos.y());
        this->textItem = make_shared<QGraphicsRectItem>(QRectF(this->endPos, QSizeF(qAbs(this->width), qAbs(this->height))));
        this->path.addRect(this->textItem->rect());
    }
}

TextItem::TextItem(const QPointF &center, const QString &textContext, int id)
{
    this->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->setAcceptHoverEvents(true);
    this->id = id;
    this->textContext = textContext;
    this->font = QFont("幼圆", 9);
    // 使用 QFontMetrics 计算文本的大小
    QFontMetrics metrics(this->font);
    QRectF boundingRect = metrics.boundingRect(this->textContext);
    this->width = boundingRect.width();
    this->height = boundingRect.height();
    // 根据中心点的位置和文本的大小设置矩形的位置
    this->lastPos = QPointF(center.x() - this->width / 2, center.y() - this->height / 2);
    this->endPos = QPointF(center.x() + this->width / 2, center.y() + this->height / 2);
    // 初始化矩形控制点、矩形实例和矩形路径
    this->topLeft = QPointF(this->lastPos.x(), this->lastPos.y());
    this->topRight = QPointF(this->endPos.x(), this->lastPos.y());
    this->bottomLeft = QPointF(this->lastPos.x(), this->endPos.y());
    this->bottomRight = QPointF(this->endPos.x(), this->endPos.y());
    this->textItem = make_shared<QGraphicsRectItem>(QRectF(this->lastPos, QSizeF(this->width, this->height)));
    this->path.addRect(this->textItem->rect());
}

// 设置文本
void TextItem::setText(const QString &textContext)
{
    this->textContext = textContext;
    this->font = QFont("幼圆", 9);
    // 使用 QFontMetrics 计算文本的大小
    QFontMetrics metrics(this->font);
    QRectF boundingRect = metrics.boundingRect(this->textContext);
    this->width = boundingRect.width();
    this->height = boundingRect.height();
    // 根据中心点的位置和文本的大小设置矩形的位置
    QPointF center = this->path.boundingRect().center();
    this->lastPos = QPointF(center.x() - this->width / 2, center.y() - this->height / 2);
    this->endPos = QPointF(center.x() + this->width / 2, center.y() + this->height / 2);
    // 初始化矩形控制点、矩形实例和矩形路径
    this->topLeft = QPointF(this->lastPos.x(), this->lastPos.y());
    this->topRight = QPointF(this->endPos.x(), this->lastPos.y());
    this->bottomLeft = QPointF(this->lastPos.x(), this->endPos.y());
    this->bottomRight = QPointF(this->endPos.x(), this->endPos.y());
    this->textItem = make_shared<QGraphicsRectItem>(QRectF(this->lastPos, QSizeF(this->width, this->height)));
    this->path.addRect(this->textItem->rect());
}

// 重设文本项大小
void TextItem::resetSize(QSizeF size)
{
    this->textItem->setRect(QRectF(this->lastPos, size));
    this->path.addRect(this->textItem->rect());
}

// 重载纯虚函数，用来返回绘制图形项的矩形区域
QRectF TextItem::boundingRect() const
{
    return (this->path.boundingRect());
}

// 重载纯虚函数，用来执行实际的绘图操作
void TextItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    painter->setPen(this->pen);
    painter->setBrush(this->brush);
    // 若碰撞列表不为空，将其图形项边框变为青色
    if (!this->collidingItems().isEmpty())
    {
        this->pen.setColor(Qt::cyan);
    }
    else
    {
        this->pen.setColor(this->penColor);
    }
    painter->setFont(this->font);
    painter->drawText(this->textItem->boundingRect(), Qt::AlignCenter, this->textContext);
    update();
}

// 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
void TextItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setFocus();
    this->setCursor(Qt::ClosedHandCursor);
    return (QGraphicsItem::mousePressEvent(event));
}

// 鼠标移动事件
void TextItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseMoveEvent(event));
}

// 鼠标施放事件
void TextItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseReleaseEvent(event));
}

// 滚轮事件
void TextItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    // 检测是否按下Shift键
    if (event->modifiers() & Qt::ShiftModifier)
    {
        // 最大放大到原始图像的50倍
        if (event->delta() > 0 && this->scaleValue >= this->scaleMax)
        {
            return;
        }
        // 图像缩小到最小缩小倍数大小之后就不继续缩小
        else if (event->delta() < 0 && (this->scaleValue <= this->scaleMin))
        {
            return;
        }
        else
        {
            // 因为图元默认的缩放原点为(0,0)，所以设置图元中心点为缩放原点
            this->setTransformOriginPoint(this->path.boundingRect().center());
            // 鼠标滚轮向前滚动
            if (event->delta() > 0)
            {
                // 每次放大10%
                this->scaleValue *= 1.1;
            }
            else
            {
                // 每次缩小10%
                this->scaleValue *= 0.9;
            }
            this->setScale(this->scaleValue);
        }
    }
    // 检测是否按下Alt键
    if (event->modifiers() & Qt::AltModifier)
    {
        // 因为图元默认的旋转原点为(0,0)，所以设置图元中心点为旋转原点
        this->setTransformOriginPoint(this->path.boundingRect().center());
        // 逆时针
        if (event->delta() > 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() + 1);
        }
        // 顺时针
        else if (event->delta() < 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() - 1);
        }
    }
    return (QGraphicsItem::wheelEvent(event));
}

// 键盘按下事件
void TextItem::keyPressEvent(QKeyEvent *event)
{
    // W键向上位移
    if (event->key() == Qt::Key_W)
    {
        this->moveBy(0, -10);
    }
    // S键向下位移
    if (event->key() == Qt::Key_S)
    {
        this->moveBy(0, 10);
    }
    // A键向左位移
    if (event->key() == Qt::Key_A)
    {
        this->moveBy(-10, 0);
    }
    // D键向右位移
    if (event->key() == Qt::Key_D)
    {
        this->moveBy(10, 0);
    }
    // 1键设置模糊效果
    if (event->key() == Qt::Key_1)
    {
        // 模糊效果
        this->blurEffect = new QGraphicsBlurEffect();
        // 设置模糊怎样来执行
        blurEffect->setBlurHints(QGraphicsBlurEffect::QualityHint);
        // 设置模糊半径
        blurEffect->setBlurRadius(8);
        this->setGraphicsEffect(blurEffect);
    }
    // 2键设置染色效果
    if (event->key() == Qt::Key_2)
    {
        // 染色效果
        this->colorizeEffect = new QGraphicsColorizeEffect();
        // 设置染色颜色
        colorizeEffect->setColor(Qt::red);
        // 设置染色效果强弱
        colorizeEffect->setStrength(0.6);
        this->setGraphicsEffect(colorizeEffect);
    }
    // 3键设置阴影效果
    if (event->key() == Qt::Key_3)
    {
        // 阴影效果
        this->dropShadowEffect = new QGraphicsDropShadowEffect();
        // 设置阴影的颜色
        dropShadowEffect->setColor(QColor(63, 63, 63, 100));
        // 设置阴影的模糊半径
        dropShadowEffect->setBlurRadius(2);
        // 设置阴影的偏移值
        dropShadowEffect->setOffset(5);
        this->setGraphicsEffect(dropShadowEffect);
    }
    // 4键设置不透明度
    if (event->key() == Qt::Key_4)
    {
        // 透明效果
        this->opacityEffect = new QGraphicsOpacityEffect();
        // 设置不透明度
        opacityEffect->setOpacity(0.4);
        this->setGraphicsEffect(opacityEffect);
    }
    // 5键停止使用图形效果
    if (event->key() == Qt::Key_5)
    {
        // 停止使用图形效果
        this->graphicsEffect()->setEnabled(false);
    }
}

// 悬停事件，设置光标外观和提示
void TextItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    this->setCursor(Qt::WhatsThisCursor);
    this->setToolTip("Text");
}

// 右键菜单事件，为图形项添加一个右键菜单
void TextItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    // 添加菜单
    QMenu menu;
    QAction *moveAction = menu.addAction("移动至起始点");
    QAction *setAttributeAction = menu.addAction("设置属性");
    QAction *setZIndexAction = menu.addAction("设置图形 Z-Index");
    QAction *removeAction = menu.addAction("删除图形");
    moveAction->setIcon(QIcon(":/撤回.png"));
    setAttributeAction->setIcon(QIcon(":/属性.png"));
    setZIndexAction->setIcon(QIcon(":/设置图形 Z-Index.png"));
    removeAction->setIcon(QIcon(":/删除图形.png"));
    // 使用exec()函数在指定位置弹出菜单，并等待用户进行选择
    QAction *selectedAction = menu.exec(event->screenPos());
    if (selectedAction == moveAction)
    {
        this->setPos(0, 0);
    }
    if (selectedAction == setAttributeAction)
    {
        // 初始化属性对话框
        this->setAttributeDialog();
        // 初始化属性栏中字体
        this->dialog->ui->fontSizeSpinBox->setValue(this->font.pointSize());
        this->dialog->ui->fontWeightSpinBox->setValue(this->font.weight());
        void (QSpinBox::*valueChanged)(int) = &QSpinBox::valueChanged;
        // 设置字体属性
        QObject::connect(dialog->ui->fontFamilyComboBox, &QFontComboBox::currentFontChanged, [=](const QFont &font)
                         {
            this->font.setFamily(font.family());
            update(); });
        QObject::connect(dialog->ui->fontSizeSpinBox, valueChanged, [=](int val)
                         {
            this->font.setPointSize(val);
            update(); });
        QObject::connect(dialog->ui->fontWeightSpinBox, valueChanged, [=](int val)
                         {
            this->font.setWeight(val);
            update(); });
        QObject::connect(dialog->ui->italicCheckBox, &QCheckBox::stateChanged, [=](int val)
                         {
            this->font.setItalic(val);
            update(); });
        QObject::connect(dialog->ui->boldCheckBox, &QCheckBox::stateChanged, [=](int val)
                         {
            this->font.setBold(val);
            update(); });
        QObject::connect(dialog->ui->strikeOutCheckBox, &QCheckBox::stateChanged, [=](int val)
                         {
            this->font.setStrikeOut(val);
            update(); });
        QObject::connect(dialog->ui->underCheckBox, &QCheckBox::stateChanged, [=](int val)
                         {
            this->font.setUnderline(val);
            update(); });
        QObject::connect(dialog->ui->capsLkCheckBox, &QCheckBox::stateChanged, [=](int val)
                         {
            if (val)
            {
                this->font.setCapitalization(QFont::Capitalize);
            }
            else
            {
                this->font.setCapitalization(QFont::MixedCase);
            }
            update(); });
        this->dialog->setState(AttributeDialog::DrawTextState);
        this->dialog->exec();
    }
    if (selectedAction == setZIndexAction)
    {
        bool ok;
        double zIndex = QInputDialog::getDouble(nullptr, "设置图形 Z-Index", "请输入图形 Z-Index: ", this->zValue(), -2147483647, 2147483647, 2, &ok);
        if (ok)
        {
            this->setZValue(zIndex);
        }
    }
    if (selectedAction == removeAction)
    {
        this->~TextItem();
    }
}

// 形状函数，用于碰撞检测
QPainterPath TextItem::shape() const
{
    return (this->textItem->shape());
}

TextItem::~TextItem()
{
}

PixmapItem::PixmapItem(const QString &fileName, int id, QGraphicsItem *parent) : GraphItem(id, parent)
{
    this->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->setAcceptHoverEvents(true);
    this->info = QFileInfo(fileName);
    this->pixmap = QPixmap(fileName);
    this->pixmapItem = make_shared<QGraphicsPixmapItem>(this->pixmap);
    this->path.addRect(this->pixmapItem->boundingRect());
}

PixmapItem::PixmapItem(const QPointF &center, const QString &fileName, int id)
{
    this->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->setAcceptHoverEvents(true);
    this->id = id;
    this->center = center;
    this->info = QFileInfo(fileName);
    this->pixmap = QPixmap(fileName);
    this->pixmapItem = make_shared<QGraphicsPixmapItem>(this->pixmap);
    this->pixmapItem->setOffset(-this->pixmapItem->boundingRect().width() / 2, -this->pixmapItem->boundingRect().height() / 2);
    this->path.addRect(this->pixmapItem->boundingRect());
}

// 重载纯虚函数，用来返回绘制图形项的矩形区域
QRectF PixmapItem::boundingRect() const
{
    return (this->path.boundingRect());
}

// 重载纯虚函数，用来执行实际的绘图操作
void PixmapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w)
{
    painter->setPen(this->pen);
    painter->setBrush(this->brush);
    this->pixmapItem->paint(painter, option, w);
}

// 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
void PixmapItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setFocus();
    this->setCursor(Qt::ClosedHandCursor);
    return (QGraphicsItem::mousePressEvent(event));
}

// 鼠标移动事件
void PixmapItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseMoveEvent(event));
}

// 鼠标施放事件
void PixmapItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseReleaseEvent(event));
}

// 滚轮事件
void PixmapItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    // 检测是否按下Shift键
    if (event->modifiers() & Qt::ShiftModifier)
    {
        // 最大放大到原始图像的50倍
        if (event->delta() > 0 && this->scaleValue >= this->scaleMax)
        {
            return;
        }
        // 图像缩小到最小缩小倍数大小之后就不继续缩小
        else if (event->delta() < 0 && (this->scaleValue <= this->scaleMin))
        {
            return;
        }
        else
        {
            // 因为图元默认的缩放原点为(0,0)，所以设置图元中心点为缩放原点
            this->setTransformOriginPoint(this->path.boundingRect().center());
            // 鼠标滚轮向前滚动
            if (event->delta() > 0)
            {
                // 每次放大10%
                this->scaleValue *= 1.1;
            }
            else
            {
                // 每次缩小10%
                this->scaleValue *= 0.9;
            }
            this->setScale(this->scaleValue);
        }
    }
    // 检测是否按下Alt键
    if (event->modifiers() & Qt::AltModifier)
    {
        // 因为图元默认的旋转原点为(0,0)，所以设置图元中心点为旋转原点
        this->setTransformOriginPoint(this->path.boundingRect().center());
        // 逆时针
        if (event->delta() > 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() + 1);
        }
        // 顺时针
        else if (event->delta() < 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() - 1);
        }
    }
    return (QGraphicsItem::wheelEvent(event));
}

// 键盘按下事件
void PixmapItem::keyPressEvent(QKeyEvent *event)
{
    // W键向上位移
    if (event->key() == Qt::Key_W)
    {
        this->moveBy(0, -10);
    }
    // S键向下位移
    if (event->key() == Qt::Key_S)
    {
        this->moveBy(0, 10);
    }
    // A键向左位移
    if (event->key() == Qt::Key_A)
    {
        this->moveBy(-10, 0);
    }
    // D键向右位移
    if (event->key() == Qt::Key_D)
    {
        this->moveBy(10, 0);
    }
    // 1键设置模糊效果
    if (event->key() == Qt::Key_1)
    {
        // 模糊效果
        this->blurEffect = new QGraphicsBlurEffect();
        // 设置模糊怎样来执行
        blurEffect->setBlurHints(QGraphicsBlurEffect::QualityHint);
        // 设置模糊半径
        blurEffect->setBlurRadius(8);
        this->setGraphicsEffect(blurEffect);
    }
    // 2键设置染色效果
    if (event->key() == Qt::Key_2)
    {
        // 染色效果
        this->colorizeEffect = new QGraphicsColorizeEffect();
        // 设置染色颜色
        colorizeEffect->setColor(Qt::red);
        // 设置染色效果强弱
        colorizeEffect->setStrength(0.6);
        this->setGraphicsEffect(colorizeEffect);
    }
    // 3键设置阴影效果
    if (event->key() == Qt::Key_3)
    {
        // 阴影效果
        this->dropShadowEffect = new QGraphicsDropShadowEffect();
        // 设置阴影的颜色
        dropShadowEffect->setColor(QColor(63, 63, 63, 100));
        // 设置阴影的模糊半径
        dropShadowEffect->setBlurRadius(2);
        // 设置阴影的偏移值
        dropShadowEffect->setOffset(5);
        this->setGraphicsEffect(dropShadowEffect);
    }
    // 4键设置不透明度
    if (event->key() == Qt::Key_4)
    {
        // 透明效果
        this->opacityEffect = new QGraphicsOpacityEffect();
        // 设置不透明度
        opacityEffect->setOpacity(0.4);
        this->setGraphicsEffect(opacityEffect);
    }
    // 5键停止使用图形效果
    if (event->key() == Qt::Key_5)
    {
        // 停止使用图形效果
        this->graphicsEffect()->setEnabled(false);
    }
}

// 悬停事件，设置光标外观和提示
void PixmapItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    this->setCursor(Qt::WhatsThisCursor);
    this->setToolTip("Pixmap");
}

// 右键菜单事件，为图形项添加一个右键菜单
void PixmapItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    // 添加菜单
    QMenu menu;
    QAction *moveAction = menu.addAction("移动至起始点");
    QAction *pixmapAttributeAction = menu.addAction("图片属性");
    QAction *setZIndexAction = menu.addAction("设置图形 Z-Index");
    QAction *removeAction = menu.addAction("删除图形");
    moveAction->setIcon(QIcon(":/撤回.png"));
    pixmapAttributeAction->setIcon(QIcon(":/属性.png"));
    setZIndexAction->setIcon(QIcon(":/设置图形 Z-Index.png"));
    removeAction->setIcon(QIcon(":/删除图形.png"));
    // 使用exec()函数在指定位置弹出菜单，并等待用户进行选择
    QAction *selectedAction = menu.exec(event->screenPos());
    if (selectedAction == moveAction)
    {
        this->setPos(0, 0);
    }
    if (selectedAction == pixmapAttributeAction)
    {
        QImage image(this->pixmap.toImage());
        QString infomation = QString("图像宽度: %1\n图像高度: %2\n图像深度值: %3\n图形格式: %4\n图形大小:%5 KB").arg(image.width()).arg(image.height()).arg(image.depth()).arg(this->info.suffix()).arg(this->info.size() / 1024.0);
        this->pixmap.fromImage(image);
        QMessageBox::information(nullptr, QString("图像信息: "), infomation);
    }
    if (selectedAction == setZIndexAction)
    {
        bool ok;
        double zIndex = QInputDialog::getDouble(nullptr, "设置图形 Z-Index", "请输入图形 Z-Index: ", this->zValue(), -2147483647, 2147483647, 2, &ok);
        if (ok)
        {
            this->setZValue(zIndex);
        }
    }
    if (selectedAction == removeAction)
    {
        this->~PixmapItem();
    }
}

// 形状函数，用于碰撞检测
QPainterPath PixmapItem::shape() const
{
    return (this->path);
}

PixmapItem::~PixmapItem()
{
}

ChessBoardItem::ChessBoardItem(int id, QGraphicsItem *parent) : GraphItem(id, parent)
{
    this->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->setAcceptHoverEvents(true);
    // 初始化棋盘项
    this->initChessBoardItem();
}

// 初始化棋盘项
void ChessBoardItem::initChessBoardItem()
{
    // 读取文件
    this->filePath = QFileDialog::getOpenFileName(nullptr, QObject::tr("Open File"), "", QObject::tr("Text Files(*.txt)"));
    if (this->filePath.isEmpty())
    {
        QMessageBox::warning(nullptr, QObject::tr("Warning"), QObject::tr("No File Selected!"), QMessageBox::Yes);
        return;
    }
    // 创建棋盘
    this->chessboard = ChessBoard(this->filePath.toStdString());
    // 初始化涂色区域访问标记
    this->chessboard.visited = vector<vector<bool>>(this->chessboard.row, vector<bool>(this->chessboard.col, false));
    // 初始化最大涂色区域
    this->chessboard.maxArea = vector<vector<bool>>(this->chessboard.row, vector<bool>(this->chessboard.col, false));
    // 初始化最大涂色区域面积
    this->chessboard.maxAreaSize = 0;
    // 初始化棋盘
    for (int i = 0; i < this->chessboard.row; i++)
    {
        for (int j = 0; j < this->chessboard.col; j++)
        {
            // 添加棋盘网格 Item
            shared_ptr<RectangleItem> cellItem = make_shared<RectangleItem>(QPointF(j * this->cellSize, i * this->cellSize), QPointF((j + 1) * this->cellSize, (i + 1) * this->cellSize));
            cellItem->setPen(Qt::black);
            cellItem->setBrush(this->chessboard.board[i][j].color);
            this->cellItems.push_back(cellItem);
            // 添加棋盘网格路径
            this->path.addRect(cellItem->boundingRect());
        }
    }
}

// 绘制最大涂色区域
void ChessBoardItem::drawMaxArea()
{
    // 使用黑色绘制最大涂色区域
    int index = 0;
    for (int i = 0; i < this->chessboard.row; i++)
    {
        for (int j = 0; j < this->chessboard.col; j++)
        {
            if (this->chessboard.maxArea[i][j])
            {
                this->cellItems[index]->brush.setColor(Qt::black);
                this->cellItems[index]->brush.setStyle(Qt::SolidPattern);
            }
            ++index;
        }
    }
    update();
}

// 重载纯虚函数，用来返回绘制图形项的矩形区域
QRectF ChessBoardItem::boundingRect() const
{
    return (this->path.boundingRect());
}

// 重载纯虚函数，用来执行实际的绘图操作
void ChessBoardItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w)
{
    for (auto &cell : this->cellItems)
    {
        cell->paint(painter, option, w);
    }
    update();
}

// 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
void ChessBoardItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setFocus();
    this->setCursor(Qt::ClosedHandCursor);
    return (QGraphicsItem::mousePressEvent(event));
}

// 鼠标移动事件
void ChessBoardItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseMoveEvent(event));
}

// 鼠标施放事件
void ChessBoardItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseReleaseEvent(event));
}

// 滚轮事件
void ChessBoardItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    // 检测是否按下Shift键
    if (event->modifiers() & Qt::ShiftModifier)
    {
        // 最大放大到原始图像的50倍
        if (event->delta() > 0 && this->scaleValue >= this->scaleMax)
        {
            return;
        }
        // 图像缩小到最小缩小倍数大小之后就不继续缩小
        else if (event->delta() < 0 && (this->scaleValue <= this->scaleMin))
        {
            return;
        }
        else
        {
            // 因为图元默认的缩放原点为(0,0)，所以设置图元中心点为缩放原点
            this->setTransformOriginPoint(this->path.boundingRect().center());
            // 鼠标滚轮向前滚动
            if (event->delta() > 0)
            {
                // 每次放大10%
                this->scaleValue *= 1.1;
            }
            else
            {
                // 每次缩小10%
                this->scaleValue *= 0.9;
            }
            this->setScale(this->scaleValue);
        }
    }
    // 检测是否按下Alt键
    if (event->modifiers() & Qt::AltModifier)
    {
        // 因为图元默认的旋转原点为(0,0)，所以设置图元中心点为旋转原点
        this->setTransformOriginPoint(this->path.boundingRect().center());
        // 逆时针
        if (event->delta() > 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() + 1);
        }
        // 顺时针
        else if (event->delta() < 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() - 1);
        }
    }
    return (QGraphicsItem::wheelEvent(event));
}

// 键盘按下事件
void ChessBoardItem::keyPressEvent(QKeyEvent *event)
{
    // W键向上位移
    if (event->key() == Qt::Key_W)
    {
        this->moveBy(0, -10);
    }
    // S键向下位移
    if (event->key() == Qt::Key_S)
    {
        this->moveBy(0, 10);
    }
    // A键向左位移
    if (event->key() == Qt::Key_A)
    {
        this->moveBy(-10, 0);
    }
    // D键向右位移
    if (event->key() == Qt::Key_D)
    {
        this->moveBy(10, 0);
    }
    // 1键设置模糊效果
    if (event->key() == Qt::Key_1)
    {
        // 模糊效果
        this->blurEffect = new QGraphicsBlurEffect();
        // 设置模糊怎样来执行
        blurEffect->setBlurHints(QGraphicsBlurEffect::QualityHint);
        // 设置模糊半径
        blurEffect->setBlurRadius(8);
        this->setGraphicsEffect(blurEffect);
    }
    // 2键设置染色效果
    if (event->key() == Qt::Key_2)
    {
        // 染色效果
        this->colorizeEffect = new QGraphicsColorizeEffect();
        // 设置染色颜色
        colorizeEffect->setColor(Qt::red);
        // 设置染色效果强弱
        colorizeEffect->setStrength(0.6);
        this->setGraphicsEffect(colorizeEffect);
    }
    // 3键设置阴影效果
    if (event->key() == Qt::Key_3)
    {
        // 阴影效果
        this->dropShadowEffect = new QGraphicsDropShadowEffect();
        // 设置阴影的颜色
        dropShadowEffect->setColor(QColor(63, 63, 63, 100));
        // 设置阴影的模糊半径
        dropShadowEffect->setBlurRadius(2);
        // 设置阴影的偏移值
        dropShadowEffect->setOffset(5);
        this->setGraphicsEffect(dropShadowEffect);
    }
    // 4键设置不透明度
    if (event->key() == Qt::Key_4)
    {
        // 透明效果
        this->opacityEffect = new QGraphicsOpacityEffect();
        // 设置不透明度
        opacityEffect->setOpacity(0.4);
        this->setGraphicsEffect(opacityEffect);
    }
    // 5键停止使用图形效果
    if (event->key() == Qt::Key_5)
    {
        // 停止使用图形效果
        this->graphicsEffect()->setEnabled(false);
    }
}

// 悬停事件，设置光标外观和提示
void ChessBoardItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    this->setCursor(Qt::WhatsThisCursor);
    this->setToolTip("ChessBoard");
}

// 右键菜单事件，为图形项添加一个右键菜单
void ChessBoardItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    // 添加菜单
    QMenu menu;
    QAction *moveAction = menu.addAction("移动至起始点");
    QAction *getMaxArea = menu.addAction("获取最大涂色区域");
    QAction *setZIndexAction = menu.addAction("设置图形 Z-Index");
    QAction *removeAction = menu.addAction("删除图形");
    moveAction->setIcon(QIcon(":/撤回.png"));
    getMaxArea->setIcon(QIcon(":/属性.png"));
    setZIndexAction->setIcon(QIcon(":/设置图形 Z-Index.png"));
    removeAction->setIcon(QIcon(":/删除图形.png"));
    // 使用exec()函数在指定位置弹出菜单，并等待用户进行选择
    QAction *selectedAction = menu.exec(event->screenPos());
    if (selectedAction == moveAction)
    {
        this->setPos(0, 0);
    }
    if (selectedAction == getMaxArea)
    {
        // 求最大涂色区域
        this->chessboard.findMaxArea();
        // 绘制最大涂色区域
        this->drawMaxArea();
        // 最大涂色区域信息
        QMessageBox::information(nullptr, QObject::tr("Max Area"), QObject::tr("Max Area: ") + QString::number(this->chessboard.maxAreaSize), QMessageBox::Yes);
    }
    if (selectedAction == setZIndexAction)
    {
        bool ok;
        double zIndex = QInputDialog::getDouble(nullptr, "设置图形 Z-Index", "请输入图形 Z-Index: ", this->zValue(), -2147483647, 2147483647, 2, &ok);
        if (ok)
        {
            this->setZValue(zIndex);
        }
    }
    if (selectedAction == removeAction)
    {
        this->~ChessBoardItem();
    }
}

// 形状函数，用于碰撞检测
QPainterPath ChessBoardItem::shape() const
{
    return (this->path);
}

ChessBoardItem::~ChessBoardItem()
{
}

ConvexHullItem::ConvexHullItem(int id, QGraphicsItem *parent) : GraphItem(id, parent)
{
    this->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->setAcceptHoverEvents(true);
    // 初始化凸包项
    this->initConvexHullItem();
}

// 初始化凸包项
void ConvexHullItem::initConvexHullItem()
{
    // 读取文件
    this->filePath = QFileDialog::getOpenFileName(nullptr, QObject::tr("Open File"), "", QObject::tr("Text Files(*.txt)"));
    if (this->filePath.isEmpty())
    {
        QMessageBox::warning(nullptr, QObject::tr("Warning"), QObject::tr("No File Selected!"), QMessageBox::Yes);
        return;
    }
    // 初始化凸包对象
    this->convexhull = ConvexHull(this->filePath.toStdString());
    // 求凸包
    this->convexhull.findConvexHull();
    // 初始化凸包点
    this->index = 0;
    for (auto &point : this->convexhull.points)
    {
        shared_ptr<PointItem> pointItem = make_shared<PointItem>(point);
        shared_ptr<TextItem> textItem = make_shared<TextItem>(point, QPointF(point.x() + 20, point.y() + 20), QString(" %1 ").arg(++this->index));
        this->convexHullPointItems.push_back(pointItem);
        this->convexHullTextItems.push_back(textItem);
    }
    // 初始化凸包线
    QVector<QPointF> v = QVector<QPointF>::fromStdVector(this->convexhull.convexhullResult);
    // 首尾相连
    v.push_back(v.first());
    this->convexHullLineItem = make_shared<PolylineItem>(v);
    // 初始化凸包路径（近似等于凸包线路径）
    this->path = this->convexHullLineItem->path;
}

// 重载纯虚函数，用来返回绘制图形项的矩形区域
QRectF ConvexHullItem::boundingRect() const
{
    // 扩大凸包路径的矩形区域，包含文本标注路径
    return (this->path.boundingRect().adjusted(0, 0, 20, 20));
}

// 重载纯虚函数，用来执行实际的绘图操作
void ConvexHullItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w)
{
    for (auto &point : this->convexHullPointItems)
    {
        point->paint(painter, option, w);
    }
    for (auto &text : this->convexHullTextItems)
    {
        text->paint(painter, option, w);
    }
    this->convexHullLineItem->paint(painter, option, w);
    update();
}

// 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
void ConvexHullItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setFocus();
    this->setCursor(Qt::ClosedHandCursor);
    return (QGraphicsItem::mousePressEvent(event));
}

// 鼠标移动事件
void ConvexHullItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseMoveEvent(event));
}

// 鼠标施放事件
void ConvexHullItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseReleaseEvent(event));
}

// 滚轮事件
void ConvexHullItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    // 检测是否按下Shift键
    if (event->modifiers() & Qt::ShiftModifier)
    {
        // 最大放大到原始图像的50倍
        if (event->delta() > 0 && this->scaleValue >= this->scaleMax)
        {
            return;
        }
        // 图像缩小到最小缩小倍数大小之后就不继续缩小
        else if (event->delta() < 0 && (this->scaleValue <= this->scaleMin))
        {
            return;
        }
        else
        {
            // 因为图元默认的缩放原点为(0,0)，所以设置图元中心点为缩放原点
            this->setTransformOriginPoint(this->path.boundingRect().center());
            // 鼠标滚轮向前滚动
            if (event->delta() > 0)
            {
                // 每次放大10%
                this->scaleValue *= 1.1;
            }
            else
            {
                // 每次缩小10%
                this->scaleValue *= 0.9;
            }
            this->setScale(this->scaleValue);
        }
    }
    // 检测是否按下Alt键
    if (event->modifiers() & Qt::AltModifier)
    {
        // 因为图元默认的旋转原点为(0,0)，所以设置图元中心点为旋转原点
        this->setTransformOriginPoint(this->path.boundingRect().center());
        // 逆时针
        if (event->delta() > 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() + 1);
        }
        // 顺时针
        else if (event->delta() < 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() - 1);
        }
    }
    return (QGraphicsItem::wheelEvent(event));
}

// 键盘按下事件
void ConvexHullItem::keyPressEvent(QKeyEvent *event)
{
    // W键向上位移
    if (event->key() == Qt::Key_W)
    {
        this->moveBy(0, -10);
    }
    // S键向下位移
    if (event->key() == Qt::Key_S)
    {
        this->moveBy(0, 10);
    }
    // A键向左位移
    if (event->key() == Qt::Key_A)
    {
        this->moveBy(-10, 0);
    }
    // D键向右位移
    if (event->key() == Qt::Key_D)
    {
        this->moveBy(10, 0);
    }
    // 1键设置模糊效果
    if (event->key() == Qt::Key_1)
    {
        // 模糊效果
        this->blurEffect = new QGraphicsBlurEffect();
        // 设置模糊怎样来执行
        blurEffect->setBlurHints(QGraphicsBlurEffect::QualityHint);
        // 设置模糊半径
        blurEffect->setBlurRadius(8);
        this->setGraphicsEffect(blurEffect);
    }
    // 2键设置染色效果
    if (event->key() == Qt::Key_2)
    {
        // 染色效果
        this->colorizeEffect = new QGraphicsColorizeEffect();
        // 设置染色颜色
        colorizeEffect->setColor(Qt::red);
        // 设置染色效果强弱
        colorizeEffect->setStrength(0.6);
        this->setGraphicsEffect(colorizeEffect);
    }
    // 3键设置阴影效果
    if (event->key() == Qt::Key_3)
    {
        // 阴影效果
        this->dropShadowEffect = new QGraphicsDropShadowEffect();
        // 设置阴影的颜色
        dropShadowEffect->setColor(QColor(63, 63, 63, 100));
        // 设置阴影的模糊半径
        dropShadowEffect->setBlurRadius(2);
        // 设置阴影的偏移值
        dropShadowEffect->setOffset(5);
        this->setGraphicsEffect(dropShadowEffect);
    }
    // 4键设置不透明度
    if (event->key() == Qt::Key_4)
    {
        // 透明效果
        this->opacityEffect = new QGraphicsOpacityEffect();
        // 设置不透明度
        opacityEffect->setOpacity(0.4);
        this->setGraphicsEffect(opacityEffect);
    }
    // 5键停止使用图形效果
    if (event->key() == Qt::Key_5)
    {
        // 停止使用图形效果
        this->graphicsEffect()->setEnabled(false);
    }
}

// 悬停事件，设置光标外观和提示
void ConvexHullItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    this->setCursor(Qt::WhatsThisCursor);
    this->setToolTip("ConvexHull");
}

// 右键菜单事件，为图形项添加一个右键菜单
void ConvexHullItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    // 添加菜单
    QMenu menu;
    QAction *moveAction = menu.addAction("移动至起始点");
    QAction *addPoint = menu.addAction("添加凸包点");
    QAction *stopAddingPoint = menu.addAction("停止添加凸包点");
    QAction *setZIndexAction = menu.addAction("设置图形 Z-Index");
    QAction *removeAction = menu.addAction("删除图形");
    moveAction->setIcon(QIcon(":/撤回.png"));
    addPoint->setIcon(QIcon(":/属性.png"));
    stopAddingPoint->setIcon(QIcon(":/停止.png"));
    setZIndexAction->setIcon(QIcon(":/设置图形 Z-Index.png"));
    removeAction->setIcon(QIcon(":/删除图形.png"));
    // 使用exec()函数在指定位置弹出菜单，并等待用户进行选择
    QAction *selectedAction = menu.exec(event->screenPos());
    if (selectedAction == moveAction)
    {
        this->setPos(0, 0);
    }
    if (selectedAction == addPoint)
    {
        this->isAddingPoint = true;
    }
    if (selectedAction == stopAddingPoint)
    {
        this->isAddingPoint = false;
    }
    if (selectedAction == setZIndexAction)
    {
        bool ok;
        double zIndex = QInputDialog::getDouble(nullptr, "设置图形 Z-Index", "请输入图形 Z-Index: ", this->zValue(), -2147483647, 2147483647, 2, &ok);
        if (ok)
        {
            this->setZValue(zIndex);
        }
    }
    if (selectedAction == removeAction)
    {
        this->~ConvexHullItem();
    }
}

// 形状函数，用于碰撞检测
QPainterPath ConvexHullItem::shape() const
{
    // 扩大凸包路径的矩形区域，包含文本标注路径
    QPainterPath newPath;
    newPath.addRect(this->path.boundingRect().adjusted(0, 0, 20, 20));
    return (newPath);
}

ConvexHullItem::~ConvexHullItem()
{
}

// 判断字符串是否转换为数值
bool DecisionTreeItem::isNumeric(const string &value)
{
    if (!regex_match(value, this->numericRegex))
    {
        return false;
    }
}

// 重塑决策树，将其转换为绘图所需的数据结构
void DecisionTreeItem::reshapeDecisionTree(shared_ptr<Node> node)
{
    // 如果节点为空，直接返回
    if (node == nullptr)
    {
        return;
    }
    // 找到叶子节点
    for (auto &pair : node->children)
    {
        // 如果节点的子节点为空，当前节点为叶子节点
        if (pair.second->children.empty())
        {
            // 当前叶子结点的父节点的所有子节点
            map<string, shared_ptr<Node>> &childs = pair.second->parent->children;
            // 存储该父节点下所有相同标签的所有子节点的值
            vector<double> v;
            // 记录后续需要抹去当前不为该节点的叶子节点的 key
            vector<string> e;
            // 遍历当前叶子结点的父节点的所有子节点
            for (auto &[childKey, childValue] : childs)
            {
                // 当前节点与该子节点的标签相同
                if (pair.second->label == childValue->label)
                {
                    // 不能转换为数值类型，直接返回
                    if (!isNumeric(childValue->value))
                    {
                        return;
                    }
                    // 将该子节点的值转换为数值类型并存储
                    v.push_back(stod(childValue->value));
                    // 记录后续需要抹去当前不为该节点的叶子节点
                    if (pair.first != childKey)
                    {
                        e.push_back(childKey);
                    }
                }
            }
            // 抹去当前不为该节点的叶子节点
            for (auto &key : e)
            {
                childs.erase(key);
            }
            // 计算当前类别划分依据的最大最小值
            auto mm = minmax_element(v.begin(), v.end());
            double minNumber = (*mm.first), maxNumber = (*mm.second);
            // 创建一个输出字符串流
            ostringstream oss;
            // 设置固定的浮点数显示格式和精度
            oss << fixed << std::setprecision(2);
            if (minNumber != maxNumber)
            {
                // 将最小值和最大值添加到流中
                oss << "[" << minNumber << "\n  " << maxNumber << "]";
            }
            else
            {
                // 将最小值添加到流中
                oss << minNumber;
            }
            // 更新叶子节点的值
            pair.second->value = oss.str();
        }
    }
    // 递归处理子节点
    for (auto &pair : node->children)
    {
        reshapeDecisionTree(pair.second);
    }
}

DecisionTreeItem::DecisionTreeItem(shared_ptr<Node> node, int id, QGraphicsItem *parent) : GraphItem(id, parent)
{
    this->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->setAcceptHoverEvents(true);
    // 重塑决策树，将其转换为绘图所需的数据结构
    this->reshapeDecisionTree(node);
    // 初始化决策树 Item
    this->initDecisionTreeItem(node, 0, 0, -1, -1);
}

// 计算树的宽度
int DecisionTreeItem::calculateTreeWidth(shared_ptr<Node> node)
{
    if (node == nullptr)
    {
        return 0;
    }
    int width = 0;
    for (auto &pair : node->children)
    {
        width += calculateTreeWidth(pair.second);
    }
    return max(1, width);
}

// 初始化决策树 Item
void DecisionTreeItem::initDecisionTreeItem(shared_ptr<Node> node, int x, int y, int parentX, int parentY, QString edgeLabel)
{
    // 创建一个圆形项来表示节点
    shared_ptr<QGraphicsEllipseItem> nodeItem = make_shared<QGraphicsEllipseItem>(x - 50, y - 50, 100, 100);
    nodeItem->setBrush(QBrush(Qt::white));
    nodeItem->setPen(QPen(Qt::black));
    this->nodeItems.push_back(nodeItem);
    // 创建一个文本项来表示节点的标签
    QString nodeText = QString::fromStdString(node->field) + " = ?";
    shared_ptr<TextItem> labelItem = make_shared<TextItem>(QPointF(x, y), nodeText);
    labelItem->setBrush(QBrush(Qt::black));
    this->labelItems.push_back(labelItem);
    // 如果节点没有子节点，那么修改节点的标签来添加预测结果
    if (node->children.empty())
    {
        labelItem->setText(QString::fromStdString(node->label));
    }
    // 如果这不是根节点，那么创建一个线项来连接父节点和当前节点，并添加一个文本项来表示边的标签
    if (parentX != -1 && parentY != -1)
    {
        // 线项连接父节点和当前节点
        QLineF line(parentX, parentY, x, y);
        shared_ptr<LineItem> lineItem = make_shared<LineItem>(line.p1(), line.p2());
        lineItem->setPen(QPen(Qt::black));
        this->lineItems.push_back(lineItem);
        // 文本项表示边的标签
        shared_ptr<TextItem> edgeLabelItem = make_shared<TextItem>(QPointF((parentX + x) / 2, (parentY + y) / 2), edgeLabel);
        edgeLabelItem->resetSize(QSizeF(edgeLabelItem->boundingRect().width(), edgeLabelItem->boundingRect().height() * 2));
        edgeLabelItem->setBrush(QBrush(Qt::black));
        this->edgeLabelItems.push_back(edgeLabelItem);
    }
    // 递归初始化子节点
    int childCount = node->children.size();
    int totalWidth = calculateTreeWidth(node);
    int currentX = x - totalWidth * 100 / 2;
    for (auto &pair : node->children)
    {
        // 计算子节点的位置
        int childWidth = calculateTreeWidth(pair.second);
        int childX = currentX + childWidth * 100 / 2;
        int childY = y + 200;
        // 递归初始化绘制子节点，将上一个划分依据作为边的标签
        initDecisionTreeItem(pair.second, childX, childY, x, y, QString::fromStdString(pair.second->value));
        currentX += childWidth * 100;
    }
    // 设置路径
    this->path.addEllipse(nodeItem->rect());
}

// 重载纯虚函数，用来返回绘制图形项的矩形区域
QRectF DecisionTreeItem::boundingRect() const
{
    return (this->path.boundingRect());
}

// 重载纯虚函数，用来执行实际的绘图操作
void DecisionTreeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w)
{
    for (auto &nodeItem : this->nodeItems)
    {
        nodeItem->paint(painter, option, w);
    }
    for (auto &labelItem : this->labelItems)
    {
        labelItem->paint(painter, option, w);
    }
    for (auto &lineItem : this->lineItems)
    {
        lineItem->paint(painter, option, w);
    }
    for (auto &edgeLabelItem : this->edgeLabelItems)
    {
        edgeLabelItem->paint(painter, option, w);
    }
    update();
}

// 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
void DecisionTreeItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setFocus();
    this->setCursor(Qt::ClosedHandCursor);
    return (QGraphicsItem::mousePressEvent(event));
}

// 鼠标移动事件
void DecisionTreeItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseMoveEvent(event));
}

// 鼠标施放事件
void DecisionTreeItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseReleaseEvent(event));
}

// 滚轮事件
void DecisionTreeItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    // 检测是否按下Shift键
    if (event->modifiers() & Qt::ShiftModifier)
    {
        // 最大放大到原始图像的50倍
        if (event->delta() > 0 && this->scaleValue >= this->scaleMax)
        {
            return;
        }
        // 图像缩小到最小缩小倍数大小之后就不继续缩小
        else if (event->delta() < 0 && (this->scaleValue <= this->scaleMin))
        {
            return;
        }
        else
        {
            // 因为图元默认的缩放原点为(0,0)，所以设置图元中心点为缩放原点
            this->setTransformOriginPoint(this->path.boundingRect().center());
            // 鼠标滚轮向前滚动
            if (event->delta() > 0)
            {
                // 每次放大10%
                this->scaleValue *= 1.1;
            }
            else
            {
                // 每次缩小10%
                this->scaleValue *= 0.9;
            }
            this->setScale(this->scaleValue);
        }
    }
    // 检测是否按下Alt键
    if (event->modifiers() & Qt::AltModifier)
    {
        // 因为图元默认的旋转原点为(0,0)，所以设置图元中心点为旋转原点
        this->setTransformOriginPoint(this->path.boundingRect().center());
        // 逆时针
        if (event->delta() > 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() + 1);
        }
        // 顺时针
        else if (event->delta() < 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() - 1);
        }
    }
    return (QGraphicsItem::wheelEvent(event));
}

// 键盘按下事件
void DecisionTreeItem::keyPressEvent(QKeyEvent *event)
{
    // W键向上位移
    if (event->key() == Qt::Key_W)
    {
        this->moveBy(0, -10);
    }
    // S键向下位移
    if (event->key() == Qt::Key_S)
    {
        this->moveBy(0, 10);
    }
    // A键向左位移
    if (event->key() == Qt::Key_A)
    {
        this->moveBy(-10, 0);
    }
    // D键向右位移
    if (event->key() == Qt::Key_D)
    {
        this->moveBy(10, 0);
    }
    // 1键设置模糊效果
    if (event->key() == Qt::Key_1)
    {
        // 模糊效果
        this->blurEffect = new QGraphicsBlurEffect();
        // 设置模糊怎样来执行
        blurEffect->setBlurHints(QGraphicsBlurEffect::QualityHint);
        // 设置模糊半径
        blurEffect->setBlurRadius(8);
        this->setGraphicsEffect(blurEffect);
    }
    // 2键设置染色效果
    if (event->key() == Qt::Key_2)
    {
        // 染色效果
        this->colorizeEffect = new QGraphicsColorizeEffect();
        // 设置染色颜色
        colorizeEffect->setColor(Qt::red);
        // 设置染色效果强弱
        colorizeEffect->setStrength(0.6);
        this->setGraphicsEffect(colorizeEffect);
    }
    // 3键设置阴影效果
    if (event->key() == Qt::Key_3)
    {
        // 阴影效果
        this->dropShadowEffect = new QGraphicsDropShadowEffect();
        // 设置阴影的颜色
        dropShadowEffect->setColor(QColor(63, 63, 63, 100));
        // 设置阴影的模糊半径
        dropShadowEffect->setBlurRadius(2);
        // 设置阴影的偏移值
        dropShadowEffect->setOffset(5);
        this->setGraphicsEffect(dropShadowEffect);
    }
    // 4键设置不透明度
    if (event->key() == Qt::Key_4)
    {
        // 透明效果
        this->opacityEffect = new QGraphicsOpacityEffect();
        // 设置不透明度
        opacityEffect->setOpacity(0.4);
        this->setGraphicsEffect(opacityEffect);
    }
    // 5键停止使用图形效果
    if (event->key() == Qt::Key_5)
    {
        // 停止使用图形效果
        this->graphicsEffect()->setEnabled(false);
    }
}

// 悬停事件，设置光标外观和提示
void DecisionTreeItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    this->setCursor(Qt::WhatsThisCursor);
    this->setToolTip("DecisionTree");
}

// 右键菜单事件，为图形项添加一个右键菜单
void DecisionTreeItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    // 添加菜单
    QMenu menu;
    QAction *moveAction = menu.addAction("移动至起始点");
    QAction *setZIndexAction = menu.addAction("设置图形 Z-Index");
    QAction *removeAction = menu.addAction("删除图形");
    moveAction->setIcon(QIcon(":/撤回.png"));
    setZIndexAction->setIcon(QIcon(":/设置图形 Z-Index.png"));
    removeAction->setIcon(QIcon(":/删除图形.png"));
    // 使用exec()函数在指定位置弹出菜单，并等待用户进行选择
    QAction *selectedAction = menu.exec(event->screenPos());
    if (selectedAction == moveAction)
    {
        this->setPos(0, 0);
    }
    if (selectedAction == setZIndexAction)
    {
        bool ok;
        double zIndex = QInputDialog::getDouble(nullptr, "设置图形 Z-Index", "请输入图形 Z-Index: ", this->zValue(), -2147483647, 2147483647, 2, &ok);
        if (ok)
        {
            this->setZValue(zIndex);
        }
    }
    if (selectedAction == removeAction)
    {
        this->~DecisionTreeItem();
    }
}

// 形状函数，用于碰撞检测
QPainterPath DecisionTreeItem::shape() const
{
    return (this->path);
}

DecisionTreeItem::~DecisionTreeItem()
{
}

ShortestPathPointToPointItem::ShortestPathPointToPointItem(const vector<Place> &places, const vector<Path> &paths, const function<QPointF(const QPointF &point)> &convertCoordinate, int id, QGraphicsItem *parent) : GraphItem(id, parent)
{
    this->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->setAcceptHoverEvents(true);
    //  初始化最短路径（点到点） Item
    this->initShortestPathPointToPointItem(places, paths, convertCoordinate);
}

ShortestPathPointToPointItem::~ShortestPathPointToPointItem()
{
}

// 初始化最短路径（点到点） Item
void ShortestPathPointToPointItem::initShortestPathPointToPointItem(const vector<Place> &places, const vector<Path> &paths, const function<QPointF(const QPointF &point)> &convertCoordinate)
{
    // 遍历每个地点
    for (int i = 0; i < places.size(); i++)
    {
        shared_ptr<TextItem> textItem = make_shared<TextItem>(QPointF(convertCoordinate(places[i].point).x() - 20, convertCoordinate(places[i].point).y() - 20), QString::fromStdWString(places[i].name));
        this->placeInfo.push_back(textItem);
    }
    // 遍历每条路线
    for (int i = 0; i < paths.size() - 1; i++)
    {
        // 创建路线
        QGraphicsLineItem *lineItem = new QGraphicsLineItem(QLineF(convertCoordinate(paths[i].from.point), convertCoordinate(paths[i].to.point)));
        lineItem->setPen(QPen(Qt::black));
        // 将线添加到映射中
        this->lineMap[make_pair(paths[i].from.id, paths[i].to.id)] = lineItem;
        // 添加线上的文本标注
        QPointF center = (convertCoordinate(paths[i].from.point) + convertCoordinate(paths[i].to.point)) / 2;
        this->labelMap[make_pair(paths[i].from.id, paths[i].to.id)] = new TextItem(center, QString("%1").arg(paths[i].length));
        this->labelMap[make_pair(paths[i].from.id, paths[i].to.id)]->setRotation(-lineItem->line().angle());
        if (i == 0)
        {
            // 移动到第一条路径的起点
            this->path.moveTo(convertCoordinate(paths[i].from.point));
        }
        // 添加一条线到当前路径的终点
        this->path.lineTo(convertCoordinate(paths[i].to.point));
    }
}

// 重载纯虚函数，用来返回绘制图形项的矩形区域
QRectF ShortestPathPointToPointItem::boundingRect() const
{
    return (this->path.boundingRect());
}

// 重载纯虚函数，用来执行实际的绘图操作
void ShortestPathPointToPointItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w)
{
    for (auto &textItem : this->placeInfo)
    {
        textItem->paint(painter, option, w);
    }
    for (auto &lineItemPair : this->lineMap)
    {
        QGraphicsLineItem *lineItem = lineItemPair.second;
        lineItem->setPen(QPen(QColor(Qt::blue)));
        lineItem->paint(painter, option, w);
    }
    for (auto &labelItemPair : this->labelMap)
    {
        TextItem *labelItem = labelItemPair.second;
        labelItem->paint(painter, option, w);
    }
    // 检查是否初始化最短路径
    if (this->shortestPathItems.size() != 0)
    {
        for (auto &shortestPathItem : this->shortestPathItems)
        {
            QPen pen = QPen(QColor(Qt::red));
            pen.setWidth(10);
            shortestPathItem->setPen(pen);
            shortestPathItem->paint(painter, option, w);
        }
    }
    update();
}

// 鼠标按下事件，设置被单击的图形项获得焦点，并改变光标外观
void ShortestPathPointToPointItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setFocus();
    this->setCursor(Qt::ClosedHandCursor);
    return (QGraphicsItem::mousePressEvent(event));
}

// 鼠标移动事件
void ShortestPathPointToPointItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseMoveEvent(event));
}

// 鼠标施放事件
void ShortestPathPointToPointItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    return (QGraphicsItem::mouseReleaseEvent(event));
}

// 滚轮事件
void ShortestPathPointToPointItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    // 检测是否按下Shift键
    if (event->modifiers() & Qt::ShiftModifier)
    {
        // 最大放大到原始图像的50倍
        if (event->delta() > 0 && this->scaleValue >= this->scaleMax)
        {
            return;
        }
        // 图像缩小到最小缩小倍数大小之后就不继续缩小
        else if (event->delta() < 0 && (this->scaleValue <= this->scaleMin))
        {
            return;
        }
        else
        {
            // 因为图元默认的缩放原点为(0,0)，所以设置图元中心点为缩放原点
            this->setTransformOriginPoint(this->path.boundingRect().center());
            // 鼠标滚轮向前滚动
            if (event->delta() > 0)
            {
                // 每次放大10%
                this->scaleValue *= 1.1;
            }
            else
            {
                // 每次缩小10%
                this->scaleValue *= 0.9;
            }
            this->setScale(this->scaleValue);
        }
    }
    // 检测是否按下Alt键
    if (event->modifiers() & Qt::AltModifier)
    {
        // 因为图元默认的旋转原点为(0,0)，所以设置图元中心点为旋转原点
        this->setTransformOriginPoint(this->path.boundingRect().center());
        // 逆时针
        if (event->delta() > 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() + 1);
        }
        // 顺时针
        else if (event->delta() < 0)
        {
            // 鼠标滑轮每滑动一次，直线旋转1°
            this->setRotation(this->rotation() - 1);
        }
    }
    return (QGraphicsItem::wheelEvent(event));
}

// 键盘按下事件
void ShortestPathPointToPointItem::keyPressEvent(QKeyEvent *event)
{
    // W键向上位移
    if (event->key() == Qt::Key_W)
    {
        this->moveBy(0, -10);
    }
    // S键向下位移
    if (event->key() == Qt::Key_S)
    {
        this->moveBy(0, 10);
    }
    // A键向左位移
    if (event->key() == Qt::Key_A)
    {
        this->moveBy(-10, 0);
    }
    // D键向右位移
    if (event->key() == Qt::Key_D)
    {
        this->moveBy(10, 0);
    }
    // 1键设置模糊效果
    if (event->key() == Qt::Key_1)
    {
        // 模糊效果
        this->blurEffect = new QGraphicsBlurEffect();
        // 设置模糊怎样来执行
        blurEffect->setBlurHints(QGraphicsBlurEffect::QualityHint);
        // 设置模糊半径
        blurEffect->setBlurRadius(8);
        this->setGraphicsEffect(blurEffect);
    }
    // 2键设置染色效果
    if (event->key() == Qt::Key_2)
    {
        // 染色效果
        this->colorizeEffect = new QGraphicsColorizeEffect();
        // 设置染色颜色
        colorizeEffect->setColor(Qt::red);
        // 设置染色效果强弱
        colorizeEffect->setStrength(0.6);
        this->setGraphicsEffect(colorizeEffect);
    }
    // 3键设置阴影效果
    if (event->key() == Qt::Key_3)
    {
        // 阴影效果
        this->dropShadowEffect = new QGraphicsDropShadowEffect();
        // 设置阴影的颜色
        dropShadowEffect->setColor(QColor(63, 63, 63, 100));
        // 设置阴影的模糊半径
        dropShadowEffect->setBlurRadius(2);
        // 设置阴影的偏移值
        dropShadowEffect->setOffset(5);
        this->setGraphicsEffect(dropShadowEffect);
    }
    // 4键设置不透明度
    if (event->key() == Qt::Key_4)
    {
        // 透明效果
        this->opacityEffect = new QGraphicsOpacityEffect();
        // 设置不透明度
        opacityEffect->setOpacity(0.4);
        this->setGraphicsEffect(opacityEffect);
    }
    // 5键停止使用图形效果
    if (event->key() == Qt::Key_5)
    {
        // 停止使用图形效果
        this->graphicsEffect()->setEnabled(false);
    }
}

// 悬停事件，设置光标外观和提示
void ShortestPathPointToPointItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    this->setCursor(Qt::WhatsThisCursor);
    this->setToolTip("ShortestPathPointToPoint");
}

// 右键菜单事件，为图形项添加一个右键菜单
void ShortestPathPointToPointItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    // 添加菜单
    QMenu menu;
    QAction *moveAction = menu.addAction("移动至起始点");
    QAction *setZIndexAction = menu.addAction("设置图形 Z-Index");
    QAction *removeAction = menu.addAction("删除图形");
    moveAction->setIcon(QIcon(":/撤回.png"));
    setZIndexAction->setIcon(QIcon(":/设置图形 Z-Index.png"));
    removeAction->setIcon(QIcon(":/删除图形.png"));
    // 使用exec()函数在指定位置弹出菜单，并等待用户进行选择
    QAction *selectedAction = menu.exec(event->screenPos());
    if (selectedAction == moveAction)
    {
        this->setPos(0, 0);
    }
    if (selectedAction == setZIndexAction)
    {
        bool ok;
        double zIndex = QInputDialog::getDouble(nullptr, "设置图形 Z-Index", "请输入图形 Z-Index: ", this->zValue(), -2147483647, 2147483647, 2, &ok);
        if (ok)
        {
            this->setZValue(zIndex);
        }
    }
    if (selectedAction == removeAction)
    {
        this->~ShortestPathPointToPointItem();
    }
}

// 形状函数，用于碰撞检测
QPainterPath ShortestPathPointToPointItem::shape() const
{
    return (this->path);
}