#pragma once
#pragma execution_character_set("utf-8")

#include "StyleSheet.h"
#include "ShortestPath.h"
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

class NetworkAnalysis : public QObject
{
	Q_OBJECT

public:
	explicit NetworkAnalysis(QObject *parent = nullptr);

	~NetworkAnalysis();
};

// 最短路径（点到点）委托类
class ShortestPathPointToPointProxy : public NetworkAnalysis
{
	Q_OBJECT

public:
	explicit ShortestPathPointToPointProxy();

	~ShortestPathPointToPointProxy();

	// 路网文件路径
	QString placeFile;

	// 路网路径文件路径
	QString pathFile;

	// 最短路径对象
	ShortestPathPointToPoint shortestPathPointToPoint;

	// 初始化最短路径
	void initShortestPathPointToPoint();

signals:
	// 绘制最短路径（点到点）信号，委托给 MainWindow
	void drawShortestPathPointToPointSignal(const vector<Place> &place, const vector<Path> &path);
};
