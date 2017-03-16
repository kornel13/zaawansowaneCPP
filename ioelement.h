#ifndef IOELEMENT_H
#define IOELEMENT_H

#include <QGraphicsPolygonItem>
#include <QPointF>
#include <QPolygonF>

class Connection;

class IOElement  : public QGraphicsPolygonItem
{
public:
    IOElement(QGraphicsItem *parent= nullptr);
    void addConnection(Connection* connection);
    void removeConnection(Connection* connection);
    bool isConnection() { return connection != nullptr; }

    virtual QPointF getPosition();
    virtual QPolygonF getPolygon();

protected:
    Connection *connection;
};

#endif // IOELEMENT_H
