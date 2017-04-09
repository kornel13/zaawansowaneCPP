#include "GraphicsItems/graphicsitem.h"
#include "GraphicsItems/connection.h"

#include <QPointF>
#include <QRectF>
#include <QBrush>
#include <QFont>

#include <QDebug>

const qreal GraphicsItem::SIZE = 100;

GraphicsItem::GraphicsItem(unsigned inputsNumber, unsigned outputNumber, QString className, QString itemName, QString icon)
{
    setBase();
    Q_ASSERT(inputsNumber <= 5);
    Q_ASSERT(outputNumber <= 1);

    setInputs(inputsNumber);
    setOutput(outputNumber);

    setClassAndItemNames(className,itemName);
    setIcon(icon);

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

void GraphicsItem::setOutput(int number)
{
    if(number)
    {
        qreal centerX = SIZE / 2;
        qreal centerY = 0;

        output = std::make_shared<OutputElement>(QPointF(centerX,centerY), this);
        addToGroup(output.get());
    }else
    {
        output = std::shared_ptr<OutputElement>();
    }


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
    qDebug() << "Can output be connected "<<!output->isConnection()<<"\n";
    return output->boundingRect().contains(mappedPoint) && !output->isConnection();
}

void GraphicsItem::removeConnection(Connection* connection)
{
    for( int i = 0; i < inputs.size(); ++i )
        if(inputs[i]->isSpecificConnection(connection))
        {
            inputs[i]->removeConnection(connection);
            qDebug()<<"Removed input con from id "<<i<<"\n";
            return;
        }
    if(output->isSpecificConnection(connection))
    {
        output->removeConnection(connection);
        qDebug()<<"Removed output con\n";
        return;
    }
    qDebug()<<"Czyli nie tu";
}

QList<Connection*> GraphicsItem::getAllConnections()
{
    QList<Connection*> list;
    for( int i = 0; i < inputs.size(); ++i )
    {
        if(inputs[i]->isConnection())
        {
            list.append(inputs[i]->getConnection());
        }
    }
    if(output && output->isConnection())
    {
        list.append(output->getConnection());
    }

    return list;
}

void GraphicsItem::removeAllConnections()
{
    for( int i = 0; i < inputs.size(); ++i )
    {
        if(inputs[i]->isConnection())
            inputs[i]->getConnection()->removeItselfFromItems();
    }
    if(output && output->isConnection())
        output->getConnection()->removeItselfFromItems();
}


int GraphicsItem::getInputIndex(Connection* connection)
{
    int index = -1;
    for( int i = 0; i < inputs.size(); ++i )
        if(inputs[i]->isSpecificConnection(connection))
        {
            index = i;
            break;
        }
    return index;
}

void GraphicsItem::setClassAndItemNames(QString className, QString itemName)
{
    this->className = std::make_shared<QGraphicsSimpleTextItem>(className,this);
    QFont font= this->className->font();
    font.setItalic(true);
    this->className->setFont(font);
    centerSubitem(this->className);
    moveByY(this->className,-SIZE/2 + 10);

    this->itemName = std::make_shared<QGraphicsSimpleTextItem>(itemName,this);
    font.setItalic(false);
    font.setBold(true);
    this->itemName->setFont(font);
    centerSubitem(this->itemName);
    moveByY(this->itemName,SIZE/2 - 10);

    addToGroup(this->className.get());
    addToGroup(this->itemName.get());

}

void GraphicsItem::centerSubitem(std::shared_ptr<QGraphicsItem> item)
{
    qreal dx = -(item->boundingRect().width())/2;
    qreal dy = -(item->boundingRect().height())/2;
    item->moveBy(dx,dy);
}


void GraphicsItem::moveByY(std::shared_ptr<QGraphicsItem> item, qreal dy)
{
    item->moveBy(0.0, dy);
}

void GraphicsItem::setIcon(QString itemString)
{
    this->icon = std::make_shared<Icon>(itemString,this);
    QFont font= this->icon->font();
    font.setPointSize(SIZE/2);
    this->icon->setFont(font);
    centerSubitem(this->icon);

    addToGroup(this->icon.get());
}




