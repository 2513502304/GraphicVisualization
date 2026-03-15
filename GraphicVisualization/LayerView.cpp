#include "LayerView.h"

LayerView::LayerView(QWidget *parent) : QGraphicsView(parent)
{
    // 始终显示滚动条
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    // 使用抗锯齿渲染
    this->setRenderHint(QPainter::Antialiasing);
    // 设置缓冲背景，加速渲染
    this->setCacheMode(QGraphicsView::CacheBackground);
}

// 设置当前场景
void LayerView::setCurrentScene()
{
    this->currentScene = this->scenes[this->scenes.size() - 1];
}

// 鼠标按下事件
void LayerView::mousePressEvent(QMouseEvent *event)
{
    // 发送鼠标左键按下信号
    if (event->button() == Qt::LeftButton)
    {
        emit this->leftButtonPressed(event);
    }
    // 点击鼠标左键，在点击处添加控制点，画点
    if (event->button() == Qt::LeftButton && this->state == DrawPointState)
    {
        QPointF clickPos = this->mapToScene(event->pos());
        PointItem *item = new PointItem(clickPos);
        this->currentScene->addItem(item);
    }
    // 点击鼠标左键，在点击处添加控制点，画线的起始点
    if (event->button() == Qt::LeftButton && this->state == DrawLineState)
    {
        this->lastPos = this->mapToScene(event->pos());
    }
    // 点击鼠标左键，在点击处添加控制点，开始画折线
    if (event->button() == Qt::LeftButton && this->state == DrawPolylineState)
    {
        QPointF clickPos = this->mapToScene(event->pos());
        this->points.append(clickPos);
    }
    // 点击鼠标右键，在点击处添加控制点，结束画折线
    if (event->button() == Qt::RightButton && this->state == DrawPolylineState)
    {
        PolylineItem *item = new PolylineItem(this->points);
        this->currentScene->addItem(item);
        // 清空容器
        QVector<QPointF>().swap(this->points);
    }
    // 点击鼠标左键，在点击处添加控制点，画矩形的起始点
    if (event->button() == Qt::LeftButton && this->state == DrawRectangleState)
    {
        this->setMouseTracking(true);
        this->lastPos = this->mapToScene(event->pos());
    }
    // 点击鼠标左键，在点击处添加控制点，画圆的起始点
    if (event->button() == Qt::LeftButton && this->state == DrawCircleState)
    {
        this->setMouseTracking(true);
        this->lastPos = this->mapToScene(event->pos());
    }
    // 点击鼠标左键，在点击处添加控制点，画扇形
    if (event->button() == Qt::LeftButton && this->state == DrawSectorState)
    {
        if (this->clickNum != 3)
        {
            this->points.append(this->mapToScene(event->pos()));
            this->clickNum++;
        }
        if (this->clickNum == 3)
        {
            this->clickNum = 0;
            SectorItem *item = new SectorItem(this->points[0], this->points[1], this->points[2]);
            this->currentScene->addItem(item);
            // 清空容器
            QVector<QPointF>().swap(this->points);
        }
    }
    // 点击鼠标左键，在点击处添加控制点，开始画多边形
    if (event->button() == Qt::LeftButton && this->state == DrawPolygonState)
    {
        QPointF clickPos = this->mapToScene(event->pos());
        this->points.append(clickPos);
    }
    // 点击鼠标右键，在点击处添加控制点，结束画多边形
    if (event->button() == Qt::RightButton && this->state == DrawPolygonState)
    {
        if (!this->points.isEmpty())
        {
            this->points.append(this->points[0]);
            PolygonItem *item = new PolygonItem(this->points);
            this->currentScene->addItem(item);
            // 清空容器
            QVector<QPointF>().swap(this->points);
        }
    }
    // 点击鼠标左键，在点击处添加控制点，画三次贝塞尔曲线
    if (event->button() == Qt::LeftButton && this->state == DrawCurveState)
    {
        if (this->clickNum != 4)
        {
            this->points.append(this->mapToScene(event->pos()));
            this->clickNum++;
        }
        if (this->clickNum == 4)
        {
            this->clickNum = 0;
            CurveItem *item = new CurveItem(this->points[0], this->points[1], this->points[2], this->points[3]);
            this->currentScene->addItem(item);
            // 清空容器
            QVector<QPointF>().swap(this->points);
        }
    }
    // 点击鼠标左键，在点击处添加控制点，画文本的起始点
    if (event->button() == Qt::LeftButton && this->state == DrawTextState)
    {
        this->setMouseTracking(true);
        this->lastPos = this->mapToScene(event->pos());
    }
    // 点击鼠标左键，在点击处添加控制点，画图片
    if (event->button() == Qt::LeftButton && this->state == DrawPixmapState)
    {
        QString pixmapFileName = QFileDialog::getOpenFileName(this, tr("选择图片"), "", tr("Images (*.png *.jpg *.bmp)"));
        if (pixmapFileName.isEmpty())
        {
            return;
        }
        PixmapItem *item = new PixmapItem(this->mapToScene(event->pos()), pixmapFileName);
        // 保留图形横纵比
        this->fitInView(this->currentScene->sceneRect(), Qt::KeepAspectRatio);
        this->currentScene->addItem(item);
    }
    QGraphicsView::mousePressEvent(event);
}

// 鼠标移动事件
void LayerView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
}

