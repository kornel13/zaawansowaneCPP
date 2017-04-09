#include "GraphicsItems/connection.h"

#include <QPen>
#include <QRectF>
#include <QPainterPath>
#include <QPainter>
#include <QLineF>
#include <QPolygonF>

#include "GraphicsItems/outputelement.h"
#include "GraphicsItems/inputelement.h"

Connection::Connection(std::shared_ptr<OutputElement> _start, std::shared_ptr<InputElement> _finish)
{
    start = _start.get();
    finish = _finish.get();
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    QPen _pen;
    _pen.setBrush(Qt::black);
    _pen.setCapStyle(Qt::RoundCap);
    _pen.setWidthF(2);

    setPen(_pen);
}

void Connection::removeItselfFromItems()
{
   start->removeConnection(this);
   finish->removeConnection(this);
}

void Connection::updatePosition()
{
    QLineF line(mapFromItem(start, start->boundingRect().center()), mapFromItem(finish, finish->boundingRect().center()));
    setLine(line);
}

QRectF Connection::boundingRect() const
{
    qreal extra = (pen().width() + 20) / 2.0;
    auto resultRect = QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),line().p2().y() - line().p1().y()));

    return resultRect.normalized().adjusted(-extra, -extra, extra, extra);
}

void Connection::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen myPen = pen();
    myPen.setColor(Qt::black);
    painter->setPen(myPen);
    painter->setBrush(Qt::black);

    QLineF centerLine(mapFromItem(start, start->boundingRect().center()), mapFromItem(finish, finish->boundingRect().center()));
    setLine(centerLine);
    painter->drawLine(line());

    if (isSelected()) {
        painter->setPen(QPen(Qt::black, 1, Qt::DashLine));
        QLineF myLine = line();
        myLine.translate(0, 4.0);
        painter->drawLine(myLine);
        myLine.translate(0,-8.0);
        painter->drawLine(myLine);
    }

}






