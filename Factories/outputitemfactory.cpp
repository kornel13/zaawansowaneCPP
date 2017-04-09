#include "Factories/outputitemfactory.h"
#include "Expressions/outputexpression.h"
#include "GraphicsItems/graphicsitem.h"

OutputItemFactory::OutputItemFactory(int id, QObject *parent)
    : ItemFactory(QString("Output Block"), id, parent)
{
}

Item OutputItemFactory::createItemObject(ItemConfig config)
{
    auto className = config.getClassName();
    auto itemName = config.getValue("itemName");
    return Item(new GraphicsItem(1,0,className,itemName,"="), new OutputExpression() );
}

bool OutputItemFactory::isOutputFactory()
{
    return true;
}

