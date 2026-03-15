#pragma once
#pragma execution_character_set("utf-8")

#include "StyleSheet.h"
#include "Interpolation.h"
#include "MachineLearning.h"
#include "NetworkAnalysis.h"
#include <QMainWindow>
#include "ui_MainWindow.h"
#include <QDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QPixmap>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>
#include <functional>

using namespace std;

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    Ui::MainWindow *ui;

    // IDW 算法
    shared_ptr<IDWProxy> idwProxy;

    // TIN 算法
    shared_ptr<TINProxy> tinProxy;

    // 决策树算法
    shared_ptr<DecisionTreeProxy> decisionTreeProxy;

    // 最短路径（点到点）算法
    shared_ptr<ShortestPathPointToPointProxy> shortestPathPointToPointProxy;

    // 初始化图层管理器
    void initLayerManagement();

    // 初始化工具箱
    void initToolManagement();

    // 添加图层
    void addLayer();

    // 删除图层
    void deleteLayer();

    // 添加图形
    void addGraph(LayerView::DrawState state, const function<void()> &func = nullptr);
};
