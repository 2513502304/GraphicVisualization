#pragma once

#include "GraphItem.h"
#include <QGraphicsScene>

using namespace std;

class LayerScene : virtual public QGraphicsScene
{
	Q_OBJECT

public:
	explicit LayerScene(QObject *parent = nullptr);

	~LayerScene();
};
