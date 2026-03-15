#include "NetworkAnalysis.h"

NetworkAnalysis::NetworkAnalysis(QObject *parent)
	: QObject(parent)
{
}

NetworkAnalysis::~NetworkAnalysis()
{
}

ShortestPathPointToPointProxy::ShortestPathPointToPointProxy()
{
}

ShortestPathPointToPointProxy::~ShortestPathPointToPointProxy()
{
}

// 初始化最短路径
void ShortestPathPointToPointProxy::initShortestPathPointToPoint()
{
	// 读取路网文件
	this->placeFile = QFileDialog::getOpenFileName(nullptr, tr("Open Node File"), "", tr("Txt Files(*.txt)"));
	if (this->placeFile.isEmpty())
	{
		QMessageBox::warning(nullptr, tr("Warning"), tr("No File Selected!"), QMessageBox::Yes);
		return;
	}
	// 读取路网路径文件
	this->pathFile = QFileDialog::getOpenFileName(nullptr, tr("Open Node File"), "", tr("Txt Files(*.txt)"));
	if (this->pathFile.isEmpty())
	{
		QMessageBox::warning(nullptr, tr("Warning"), tr("No File Selected!"), QMessageBox::Yes);
		return;
	}
	// 创建最短路径（点到点）对象
	this->shortestPathPointToPoint = ShortestPathPointToPoint(this->placeFile.toStdString(), this->pathFile.toStdString());
	// 发送绘制最短路径（点到点）信号
	emit drawShortestPathPointToPointSignal(this->shortestPathPointToPoint.places, this->shortestPathPointToPoint.paths);
}