#include "controller.h"
#include "mapper.h"
#include "additemfactory.h"
#include "subtractitemfactory.h"
#include "inputitemfactory.h"
#include "outputitemfactory.h"
#include "graphicsitem.h"
#include "iexpression.h"

#include <QDebug>
Controller::Controller(Scene *scene, QObject *parent)
    : QObject(parent), scene(scene)
{
    outputExpression = nullptr;

    addItemFactory(new AddItemFactory(Mapper::getItemFactoryId(), this));
    addItemFactory(new SubtractItemFactory(Mapper::getItemFactoryId(), this));
    addItemFactory(new InputItemFactory(Mapper::getItemFactoryId(), this));
    addItemFactory(new OutputItemFactory(Mapper::getItemFactoryId(), this));
}

QList<ItemFactory*> Controller::getItemFactory()
{
    return itemFactoryList;
}

void Controller::addItemFactory(ItemFactory* itemFactory)
{
    Mapper::idToItemFactoryMap[itemFactory->getId()] = itemFactory;
    itemFactoryList.append(itemFactory);
}

void Controller::actionChanged(QAction* action)
{
    SceneMode mode;
    if(Mapper::actionToEnumMap[action] == Move) mode = MoveBlock;
    else mode = InsertConnection;
    emit sceneModeChanged(mode);
}

void Controller::buttonChanged(int id)
{
    qDebug()<<"klik";
    selectedItemFactory = Mapper::idToItemFactoryMap[id];
    emit sceneModeChanged(InsertItem);
}

void Controller::itemInserted(QPointF position)
{
    qDebug()<<"itemInserted - 1";
    if(selectedItemFactory)
    {
        qDebug()<<"itemInserted - 2";
        QMap<QString,QString> debug;
        Item item = selectedItemFactory->createItemObject(debug);
        if(item.second->isOutput()) outputExpression = item.second;
        Mapper::graphicsToExpessionMap[item.first] = item.second;
        scene->addItem(item.first);
        item.first->setPos(position);
    }
}

void Controller::connectionInserted(GraphicsItem* start, unsigned,
                        GraphicsItem* end, unsigned inId)
{
    IExpression* startExpression = Mapper::graphicsToExpessionMap[start];
    IExpression* endExpression = Mapper::graphicsToExpessionMap[end];

    endExpression->addExpression(startExpression, inId);
}

    void  Controller::calculate(bool)
    {
        if(outputExpression)
        {
            Data result = outputExpression->evaluate();
            QString convertedResult = QString::number(result);
            emit setOutputText(QString("Result is ") + convertedResult);

        }else
        {
           emit setOutputText("There's no output block added to scene");
        }

    }

