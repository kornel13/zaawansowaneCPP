#include "GraphicsItems/outputelement.h"

#include <QBrush>
#include <QDebug>

const qreal OutputElement::SIZE = 25;

OutputElement::OutputElement(QPointF center, QGraphicsItem *parent)
    : QGraphicsPolygonItem(parent)
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
    this->connection = nullptr;
    qDebug()<<"con to null A: "<< (connection != nullptr) <<"\n";
    qDebug()<<"con to null B: "<<isConnection()<<"\n";

}

QPointF OutputElement::getPosition()
{
    return mapToScene(pos());
}

Connection* OutputElement::getConnection()
{
    return connection;
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
