#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 设置菜单栏字体与背景颜色
    ui->menuBar->setStyleSheet("font: 9pt 幼圆;" +
                               QString("background-color: rgb(%1, %2, %3);").arg(MainWindow::window()->palette().color(QPalette::Window).red()).arg(MainWindow::window()->palette().color(QPalette::Window).green()).arg(MainWindow::window()->palette().color(QPalette::Window).blue()));
    // 设置主窗体字体
    this->setStyleSheet(MainWindowStyleSheet);
    // 设置当前视图可获得焦点
    ui->graphicsView->setFocus();
    // 设置边界矩形
    ui->graphicsView->setSceneRect(0 - this->width() / 2.0, 0 - this->height() / 2.0, this->width(), this->height());
    // 状态栏显示当前时间
    QTimer *showTime = new QTimer(this);
    QLabel *timeLabel = new QLabel(this);
    timeLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    showTime->start(1000);
    ui->statusBar->addPermanentWidget(timeLabel);
    // 设置中心窗口
    this->setCentralWidget(ui->graphicsView);
    // 初始化图层管理器
    this->initLayerManagement();
    // 初始化工具箱
    this->initToolManagement();
    // 拖动场景 Action
    connect(ui->actionScollHand, &QAction::triggered, [=]()
            {
        if (ui->actionScollHand->isChecked())
        {
            ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
            ui->graphicsView->state = ui->graphicsView->NoDrawState;
        }
        else if (!ui->actionScollHand->isChecked())
        {
            ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
            ui->graphicsView->state = ui->graphicsView->NoDrawState;
        }
        if (ui->actionrubberBand->isChecked())
        {
            ui->actionrubberBand->setChecked(false);
        } });
    // 选择图形项 Action
    connect(ui->actionrubberBand, &QAction::triggered, [=]()
            {
        if (ui->actionrubberBand->isChecked())
        {
            ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
            ui->graphicsView->state = ui->graphicsView->NoDrawState;
        }
        else if (!ui->actionrubberBand->isChecked())
        {
            ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
            ui->graphicsView->state = ui->graphicsView->NoDrawState;
        }
        if (ui->actionScollHand->isChecked())
        {
            ui->actionScollHand->setChecked(false);
        } });
    // 全局浏览 Action
    connect(ui->actionGlobal, &QAction::triggered, [=]()
            {
        // 还原屏幕比例
        ui->graphicsView->setTransform(QTransform()); });
    // 放大 Action
    connect(ui->actionZoomIn, &QAction::triggered, [=]()
            { ui->graphicsView->scale(1.2, 1.2); });
    // 缩小浏览 Action
    connect(ui->actionZoomOut, &QAction::triggered, [=]()
            { ui->graphicsView->scale(1 / 1.2, 1 / 1.2); });
    // 数据分析 Action
    connect(ui->actionDataAnalysis, &QAction::triggered, [=]()
            {
        ui->actionScollHand->setChecked(false);
        ui->actionrubberBand->setChecked(false);
        ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
        ui->graphicsView->state = ui->graphicsView->NoDrawState;
        ui->treeDockWidget->show(); });
    // 工具箱 Action
    connect(ui->actionToolBox, &QAction::triggered, [=]()
            {
            ui->actionScollHand->setChecked(false);
            ui->actionrubberBand->setChecked(false);
            ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
            ui->graphicsView->state = ui->graphicsView->NoDrawState;
            ui->toolDockWidget->show(); });
    // 打开文件 Action
    connect(ui->actionOpen, &QAction::triggered, [=]() {});
    // 保存文件 Action
    connect(ui->actionSave, &QAction::triggered, [=]() {});
    // 添加图层 Action
    connect(ui->actionAddLayer, &QAction::triggered, [=]()
            { this->addLayer(); });
    // 删除图层 Action
    connect(ui->actionRemoveLayer, &QAction::triggered, [=]()
            { this->deleteLayer(); });
    // 保存图层为 PDF Action
    connect(ui->actionSaveLayerPDF, &QAction::triggered, [=]()
            {
        QPrinter printer;
        if (QPrintDialog(&printer).exec() == QDialog::Accepted)
        {
            QPainter painter(&printer);
            painter.setRenderHint(QPainter::Antialiasing);
            ui->graphicsView->currentScene->render(&painter);
        } });
    // 保存图层为 Pixmap Action
    connect(ui->actionSaveLayerPixmap, &QAction::triggered, [=]()
            {
        QPixmap pixmap(ui->graphicsView->sceneRect().width(), ui->graphicsView->sceneRect().height());
        QPainter painter(&pixmap);
        // 使用 void QPixmap::fill(const QColor &color = Qt::white) 解决保存图像默认为黑色底色的问题
        pixmap.fill();
        painter.setRenderHint(QPainter::Antialiasing);
        ui->graphicsView->render(&painter);
        if (pixmap.save(QString("view%1.png").arg(ui->layerManagement->layerOrder)))
        {
            QMessageBox* message = new QMessageBox(this);
            message->setIcon(QMessageBox::Information);
            message->setText("保存成功");
            message->show();
            ui->layerManagement->layerOrder++;
        }
        else
        {
            QMessageBox* message = new QMessageBox(this);
            message->setIcon(QMessageBox::Warning);
            message->setText("保存失败");
            message->show();
        } });
    // 添加点 Action
    connect(ui->actionAddPoint, &QAction::triggered, [=]()
            { this->addGraph(ui->graphicsView->DrawPointState); });
    // 添加线 Action
    connect(ui->actionAddLine, &QAction::triggered, [=]()
            { this->addGraph(ui->graphicsView->DrawLineState); });
    // 添加折线 Action
    connect(ui->actionAddPolyLine, &QAction::triggered, [=]()
            { this->addGraph(ui->graphicsView->DrawPolylineState); });
    // 添加矩形 Action
    connect(ui->actionAddRectangle, &QAction::triggered, [=]()
            { this->addGraph(ui->graphicsView->DrawRectangleState); });
    // 添加圆 Action
    connect(ui->actionAddCircle, &QAction::triggered, [=]()
            { this->addGraph(ui->graphicsView->DrawCircleState); });
    // 添加扇形 Action
    connect(ui->actionAddSector, &QAction::triggered, [=]()
            { this->addGraph(ui->graphicsView->DrawSectorState); });
    // 添加多边形 Action
    connect(ui->actionAddPolygon, &QAction::triggered, [=]()
            { this->addGraph(ui->graphicsView->DrawPolygonState); });
    // 添加曲线 Action
    connect(ui->actionAddCurve, &QAction::triggered, [=]()
            { this->addGraph(ui->graphicsView->DrawCurveState); });
    // 添加文本 Action
    connect(ui->actionAddText, &QAction::triggered, [=]()
            { this->addGraph(ui->graphicsView->DrawTextState); });
    // 添加图片 Action
    connect(ui->actionAddPicture, &QAction::triggered, [=]()
            { this->addGraph(ui->graphicsView->DrawPixmapState); });
    // ----------------------------------- 组合图形项 -----------------------------------
    // 棋盘
    auto createChessBoard = [=]()
    {
        // 添加棋盘图形项
        ChessBoardItem *item = new ChessBoardItem();
        ui->graphicsView->currentScene->addItem(item);
    };
    connect(ui->actionChessBoard, &QAction::triggered, [=]()
            { this->addGraph(ui->graphicsView->NoDrawState, createChessBoard); });
    // 凸包
    auto createConvexHull = [=]()
    {
        // 添加凸包图形项
        ConvexHullItem *item = new ConvexHullItem();
        // 连接添加凸包点信号
        connect(ui->graphicsView, &LayerView::leftButtonPressed, [=](QMouseEvent *event)
                {
                // 若当前为添加点状态
                if (item->isAddingPoint) {
                    // 将获取的视图坐标转换为场景坐标，同时为保持添加点的位置是相对与凸包移动的坐标，需要将点的坐标转换为相对于凸包的坐标
                    QPointF point = ui->graphicsView->mapToScene(event->pos());
                    point = item->mapFromScene(point);
                    // 添加新的点
                    item->convexhull.points.push_back(point);
                    // 重新计算凸包
                    item->convexhull.findConvexHull();
                    shared_ptr<PointItem> pointItem = make_shared<PointItem>(point);
                    shared_ptr<TextItem> textItem = make_shared<TextItem>(point, QPointF(point.x() + 20, point.y() + 20), QString(" %1 ").arg(++item->index));
                    item->convexHullPointItems.push_back(pointItem);
                    item->convexHullTextItems.push_back(textItem);
                    // 更新凸包线
                    QVector<QPointF> v = QVector<QPointF>::fromStdVector(item->convexhull.convexhullResult);
                    // 首尾相连
                    v.push_back(v.first());
                    item->convexHullLineItem = make_shared<PolylineItem>(v);
                    // 更新凸包路径（近似等于凸包线路径）
                    item->path = item->convexHullLineItem->path;
                    // 更新图形项
                    item->update();
                } });
        ui->graphicsView->currentScene->addItem(item);
    };
    connect(ui->actionConvexHull, &QAction::triggered, [=]()
            { this->addGraph(ui->graphicsView->NoDrawState, createConvexHull); });
    // Delaunay 三角剖分
    connect(ui->actionDelaunayTriangulation, &QAction::triggered, [=]() {

    });
    // 修改窗口颜色
    connect(ui->actionWindowColor, &QAction::triggered, [=]()
            {
        QColor colorWindow = QColorDialog::getColor(MainWindow::window()->palette().color(QPalette::Window));
        QString style = QString("background-color: rgb(%1, %2, %3);").arg(colorWindow.red()).arg(colorWindow.green()).arg(colorWindow.blue());
        this->setStyleSheet(style);
        ui->menuBar->setStyleSheet(style);
        ui->mainToolBar->setStyleSheet(style);
        ui->graphicsView->setStyleSheet(style);
        ui->statusBar->setStyleSheet(style); });
    // 修改窗口字体
    connect(ui->actionWindowFont, &QAction::triggered, [=]()
            {
        // 判断是否按下默认键
        bool ok;
        QFont fontWindow = QFontDialog::getFont(&ok, QFont("幼圆"));
        if (ok)
        {
            QString fontStr = QString("font: %1 \"%2\"; ").arg(fontWindow.pointSize()).arg(fontWindow.family());
            QString decorationStr = "";
            // 添加下划线
            if (fontWindow.underline())
            {
                decorationStr += "underline ";
            }
            // 添加删除线
            if (fontWindow.strikeOut())
            {
                decorationStr += "line-through ";
            }
            QString style = fontStr + "text-decoration: " + decorationStr + ";";
            this->setStyleSheet(style);
            ui->menuBar->setStyleSheet(style);
            ui->mainToolBar->setStyleSheet(style);
            ui->graphicsView->setStyleSheet(style);
            ui->statusBar->setStyleSheet(style);
        }
        else
        {
            return;
        } });
    // 状态栏显示当前时间
    connect(showTime, &QTimer::timeout, [=]()
            {
        QDateTime current = QDateTime::currentDateTime();
        QString text = QString("Current time: %1 ").arg(current.toString(Qt::ISODate));
        timeLabel->setText(text); });
}