// 鼠标释放事件
void LayerView::mouseReleaseEvent(QMouseEvent *event)
{
    // 松开鼠标左键，在点击处添加控制点，画线的结束点
    if (event->button() == Qt::LeftButton && this->state == DrawLineState)
    {
        this->endPos = this->mapToScene(event->pos());
        LineItem *item = new LineItem(this->lastPos, this->endPos);
        this->currentScene->addItem(item);
    }
    // 松开鼠标左键，在点击处添加控制点，画矩形的结束点
    if (event->button() == Qt::LeftButton && this->state == this->DrawRectangleState)
    {
        this->setMouseTracking(false);
        this->endPos = this->mapToScene(event->pos());
        RectangleItem *item = new RectangleItem(this->lastPos, this->endPos);
        this->currentScene->addItem(item);
    }
    // 松开鼠标左键，在点击处添加控制点，画圆的结束点
    if (event->button() == Qt::LeftButton && this->state == DrawCircleState)
    {
        this->setMouseTracking(false);
        this->endPos = this->mapToScene(event->pos());
        CircleItem *item = new CircleItem(this->lastPos, this->endPos);
        this->currentScene->addItem(item);
    }
    // 松开鼠标左键，在点击处添加控制点，画文本的结束点
    if (event->button() == Qt::LeftButton && this->state == DrawTextState)
    {
        this->setMouseTracking(false);
        this->endPos = this->mapToScene(event->pos());
        // 检测是否按下默认键
        bool ok;
        QString textContext = QInputDialog::getMultiLineText(this, tr("输入字符串对话框"), tr("请输入要显示的文字"), tr("请输入:"), &ok);
        if (ok)
        {
            TextItem *item = new TextItem(this->lastPos, this->endPos, textContext);
            this->currentScene->addItem(item);
        }
        else
        {
            return;
        }
    }
    QGraphicsView::mouseReleaseEvent(event);
}

// 鼠标滚轮事件
void LayerView::wheelEvent(QWheelEvent *event)
{
    // 缩放、旋转、移动因子
    double scaleFactor = 1.2, rotateFactor = 10, translateFactor = 10;
    // 检测是否按下 Ctrl 键
    if (event->modifiers() & Qt::ControlModifier)
    {
        // 滚轮向前推动
        if (event->angleDelta().y() > 0)
        {
            // 靠近视图
            this->scale(scaleFactor, scaleFactor);
        }
        // 滚轮向后推动
        else if (event->angleDelta().y() < 0)
        {
            // 远离视图
            this->scale(1 / scaleFactor, 1 / scaleFactor);
        }
    }
    // 检测是否按下 Shift 键
    else if (event->modifiers() & Qt::ShiftModifier)
    {
        // 滚轮向前推动
        if (event->angleDelta().y() > 0)
        {
			// 水平滑动条向左移动
            this->horizontalScrollBar()->setValue(this->horizontalScrollBar()->value() - translateFactor);
		}
		// 滚轮向后推动
        else if (event->angleDelta().y() < 0)
        {
			// 水平滑动条向右移动
            this->horizontalScrollBar()->setValue(this->horizontalScrollBar()->value() + translateFactor);
		}
    }
    // 检测是否按下 Alt 键
    else if (event->modifiers() & Qt::AltModifier)
    {
        // 滚轮向前推动
        if (event->angleDelta().y() > 0)
        {
            // 视图逆时针旋转
            this->rotate(-rotateFactor);
        }
        // 滚轮向后推动
        else if (event->angleDelta().y() < 0)
        {
            // 视图顺时针旋转
            this->rotate(-translateFactor);
        }
    }
    // 鼠标推动
    else
    {
        // 滚轮向前推动
        if (event->angleDelta().y() > 0)
        {
            // 竖直滑动条向上移动
            this->verticalScrollBar()->setValue(this->verticalScrollBar()->value() - translateFactor);
        }
        // 滚轮向后推动
        if (event->angleDelta().y() < 0)
        {
            // 竖直滑动条向下移动
            this->verticalScrollBar()->setValue(this->verticalScrollBar()->value() + translateFactor);
        }
    }
    // QGraphicsView::wheelEvent(event);
}

// 键盘事件
void LayerView::keyPressEvent(QKeyEvent *event)
{
    // 缩放、旋转、移动因子
    double scaleFactor = 1.2, rotateFactor = 10, translateFactor = 10;
    // + 靠近视图
    if (event->key() == Qt::Key_Plus)
    {
        this->scale(scaleFactor, scaleFactor);
    }
    // - 远离视图
    if (event->key() == Qt::Key_Minus)
    {
        this->scale(1 / scaleFactor, 1 / scaleFactor);
    }
    // Q 逆时针旋转视图
    if (event->key() == Qt::Key_Q)
    {
        this->rotate(-rotateFactor);
    }
    // E 顺时针旋转视图
    if (event->key() == Qt::Key_E)
    {
        this->rotate(rotateFactor);
    }
    // W 上移视图
    if (event->key() == Qt::Key_W)
    {
		this->verticalScrollBar()->setValue(this->verticalScrollBar()->value() - translateFactor);
	}
    // S 下移视图
    if (event->key() == Qt::Key_S)
    {
        this->verticalScrollBar()->setValue(this->verticalScrollBar()->value() + translateFactor);
    }
    // A 左移视图
    if (event->key() == Qt::Key_A)
    {
		this->horizontalScrollBar()->setValue(this->horizontalScrollBar()->value() - translateFactor);
	}
    // D 右移视图
    if (event->key() == Qt::Key_D)
    {
		this->horizontalScrollBar()->setValue(this->horizontalScrollBar()->value() + translateFactor);
	}
    // QGraphicsView::keyPressEvent(event);
}
