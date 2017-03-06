#ifndef OUTPUTELEMENT_H
#define OUTPUTELEMENT_H

#include <QGraphicsPolygonItem>
#include <QPointF>
#include <QPolygonF>

class Connection;

class OutputElement : public QGraphicsPolygonItem
{
public:
    OutputElement(QPointF center);
    void addConnection(Connection* connection);
    void removeConnection(Connection* connection);
    bool isConnection() { return connection != nullptr; }
    QPointF getPosition();
    QPolygonF getPolygon();

private:
    Connection *connection;
    static const qreal SIZE;
};

#endif // OUTPUTELEMENT_H