// 初始化图层管理器
void MainWindow::initLayerManagement()
{
    // 设置 tree 浮动窗口标题
    ui->treeDockWidget->setWindowTitle("数据分析");
    // 设置图层管理器标题
    ui->layerManagement->setHeaderLabels(QStringList() << "图层");
    // 开启图层管理器拖放
    ui->layerManagement->setDragEnabled(true);
    // 启用图层管理器拖放指示器
    ui->layerManagement->setDropIndicatorShown(true);
    // 设置图层管理器拖放模式为可拖放
    ui->layerManagement->setDragDropMode(QAbstractItemView::InternalMove);
    // 设置自定义菜单策略 CustomContextMenu，点击右键发出 customContextMenuRequested
    ui->layerManagement->setContextMenuPolicy(Qt::CustomContextMenu);
    // 连接 customContextMenuRequested 信号到槽函数
    connect(ui->layerManagement, &QTreeWidget::customContextMenuRequested, [=](const QPoint &pos)
            {
            // 获取鼠标点击的 QTreeWidgetItem 对象
            ui->layerManagement->selectedSceneItem = ui->layerManagement->itemAt(pos);
            int index = ui->layerManagement->indexOfTopLevelItem(ui->layerManagement->selectedSceneItem);
            // 选中了 QTreeWidgetItem 弹出菜单
            if (ui->layerManagement->selectedSceneItem)
            {
                QMenu menu(this);
                QAction* addChildItem = menu.addAction("添加图层节点");
                QAction* removeItem = menu.addAction("删除图层节点");
                // 调整菜单的位置
                QPoint menuPos = ui->layerManagement->mapToGlobal(pos);
                menuPos.setY(menuPos.y() + menu.sizeHint().height()/2);
                // 显示菜单并获取用户选择的 QAction
                QAction *selectedAction = menu.exec(menuPos);
                if (selectedAction == addChildItem)
                {
                    // 添加节点
                    ui->layerManagement->onAddItem();
                }
                else if (selectedAction == removeItem)
                {
                    auto removeLayer = [=](const QString& name) {
                        // 在父节点中查找这个节点
                        for (int i = 0; i < ui->graphicsView->scenes.size(); i++)
                        {
                            if (ui->graphicsView->scenes[i]->objectName() == name)
                            {
                                ui->graphicsView->scenes.remove(i);
                                return(true);
                            }
                        }
                        return(false);
                        };
                    // 在父节点中查找不到则删除子节点
                    if (!removeLayer(ui->layerManagement->selectedSceneItem->text(0)))
                    {
                        ui->layerManagement->onRemoveSelectedItem();
                        return;
                    }
                    // 在父节点中查找到了则删除父节点及其子节点
                    ui->layerManagement->onRemoveSelectedItem();
                    // 要删除的节点为第一个，下一个节点不存在
                    if (index == 0 && ui->graphicsView->scenes.size() == 0)
                    {
                        ui->graphicsView->currentScene->~LayerScene();
                        QMessageBox* message = new QMessageBox;
                        message->setIcon(QMessageBox::Information);
                        message->setText("当前图层集为空");
                        message->show();
                    }
                    // 要删除的节点为第一个，下一个显示的节点为删除节点的后一个
                    else if (index == 0 && ui->graphicsView->scenes.size() != 0)
                    {
                        ui->graphicsView->currentScene = ui->graphicsView->scenes[index];
                        ui->graphicsView->setScene(ui->graphicsView->currentScene);
                        ui->layerManagement->topLevelItem(index)->setCheckState(0, Qt::CheckState::Checked);
                    } 
                    //要删除的节点不为第一个，下一个显示的节点为删除节点的前一个
                    else
                    {
                        ui->graphicsView->currentScene = ui->graphicsView->scenes[index - 1];
                        ui->graphicsView->setScene(ui->graphicsView->currentScene);
                        ui->layerManagement->topLevelItem(index - 1)->setCheckState(0, Qt::CheckState::Checked);
                    }
                }
            } });
    // 图层改变时，更新对应的图层对象
    connect(ui->layerManagement, &QTreeWidget::itemChanged, [=](QTreeWidgetItem *item, int column)
            {
            // 只更换父节点而不更换子节点
            if (ui->layerManagement->indexOfTopLevelItem(item) >= 0)
            {
                // 判断当前图层是否被勾选
                if (item->checkState(column) == Qt::Checked)
                {
                    auto findLayer = [=](const QString& name) {
                        // 查找当前勾选图层
                        foreach(LayerScene * scene, ui->graphicsView->scenes)
                        {
                            if (scene->objectName() == name)
                            {
                                return(scene);
                            }
                        }
                        };
                    // 切换至当前图层
                    ui->graphicsView->currentScene = findLayer(item->text(column));
                    ui->graphicsView->setScene(ui->graphicsView->currentScene);
                }
            }
            // 顶层 item
            if (item->parent() == nullptr)
            {
                // 当前顶层 item 被选中
                if (item->checkState(column) == Qt::Checked)
                {
                    // 取消其他顶层 item 的选中状态
                    for (int i = 0; i < ui->layerManagement->topLevelItemCount(); i++)
                    {
                        QTreeWidgetItem* otherItem = ui->layerManagement->topLevelItem(i);
                        if (otherItem != item)
                        {
                            otherItem->setCheckState(0, Qt::Unchecked);
                            // 取消其他顶层 item 的所有 child 的选中状态
                            for (int j = 0; j < otherItem->childCount(); j++)
                            {
                                otherItem->child(j)->setCheckState(column, Qt::Unchecked);
                            }
                        }
                    }
                    // 设置所有 child 为选中状态
                    for (int i = 0; i < item->childCount(); i++)
                    {
                        item->child(i)->setCheckState(column, Qt::Checked);
                    }
                }
                // 顶层 item 被取消选中
                else
                {
                    // 取消当前顶层 item 所有 child 的选中状态
                    for (int i = 0; i < item->childCount(); i++)
                    {
                        item->child(i)->setCheckState(column, Qt::Unchecked);
                    }
                }
            }
            // childItem
            else
            {
                // 当前 childItem 被选中
                if (item->checkState(column) == Qt::Checked)
                {
                    // 如果顶层item未选中，选中顶层 item
                    if (item->parent()->checkState(column) != Qt::Checked)
                    {
                        item->parent()->setCheckState(column, Qt::Checked);
                    }
                }
            }
            // 检测当前有没有图层被选中
            bool allParentsDeselected = true;
            for (int i = 0; i < ui->layerManagement->topLevelItemCount(); i++)
            {
                QTreeWidgetItem* item = ui->layerManagement->topLevelItem(i);
                if (item->checkState(column) == Qt::Checked)
                {
                    allParentsDeselected = false;
                    break;
                }
            }
            // 如果所有图层都没被选中，将其切换至空场景
            if (allParentsDeselected)
            {
                ui->graphicsView->setScene(nullptr);
            } });
}

