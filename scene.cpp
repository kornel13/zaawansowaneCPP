#include "scene.h"

#include <graphicsitem.h>
#include <QAction>
#include <QGraphicsLineItem>
#include <QLineF>
#include <QList>
#include <QDebug>

#include <QGraphicsSceneMouseEvent>

#include "connection.h"


Scene::Scene(QObject *parent)
    : QGraphicsScene(parent)
{

    //test
    addItem(new GraphicsItem(3,1));


}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

    if ( InsertConnection == mode)
    {
        currentLine = new QGraphicsLineItem(QLineF(mouseEvent->scenePos(), mouseEvent->scenePos()));
        addItem(currentLine);
    }else if (InsertItem == mode)
    {
        emit itemInserted(mouseEvent->scenePos());
    }

    //qDebug("Wcisnieto\n");
    QGraphicsScene::mousePressEvent(mouseEvent);
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if ( InsertConnection == mode && currentLine )
    {
        QLineF newLinePosition(currentLine->line().p1(), event->scenePos());
        currentLine->setLine(newLinePosition);
    }
    else if( MoveBlock == mode )
    {
        QGraphicsScene::mouseMoveEvent(event);
    }
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if ( InsertConnection == mode && currentLine )
    {
        QPointF startPoint = currentLine->line().p1();
        QPointF finishPoint = currentLine->line().p2();
        qDebug()<<"startPoint: "<<startPoint<<"finishPoint: "<<finishPoint<<"\n";

        QList<QGraphicsItem *> blocksAtLineStart = items(startPoint);
        QList<QGraphicsItem *> blocksAtLineFinish = items(finishPoint);

        filterBlockItems(blocksAtLineStart);
        filterBlockItems(blocksAtLineFinish);

        if(!blocksAtLineStart.isEmpty() && !blocksAtLineFinish.isEmpty() )
        {
            GraphicsItem *startBlock = qgraphicsitem_cast<GraphicsItem *>(blocksAtLineStart.first());
            GraphicsItem *finishBlock = qgraphicsitem_cast<GraphicsItem *>(blocksAtLineFinish.first());
            if(startBlock != finishBlock)
            {
                int inputIndex = -1;
                if(startBlock->canOutputBeConnected(startPoint)
                        && finishBlock->whichInputCanBeConnected(finishPoint) != -1)
                {
                    inputIndex = finishBlock->whichInputCanBeConnected(finishPoint);

                    Connection *connection = new Connection(startBlock->getOutput(), finishBlock->getInput(inputIndex));
                    connection->setZValue(-200);
                    addItem(connection);
                    connection->updatePosition();
                    emit connectionInserted(startBlock, 0, finishBlock, (unsigned)inputIndex);
                }
            }
        }


        removeItem(currentLine);
        delete currentLine;
        currentLine = nullptr;
    }

    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

void Scene::modeChanged(SceneMode mode)
{
    qDebug()<<"Scene::modeChanged";
    this->mode = mode;
}

void Scene::filterBlockItems(QList<QGraphicsItem *> &list)
{
    if ( !list.isEmpty())
    {
       for(int i = 0; i < list.size(); ++i)
       {
           if(list[i]->type() != GraphicsItem::Type)
           {
               list.removeAt(i);
               --i;
           }
       }

    }
}

