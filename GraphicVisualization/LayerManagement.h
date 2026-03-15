#pragma once
#pragma execution_character_set("utf-8")

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QDebug>

using namespace std;

class LayerManagement : public QTreeWidget
{
    Q_OBJECT

public:
    explicit LayerManagement(QWidget *parent = nullptr);

    // 图层次序
    int layerOrder = 0;

    // 图层父项
    QTreeWidgetItem* selectedSceneItem;

    // 添加节点
    void onAddItem();

    // 删除被选中的节点
    void onRemoveSelectedItem();

    // 删除节点
    void removeItem(QTreeWidgetItem* item);
};
