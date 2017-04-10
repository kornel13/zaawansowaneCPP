#include "controller.h"
#include "GraphicsItems/connection.h"
#include "Common/mapper.h"
#include "Factories/additemfactory.h"
#include "Factories/subtractitemfactory.h"
#include "Factories/inputitemfactory.h"
#include "Factories/outputitemfactory.h"
#include "GraphicsItems/graphicsitem.h"
#include "Expressions/iexpression.h"
#include "itemattributesdialog.h"

#include <QDebug>
Controller::Controller(Scene *scene, ChartDialog *chartDialog, QObject *parent)
    : QObject(parent), scene(scene), chartDialog(chartDialog)
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

        IExpression* endExpression = Mapper::graphicsToExpessionMap[finishItem];
        endExpression->removeExpression(index);

        delete connection;

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

        IExpression* expression = Mapper::graphicsToExpessionMap[graphicsItem];
        expression->removeAllExpressions();
        if(expression->isOutput())
        {
            emit enableOutput(true);
        }

        delete graphicsItem;
        delete expression;
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
            if(result.isValid())
            {
                if(auto idataseries = result.toIDataSeries())
                {
                   chartDialog->setResults(idataseries);
                   emit enableChart(true);
                }else
                    emit enableChart(false);


                emit setOutputText(QString("Result is ") + result.toString());
            }
            else
                emit enableChart(false);
                emit setOutputText(result.getErrMsg());


        }else
        {
           emit setOutputText("There's no output block added to scene");
        }

    }

