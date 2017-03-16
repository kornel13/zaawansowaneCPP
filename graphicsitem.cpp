#include "graphicsitem.h"

#include <QPointF>
#include <QRectF>
#include <QBrush>

#include <QDebug>

const qreal GraphicsItem::SIZE = 100;

GraphicsItem::GraphicsItem()
{
    setBase();
    setInputs(3);
    setOutput();

    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

void GraphicsItem::setBase()
{
    base = std::make_shared<QGraphicsRectItem>();
    base->setRect( getBaseRect() );
    addToGroup(base.get());
}

void GraphicsItem::setInputs(int number)
{
    qreal step = SIZE / (number + 1);
    qreal startXYCoordinate = -SIZE / 2;
    qreal centerX = startXYCoordinate;
    qreal centerY = 0;

    inputs.reserve(number);

    for( int i = 1; i <= number; ++i )
    {
        centerY = startXYCoordinate + i * step;

        auto inputItem = std::make_shared<InputElement>(QPointF(centerX,centerY), this);
        addToGroup(inputItem.get());

        inputs.append(inputItem);
    }
}

void GraphicsItem::setOutput()
{
    qreal centerX = SIZE / 2;
    qreal centerY = 0;

    output = std::make_shared<OutputElement>(QPointF(centerX,centerY), this);
    addToGroup(output.get());

}


QRectF GraphicsItem::getBaseRect() const
{
    auto half = SIZE / 2;
    return QRectF( QPointF(-half,half), QPointF(half,-half) );
}

int GraphicsItem::whichInputCanBeConnected(QPointF point)
{
    int whichCanConnect = -1;
    for( int i = 0; i < inputs.size(); ++i )
    {
        QPointF mappedPoint = mapFromScene(point);

        if(inputs[i]->boundingRect().contains(mappedPoint) && !inputs[i]->isConnection() )
        {
            whichCanConnect = i;
            break;
        }
    }
    return whichCanConnect;

}

bool GraphicsItem::canOutputBeConnected(QPointF point)
{
    QPointF mappedPoint = mapFromScene(point);
    return output->boundingRect().contains(mappedPoint) && !output->isConnection();
}



