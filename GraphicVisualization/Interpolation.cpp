#include "Interpolation.h"

Interpolation::Interpolation(QObject *parent)
    : QObject(parent)
{
}

Interpolation::~Interpolation()
{
}

IDWProxy::IDWProxy()
{
    // 初始化 Python 解释器，仅调用一次
    CPython::initPython();
    // 初始化文件监视器对象
    this->fileWatcher = make_shared<QFileSystemWatcher>(nullptr);
    // 添加要监视的文件
    this->fileWatcher->addPath(this->coordinatesPath);
    // 检测文件是否被修改
    connect(this->fileWatcher.get(), &QFileSystemWatcher::fileChanged, [=](const QString &path)
            {
            // 读取当前点
            this->readPoint(path.toStdString());
            bool ok;
            double nearestNum = QInputDialog::getDouble(nullptr, "选取临近点个数", "请输入临近点个数：",100, 1, 2147483647, 2, &ok);
            if (ok)
            {
                // 计算当前点的 IDW 值
                double eval = this->idw.interpolate(this->point, nearestNum);
                // 显示当前点的 IDW 值
                QMessageBox::information(nullptr, "Point", QString("插值点个数: %1\nlon: %2\nlat: %3\nEval: %4").arg(nearestNum).arg(this->point.x(), 0, 'f', 20).arg(this->point.y(), 0, 'f', 20).arg(eval, 0, 'f', 20), QMessageBox::Yes);
            }
            else 
            {
                // 计算当前点的 IDW 值
                double eval = this->idw.interpolate(this->point);
                // 显示当前点的 IDW 值
                QMessageBox::information(nullptr, "Point", QString("默认插值点个数: 100\nlon:  %1\nlat:  %2\nEval: %3").arg(this->point.x(), 0, 'f', 20).arg(this->point.y(), 0, 'f', 20).arg(eval, 0, 'f', 20), QMessageBox::Yes);
            }
            });
}

IDWProxy::~IDWProxy()
{
    // 清理 Python 解释器，仅调用一次
    CPython::clearPython();
}

// 读取用户点击的点
void IDWProxy::readPoint(const string &file)
{
    // 读取文件
    ifstream in(file);
    // 读取点的坐标
    double x, y;
    in >> x >> y;
    this->point.setX(x);
    this->point.setY(y);
    // 关闭文件
    in.close();
}

// 初始化 IDW
void IDWProxy::initIDW()
{
    // 读取文件
    this->filePath = QFileDialog::getOpenFileName(nullptr, QObject::tr("Open File"), "", QObject::tr("JSON Files(*.json *.geojson)"));
    if (this->filePath.isEmpty())
    {
        QMessageBox::warning(nullptr, QObject::tr("Warning"), QObject::tr("No File Selected!"), QMessageBox::Yes);
        return;
    }
    // 初始化 IDW 对象
    this->idw = IDW(this->filePath.toStdString());
    // 使用 Matplotlib 显示 2D/3D 等高线地图
    CPython::IDW::showContourMap(this->filePath.toStdString(), this->elevField.toStdString());
}

TINProxy::TINProxy()
{
}

TINProxy::~TINProxy()
{
}

// 初始化表格
void TINProxy::initTable()
{
    // 初始化表格
    this->tableWidget = make_shared<QTableWidget>();
    // 获取文件名称
    QString fileName = this->filePath.split("/").last();
    // 设置表格的标题
    this->tableWidget->setWindowTitle(fileName);
    // 设置表格的样式
    this->tableWidget->setStyleSheet(TableWidgetStyleSheet);
    // 表头字段
    QStringList sl;
    // 表大小
    QSize size = QSize(this->tin.table.begin()->second.size(), this->tin.table.size());
    // 设置表格的列数
    this->tableWidget->setColumnCount(size.height());
    // 设置表格的行数
    for (int i = 0; i < size.width(); i++)
    {
        // 添加一个新的行
        tableWidget->insertRow(i);
    }
    int col = 0;
    // 遍历表格的每一个字段
    for (const auto &p : this->tin.table)
    {
        int row = 0;
        string key = p.first;
        sl << QString::fromStdString(key);
        vector<string> fields = p.second;
        // 遍历每一个字段的值
        for (auto &field : fields)
        {
            // 创建一个新的 QTableWidgetItem
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setText(QString::fromStdString(field));
            // 将 QTableWidgetItem 添加到 QTableWidget
            tableWidget->setItem(row++, col, item);
        }
        col++;
    }
    // 设置表头字段
    this->tableWidget->setHorizontalHeaderLabels(sl);
}

// 初始化 TIN
void TINProxy::initTIN()
{
    // 读取文件
    this->filePath = QFileDialog::getOpenFileName(nullptr, QObject::tr("Open File"), "", QObject::tr("CSV Files(*.csv)"));
    if (this->filePath.isEmpty())
    {
        QMessageBox::warning(nullptr, QObject::tr("Warning"), QObject::tr("No File Selected!"), QMessageBox::Yes);
        return;
    }
    // 初始化 TIN 对象
    this->tin = TIN(this->filePath.toStdString());
    //// 创建 Delaunay 三角剖分
    // this->tin.createDelaunay();
    //// 初始化表格
    // this->initTable();
    //// 初始化属性字段窗口大小
    // this->tableWidget->setFixedSize(QSize(800, 600));
    //// 显示属性字段窗口
    // this->tableWidget->show();
}