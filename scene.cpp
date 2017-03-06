#include "scene.h"

#include <block.h>
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
    addItem(new Block());

    Block *secondItem = new Block();
    qreal x = secondItem->x() + 200;
    secondItem->setX(x);

    addItem(secondItem);

}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

    if ( InsertConnection == mode)
    {
        currentLine = new QGraphicsLineItem(QLineF(mouseEvent->scenePos(), mouseEvent->scenePos()));
        addItem(currentLine);
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
        qDebug("Tutaj 1\n");
        QPointF startPoint = currentLine->line().p1();
        QPointF finishPoint = currentLine->line().p2();
        QList<QGraphicsItem *> blocksAtLineStart = items(startPoint);
        QList<QGraphicsItem *> blocksAtLineFinish = items(finishPoint);

        if ( !blocksAtLineStart.isEmpty() )
        {
           for(int i = 0; i < blocksAtLineStart.size(); ++i)
           {
               if(blocksAtLineStart[i]->type() != Block::Type)
               {
                   blocksAtLineStart.removeAt(i);
                   --i;
               }
           }

        }

        if ( !blocksAtLineFinish.isEmpty())
        {
           for(int i = 0; i < blocksAtLineFinish.size(); ++i)
           {
               if(blocksAtLineFinish[i]->type() != Block::Type)
               {
                   blocksAtLineFinish.removeAt(i);
                   --i;
               }
           }

        }

        qDebug("Tutaj 2\n");
        if(!blocksAtLineStart.isEmpty() && !blocksAtLineFinish.isEmpty() )
        {
            qDebug("Tutaj 3\n");
            Block *startBlock = qgraphicsitem_cast<Block *>(blocksAtLineStart.first());
            Block *finishBlock = qgraphicsitem_cast<Block *>(blocksAtLineFinish.first());
            //if(startBlock != finishBlock)
            {
                /*

                if(startBlock->canOutputBeConnected(startPoint) )
                    qDebug("Output OK\n");
                else
                    qDebug("Output NOK\n");

                if (finishBlock->whichInputCanBeConnected(finishPoint) != -1)
                    qDebug("Input OK: %d\n");
                else
                    qDebug("Input NOK\n");
                */
                int inputIndex = -1;
                if(startBlock->canOutputBeConnected(startPoint)
                        && finishBlock->whichInputCanBeConnected(finishPoint) != -1)
                {
                    qDebug("Tutaj 4n");
                    inputIndex = finishBlock->whichInputCanBeConnected(finishPoint);

                    Connection *connection = new Connection(startBlock->getOutput(), finishBlock->getInput(inputIndex));
                    connection->setZValue(-200);
                    addItem(connection);
                    connection->updatePosition();
                }
            }

        }


        removeItem(currentLine);
        delete currentLine;
        currentLine = nullptr;
    }

    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

void Scene::modeChanged(QAction *action)
{
    qDebug("Menu: %s\n", action->text());
    if( action -> text() == "Move") mode = MoveBlock;
    else mode = InsertConnection;
}

