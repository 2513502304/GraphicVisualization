#pragma once
#pragma execution_character_set("utf-8")

#include "CPython.h"
#include "IDW.h"
#include "TIN.h"
#include "StyleSheet.h"
#include <QObject>
#include <QTableWidget>
#include <QFileSystemWatcher>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>

using namespace std;

class Interpolation : public QObject
{
    Q_OBJECT

public:
    explicit Interpolation(QObject *parent = nullptr);

    ~Interpolation();
};

// IDW 委托类
class IDWProxy : public Interpolation
{
    Q_OBJECT

public:
    explicit IDWProxy();

    ~IDWProxy();

    // 文件路径
    QString filePath;

    // 存储点坐标路径
    QString coordinatesPath = "./Coordinates.txt";

    // 文件名高程值字段
    QString elevField = "ELEV";

    // 当前用户点击点
    QPointF point;

    // IDW 对象
    IDW idw;

    // 文件监视器对象
    shared_ptr<QFileSystemWatcher> fileWatcher;

    // 读取用户点击的点
    void readPoint(const string &file);

    // 初始化 IDW
    void initIDW();
};

// TIN 委托类
class TINProxy : public Interpolation
{
    Q_OBJECT

public:
    explicit TINProxy();

    ~TINProxy();

    // 文件路径
    QString filePath;

    // TIN 对象
    TIN tin;

    // 显示表格字段内容窗口
    shared_ptr<QTableWidget> tableWidget = nullptr;

    // 初始化表格
    void initTable();

    // 初始化 TIN
    void initTIN();
};