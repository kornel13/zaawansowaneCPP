#ifndef OUTPUTELEMENT_H
#define OUTPUTELEMENT_H

#include <QGraphicsPolygonItem>
#include <QPointF>
#include <QPolygonF>

class Connection;

class OutputElement : public QGraphicsPolygonItem
{
public:
    OutputElement(QPointF center, QGraphicsItem *parent = nullptr);
    void addConnection(Connection* connection);
    void removeConnection(Connection* connection);
    bool isConnection() { return connection != nullptr; }
    bool isSpecificConnection(Connection *checked) { return connection == checked; }

    QPointF getPosition();
    QPolygonF getPolygon();
    Connection* getConnection();

private:
    Connection *connection;
    static const qreal SIZE;
};

#endif // OUTPUTELEMENT_H
