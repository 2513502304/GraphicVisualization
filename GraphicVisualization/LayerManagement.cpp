#include "LayerManagement.h"

LayerManagement::LayerManagement(QWidget *parent) : QTreeWidget(parent)
{
}

// 添加节点
void LayerManagement::onAddItem()
{
    QList<QTreeWidgetItem *> selectItemList = this->selectedItems();
    // 这里构造函数不能写为this，若为this，就直接将其添加为了顶层节点
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, QStringLiteral("新建图层节点"));
    item->setCheckState(0, Qt::CheckState::Unchecked);
    item->setFlags(item->flags() | Qt::ItemFlag::ItemIsEditable);
    // 若没有选中则返回
    if (selectItemList.size() == 0)
    {
        return;
    }
    // 选中则添加一个子节点
    else
    {
        selectItemList.first()->addChild(item);
    }
}

// 删除选中的节点
void LayerManagement::onRemoveSelectedItem()
{
    QList<QTreeWidgetItem *> items = this->selectedItems();
    for (int i = 0; i < items.size(); i++)
    {
        removeItem(items[i]);
    }
}

// 递归删除节点
void LayerManagement::removeItem(QTreeWidgetItem *item)
{
    int count = item->childCount();
    // 没有子节点，直接删除
    if (count == 0)
    {
        delete item;
        return;
    }
    // 删除子节点
    for (int i = 0; i < count; i++)
    {
        QTreeWidgetItem *childItem = item->child(0);
        removeItem(childItem);
    }
    // 最后将自己删除
    delete item;
}
