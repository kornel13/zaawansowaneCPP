#ifndef CONNECTION_H
#define CONNECTION_H

#include <QGraphicsLineItem>
#include <QPolygon>
#include <memory>

class OutputElement;
class InputElement;

class Connection : public QGraphicsLineItem
{
public /*enumarations*/:
    enum { Type = UserType + 11 };

public:
    Connection(std::shared_ptr<OutputElement> _start, std::shared_ptr<InputElement> _finish);
    QRectF boundingRect() const override;
    void updatePosition();
    void removeItselfFromItems();

    int type() const override { return Type; }
    OutputElement* getStart() { return start; }
    InputElement* getFinish() { return finish; }

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;

private:
    OutputElement *start;
    InputElement *finish;
    QPolygonF arrow;

};

#endif // CONNECTION_H
