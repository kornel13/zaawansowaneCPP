#include "controller.h"
#include "connection.h"
#include "mapper.h"
#include "additemfactory.h"
#include "subtractitemfactory.h"
#include "inputitemfactory.h"
#include "outputitemfactory.h"
#include "graphicsitem.h"
#include "iexpression.h"
#include "itemattributesdialog.h"

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

QHash<int, ItemAttributesDialog*>* Controller::getItemAttributesDialogs()
{
    return &itemAttributesDialogHash;
}

void Controller::addItemFactory(ItemFactory* itemFactory)
{
    Mapper::idToItemFactoryMap[itemFactory->getId()] = itemFactory;
    itemAttributesDialogHash[itemFactory->getId()] = new ItemAttributesDialog(itemFactory->getDefaultConfig(), (QWidget*)parent());
    itemFactoryList.append(itemFactory);
}

void Controller::actionChanged(QAction* action)
{
    SceneMode mode;
    if(Mapper::actionToEnumMap[action] == Move) mode = MoveBlock;
    else mode = InsertConnection;
    emit sceneModeChanged(mode);
}

void Controller::itemToAdd(int id, ItemConfig config)
{
    selectedItemFactory = Mapper::idToItemFactoryMap[id];

    emit appliedConfig(config);
    emit sceneModeChanged(InsertItem);
}

void Controller::itemToDelete()
{
    QGraphicsItem* item = scene->selectedItems().first();
    if(Connection::Type == item->type())
    {
        Connection* connection = qgraphicsitem_cast<Connection *>(item);
        GraphicsItem *finishItem = qgraphicsitem_cast<GraphicsItem *>(connection->getFinish()->parentItem());

        int index = finishItem->getInputIndex(connection);
        connection->removeItselfFromItems();
        scene->removeItem(connection);
        delete connection;

        IExpression* endExpression = Mapper::graphicsToExpessionMap[finishItem];
        endExpression->removeExpression(index);

    }else if(GraphicsItem::Type == item->type())
    {
        GraphicsItem *graphicsItem = qgraphicsitem_cast<GraphicsItem *>(item);
        auto connections = graphicsItem->getAllConnections();
        graphicsItem->removeAllConnections();

        Connection* con;
        foreach(con, connections)
        {
            scene->removeItem(con);
            delete con;
        }
        scene->removeItem(graphicsItem);
    }

}

void Controller::itemInserted(QPointF position, ItemConfig config)
{
    if(selectedItemFactory)
    {
        Item item = selectedItemFactory->createItemObject(config);
        if(item.second->isOutput())
        {
            outputExpression = item.second;
            emit enableOutput(false);
        }
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
            QString convertedResult = result.toString();
            emit setOutputText(QString("Result is ") + convertedResult);

        }else
        {
           emit setOutputText("There's no output block added to scene");
        }

    }

