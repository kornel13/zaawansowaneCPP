#ifndef INPUTELEMENT_H
#define INPUTELEMENT_H

#include <QGraphicsRectItem>
#include <QPointF>
#include <QPolygonF>

class Connection;

class InputElement : public QGraphicsRectItem
{
public:
    InputElement(QPointF center, QGraphicsItem *parent = nullptr);
    void addConnection(Connection* connection);
    void removeConnection(Connection* connection);
    bool isConnection() { return connection != nullptr; }
    bool isSpecificConnection(Connection *checked) { return connection == checked; }
    QPointF getPosition();
    QPolygonF getPolygon();


private:
    Connection *connection;

    static const qreal SIZE;

};

#endif // INPUTELEMENT_H
