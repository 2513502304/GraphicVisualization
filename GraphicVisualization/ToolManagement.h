#pragma once
#pragma execution_character_set("utf-8")

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QDebug>

using namespace std;

class ToolManagement : public QTreeWidget
{
public:
	explicit ToolManagement(QWidget *parent = nullptr);

	~ToolManagement();
};
