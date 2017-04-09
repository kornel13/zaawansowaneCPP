#include "GraphicsItems/inputelement.h"

#include <QBrush>
#include <QRectF>

const qreal InputElement::SIZE = 10;

InputElement::InputElement(QPointF center, QGraphicsItem *parent)
    : QGraphicsRectItem(parent)
{
    QPointF p1 = QPointF(center.x() - SIZE/2,center.y() + SIZE/2);
    QPointF p2 = QPointF(center.x() + SIZE/2,center.y() - SIZE/2);
    setRect( QRectF(p1,p2) );
    setBrush(QBrush(QColor(0,0,0)));

    connection = nullptr;
}

void InputElement::addConnection(Connection* connection)
{
    if (!isConnection() )
    {
        this->connection = connection;
    }
}

void InputElement::removeConnection(Connection* connection)
{
    this->connection = nullptr;
}

QPointF InputElement::getPosition()
{
    //return mapToScene(pos());
    return pos();
}

Connection* InputElement::getConnection()
{
    return connection;
}

QPolygonF InputElement::getPolygon()
{
    QPolygonF remappedPolygon;
    QPolygonF current(rect());
    for (int i = 1; i < current.count(); ++i)
    {
        remappedPolygon.append(current.at(i));
    }
    return remappedPolygon;
}