// 初始化工具箱
void MainWindow::initToolManagement()
{
    // 设置 tool 浮动窗口标题
    ui->toolDockWidget->setWindowTitle("工具箱");
    // 设置工具箱标题
    ui->toolManagement->setHeaderLabels(QStringList() << "工具");
    // 初始化搜索框搜索样式
    QAction *searchBarIcon = new QAction(this);
    // 设置图标
    searchBarIcon->setIcon(QIcon(":/搜索.png"));
    // 在输入框的左侧添加图标动作
    ui->toolBoxSearchBar->addAction(searchBarIcon, QLineEdit::LeadingPosition);
    // 输入框搜索 Filter
    connect(ui->toolBoxSearchBar, &QLineEdit::textChanged, [=](const QString &text)
            {
        // 遍历所有顶层 item
        for (int i = 0; i < ui->toolManagement->topLevelItemCount(); ++i) 
        {
            QTreeWidgetItem* item = ui->toolManagement->topLevelItem(i);
            // 如果 item 的 text 不包含输入框的 text，隐藏 item，不区分大小写
            if (!item->text(0).contains(text, Qt::CaseInsensitive))
            {
                item->setHidden(true);
            }
            else 
            {
                item->setHidden(false);
            }
        } });
    // ----------------------------------- 插值工具 -----------------------------------
    // 插值顶层节点
    QTreeWidgetItem *interpolationItem = new QTreeWidgetItem();
    interpolationItem->setText(0, "插值");
    interpolationItem->setIcon(0, QIcon(":/插值分析.png"));
    ui->toolManagement->addTopLevelItem(interpolationItem);
    // IDW
    QTreeWidgetItem *idwItem = new QTreeWidgetItem();
    idwItem->setText(0, "反距离加权法插值");
    idwItem->setIcon(0, QIcon(":/反距离加权.png"));
    interpolationItem->addChild(idwItem);
    // TIN
    QTreeWidgetItem *tinItem = new QTreeWidgetItem();
    tinItem->setText(0, "不规则三角网插值");
    tinItem->setIcon(0, QIcon(":/不规则三角网.png"));
    interpolationItem->addChild(tinItem);
    // ----------------------------------- 机器学习 -----------------------------------
    // 机器学习顶层节点
    QTreeWidgetItem *machineLearningItem = new QTreeWidgetItem();
    machineLearningItem->setText(0, "机器学习");
    machineLearningItem->setIcon(0, QIcon(":/机器学习.png"));
    ui->toolManagement->addTopLevelItem(machineLearningItem);
    // 决策树
    QTreeWidgetItem *decisionTreeItem = new QTreeWidgetItem();
    decisionTreeItem->setText(0, "决策树");
    decisionTreeItem->setIcon(0, QIcon(":/决策树.png"));
    machineLearningItem->addChild(decisionTreeItem);
    // ----------------------------------- 网络分析 -----------------------------------
    // 网络分析顶层节点
    QTreeWidgetItem *networkAnalysisItem = new QTreeWidgetItem();
    networkAnalysisItem->setText(0, "网络分析");
    networkAnalysisItem->setIcon(0, QIcon(":/网络分析.png"));
    ui->toolManagement->addTopLevelItem(networkAnalysisItem);
    // 最短路径（点到点）
    QTreeWidgetItem *shortestPathPointToPointItem = new QTreeWidgetItem();
    shortestPathPointToPointItem->setText(0, "最短路径（点到点）");
    shortestPathPointToPointItem->setIcon(0, QIcon(":/最短路径.png"));
    networkAnalysisItem->addChild(shortestPathPointToPointItem);
    // ----------------------------------- 功能槽函数 -----------------------------------
    // 初始化算法对象
    this->idwProxy = make_shared<IDWProxy>();
    this->tinProxy = make_shared<TINProxy>();
    this->decisionTreeProxy = make_shared<DecisionTreeProxy>();
    this->shortestPathPointToPointProxy = make_shared<ShortestPathPointToPointProxy>();
    // 连接绘制决策树信号到槽函数
    connect(this->decisionTreeProxy.get(), &DecisionTreeProxy::drawDecisionTreeSignal, [=](shared_ptr<Node> node)
            {
            // 添加决策树图形项
            this->addGraph(ui->graphicsView->NoDrawState);
            DecisionTreeItem* item = new DecisionTreeItem(node);
            ui->graphicsView->currentScene->addItem(item); });
    // 连接绘制最短路径（点到点）信号到槽函数
    connect(this->shortestPathPointToPointProxy.get(), &ShortestPathPointToPointProxy::drawShortestPathPointToPointSignal, [=](const vector<Place> &places, const vector<Path> &paths)
            {
            // 添加最短路径（点到点）图形项
            this->addGraph(ui->graphicsView->NoDrawState);
            auto convertCoordinate = [=](const QPointF& point) -> QPointF {
                double minY = numeric_limits<double>::max();
                double maxY = numeric_limits<double>::min();
                double minX = numeric_limits<double>::max();
                double maxX = numeric_limits<double>::min();
                for (const Place& place : places)
                {
                    minY = min(minY, place.point.y());
                    maxY = max(maxY, place.point.y());
                    minX = min(minX, place.point.x());
                    maxX = max(maxX, place.point.x());
                }
                double width = this->width();
                double height = this->height();
                double x = (point.x() - minX) / (maxX - minX) * width;
                double y = (point.y() - minY) / (maxY - minY) * height;
                return QPointF(x, y);
                };
            ShortestPathPointToPointItem* item = new ShortestPathPointToPointItem(places, paths, convertCoordinate);
            ui->graphicsView->currentScene->addItem(item);
            // 遍历路径中的每个场所
            for (const Place& place : places)
            {
                // 创建一个表示场所的椭圆项
                PointItem* nodeItem = new PointItem(convertCoordinate(place.point), place.id, item);
                nodeItem->setPen(QPen(Qt::cyan));
                nodeItem->setSize(8);
                nodeItem->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsSelectable);
                nodeItem->setParentItem(item);
                ui->graphicsView->currentScene->addItem(nodeItem);
                connect(nodeItem, &PointItem::PointSelected, [=](int id)  
                {
                        // 奇数
                        if (item->clickNum % 2 == 0)
                        {
                            if (item->shortestPathItems.size() != 0) 
                            {
                                item->shortestPathItems.clear();
                            }
                            item->start = places[id];
                            item->clickNum++;
							}
                        // 偶数
                        else 
                        {
                            item->clickNum = 0;
                            item->end = places[id];
                            // 调用最短路径（点到点）算法程序
                            vector<Place> shortest = this->shortestPathPointToPointProxy->shortestPathPointToPoint.shortestPath(item->start, item->end);
                            // 绘制最短路径（点到点）
                            for (int i = 0; i < shortest.size() - 1; i++)
                            {
                                // 查找对应的线
                                pair<int, int>key;
                                key = make_pair(shortest[i].id, shortest[i + 1].id);
                                if (item->lineMap.find(key) != item->lineMap.end())
                                {
                                    QGraphicsLineItem *lineItem = item->lineMap[key];
                                    item->shortestPathItems.push_back(lineItem);
                                }
                                key = make_pair(shortest[i+1].id, shortest[i].id);
                                if (item->lineMap.find(key) != item->lineMap.end())
                                {
                                    QGraphicsLineItem* lineItem = item->lineMap[key];
                                    item->shortestPathItems.push_back(lineItem);
                                }
                            }
                            // 弹出最短路径信息
                            double minDistance = this->shortestPathPointToPointProxy->shortestPathPointToPoint.calcMinDistance(shortest);
                            QStringList roadPath;
                            for (auto& s : shortest)
                            {
                                roadPath << QString::fromStdWString(s.name);
							}
							QMessageBox::information(this, "最短路径（点到点）", QString("最短路径：\n  路线：%1\n  长度：%2").arg(roadPath.join("->")).arg(minDistance));
                        }
                    }
                );
            } });
    // 连接 itemActivated（单次或双击，取决于平台）信号到槽函数
    connect(ui->toolManagement, &QTreeWidget::itemActivated, [=](QTreeWidgetItem *item, int column)
            {
            if (item == idwItem)
            {
                // 调用 IDW 算法程序
                this->idwProxy->initIDW();
            }
            else if (item == tinItem)
            {
                // 调用 TIN 算法程序
                this->tinProxy->initTIN();
            }
            else if (item == decisionTreeItem)
            {
                // 调用决策树算法程序
                this->decisionTreeProxy->initDecisionTree();
            }
            else if (item == shortestPathPointToPointItem)
            {
                // 调用最短路径（点到点）算法程序
                this->shortestPathPointToPointProxy->initShortestPathPointToPoint();
            } });
}

