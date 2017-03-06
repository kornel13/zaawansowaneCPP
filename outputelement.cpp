#include "outputelement.h"

#include <QBrush>

const qreal OutputElement::SIZE = 15;

OutputElement::OutputElement(QPointF center)
{
    QPolygonF polygon = QPolygonF();

    polygon << QPointF(center.x(), center.y())
            << QPointF(center.x(), center.y() + SIZE / 2)
            << QPointF(center.x()+ SIZE / 2, center.y() )
            << QPointF(center.x(), center.y() - SIZE / 2)
            << QPointF(center.x(), center.y());

    setPolygon(polygon);
    setBrush(QBrush(QColor(0,0,0)));

    connection = nullptr;

}

void OutputElement::addConnection(Connection* connection)
{
    if (!isConnection() )
    {
        this->connection = connection;
    }
}

void OutputElement::removeConnection(Connection* connection)
{
    connection = nullptr;
}

QPointF OutputElement::getPosition()
{
    return mapToScene(pos());
}

QPolygonF OutputElement::getPolygon()
{
    QPolygonF remappedPolygon;
    for (int i = 1; i < polygon().count(); ++i)
    {
        remappedPolygon.append(polygon().at(i));
    }
    return remappedPolygon;
}
