#include "ioelement.h"
#include "connection.h"

IOElement::IOElement(QGraphicsItem *parent): QGraphicsPolygonItem(parent)
{
}

void IOElement::addConnection(Connection* connection)
{
    if (!isConnection() )
    {
        this->connection = connection;
    }
}

void IOElement::removeConnection(Connection* connection)
{
    connection = nullptr;
}

QPointF IOElement::getPosition()
{
    return mapToScene(pos());
}

QPolygonF IOElement::getPolygon()
{
    QPolygonF remappedPolygon;
    for (int i = 1; i < polygon().count(); ++i)
    {
        remappedPolygon.append(polygon().at(i));
    }
    return remappedPolygon;
}