// 添加图层
void MainWindow::addLayer()
{
    ui->graphicsView->currentScene = new LayerScene();
    // 设置图层对象名称
    ui->graphicsView->currentScene->setObjectName(QString("Layer%1").arg(ui->layerManagement->layerOrder));
    ui->graphicsView->scenes.append(ui->graphicsView->currentScene);
    ui->graphicsView->setCurrentScene();
    ui->graphicsView->setScene(ui->graphicsView->currentScene);
    // 初始化图层父项
    ui->layerManagement->selectedSceneItem = new QTreeWidgetItem(QStringList() << QString("Layer%1").arg(ui->layerManagement->layerOrder));
    // 添加新的 QTreeWidgetItem* 时将不会触发 itemChanged 信号，所以这里需要手动将不为当前选中的图层设置为未选中
    for (int i = 0; i < ui->layerManagement->topLevelItemCount(); i++)
    {
        QTreeWidgetItem *otherItem = ui->layerManagement->topLevelItem(i);
        otherItem->setCheckState(0, Qt::Unchecked);
    }
    // 设置选中状态
    ui->layerManagement->selectedSceneItem->setCheckState(0, Qt::CheckState::Checked);
    // 更新图层名称
    ui->layerManagement->layerOrder++;
    // 添加到树状窗口中
    ui->layerManagement->addTopLevelItem(ui->layerManagement->selectedSceneItem);
}

