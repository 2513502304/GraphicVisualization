#pragma once
#pragma execution_character_set("utf-8")

#include "CPython.h"
#include "DecisionTree.h"
#include "StyleSheet.h"
#include <QObject>
#include <QWidget>
#include <QTableWidget>
#include <QLayout>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QHeaderView>
#include <QMenu>
#include <QFileSystemWatcher>
#include <QFileDialog>
#include <QMessageBox>

using namespace std;

class MachineLearning : public QObject
{
	Q_OBJECT

public:
	explicit MachineLearning(QObject *parent = nullptr);

	~MachineLearning();
};

// 决策树委托类
class DecisionTreeProxy : public MachineLearning
{
	Q_OBJECT

public:
	explicit DecisionTreeProxy();

	~DecisionTreeProxy();

	// 文件路径
	QString filePath;

	// 决策树对象
	DecisionTree tree;

	// 决策树节点
	shared_ptr<Node> node;

	// 显示表格字段内容窗口
	shared_ptr<QTableWidget> tableWidget;

	// 初始化预测界面
	void initPredictWidget();

	// 设置目标字段
	void setTargetField(int column);

	// 初始化菜单
	void initHeaderMenu(QHeaderView *header);

	// 初始化表格
	void initTable();

	// 初始化决策树
	void initDecisionTree();

signals:
	// 绘制决策树信号，委托给 MainWindow
	void drawDecisionTreeSignal(shared_ptr<Node> node);
};