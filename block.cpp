#include "block.h"

#include <QPointF>
#include <QRectF>
#include <QBrush>

const qreal Block::SIZE = 100;

Block::Block()
{
    setBase();
    setInputs(3);
    setOutput();

    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

void Block::setBase()
{
    base = std::make_shared<QGraphicsRectItem>();
    base->setRect( getBaseRect() );
    addToGroup(base.get());
}

void Block::setInputs(int number)
{
    qreal step = SIZE / (number + 1);
    qreal startXYCoordinate = -SIZE / 2;
    qreal centerX = startXYCoordinate;
    qreal centerY = 0;

    inputs.reserve(number);

    for( int i = 1; i <= number; ++i )
    {
        centerY = startXYCoordinate + i * step;

        auto inputItem = std::make_shared<InputElement>(QPointF(centerX,centerY) );
        addToGroup(inputItem.get());

        inputs.append(inputItem);
    }
}

void Block::setOutput()
{
    qreal centerX = SIZE / 2;
    qreal centerY = 0;

    output = std::make_shared<OutputElement>(QPointF(centerX,centerY));
    addToGroup(output.get());

}


QRectF Block::getBaseRect() const
{
    auto half = SIZE / 2;
    return QRectF( QPointF(-half,half), QPointF(half,-half) );
}

int Block::whichInputCanBeConnected(QPointF point)
{
    int whichCanConnect = -1;
    for( int i = 0; i < inputs.size(); ++i )
    {
        QPointF pp = mapFromScene(point);
        QPointF pp2 = mapToScene(point);
        QRectF huj = inputs[i]->boundingRect();
        bool hh = huj.contains(pp);
        bool ff = !inputs[i]->isConnection();
        bool dupa = hh && ff;

        if(inputs[i]->boundingRect().contains(pp) && !inputs[i]->isConnection() )
        {
            whichCanConnect = i;
            break;
        }
    }
    return whichCanConnect;

}

bool Block::canOutputBeConnected(QPointF point)
{
    QPointF pp = mapFromScene(point);
    bool cos = output->boundingRect().contains(point) && !output->isConnection();
    return output->boundingRect().contains(point) && !output->isConnection();
}