// 删除图层
void MainWindow::deleteLayer()
{
    if (ui->graphicsView->scenes.size() > 1)
    {
        ui->graphicsView->scenes.pop_back();
        ui->graphicsView->setCurrentScene();
        ui->graphicsView->setScene(ui->graphicsView->currentScene);
        // 删除最后一个节点
        int lastIndex = ui->layerManagement->topLevelItemCount() - 1;
        ui->layerManagement->takeTopLevelItem(lastIndex);
        ui->layerManagement->selectedSceneItem = new QTreeWidgetItem(ui->layerManagement->topLevelItem(lastIndex - 1));
        ui->layerManagement->selectedSceneItem->setCheckState(0, Qt::CheckState::Checked);
    }
    else if (ui->graphicsView->scenes.size() == 1)
    {
        ui->graphicsView->scenes.pop_back();
        ui->graphicsView->currentScene->~LayerScene();
        int lastIndex = ui->layerManagement->topLevelItemCount() - 1;
        ui->layerManagement->takeTopLevelItem(lastIndex);
        QMessageBox *message = new QMessageBox(this);
        message->setIcon(QMessageBox::Information);
        message->setText("当前图层集为空");
        message->show();
    }
    else
    {
        QMessageBox *message = new QMessageBox(this);
        message->setIcon(QMessageBox::Warning);
        message->setText("你不能删除空的图层!");
        message->show();
    }
}

// 添加图形
void MainWindow::addGraph(LayerView::DrawState state, const function<void()> &func)
{
    if (ui->graphicsView->scenes.size() == 0)
    {
        QMessageBox *message = new QMessageBox(this);
        message->setIcon(QMessageBox::Warning);
        message->setText("当前不存在图层，将自动创建一个新图层");
        message->show();
        this->addLayer();
    }
    ui->graphicsView->state = state;
    ui->graphicsView->setScene(ui->graphicsView->currentScene);
    for (int i = 0; i < ui->layerManagement->topLevelItemCount(); i++)
    {
        if (ui->layerManagement->topLevelItem(i)->text(0) == ui->graphicsView->currentScene->objectName())
        {
            ui->layerManagement->topLevelItem(i)->setCheckState(0, Qt::CheckState::Checked);
        }
    }
    // 若其他按钮是被 Check 的，取消 Check 并取消设置这些按钮的功能
    if (ui->actionScollHand->isChecked() || ui->actionrubberBand->isChecked())
    {
        ui->actionScollHand->setChecked(false);
        ui->actionrubberBand->setChecked(false);
        ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
    }
    if (func != nullptr)
    {
        func();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
