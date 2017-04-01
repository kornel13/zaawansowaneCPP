#include "outputitemfactory.h"
#include "outputexpression.h"
#include "graphicsitem.h"

OutputItemFactory::OutputItemFactory(int id, QObject *parent)
    : ItemFactory(QString("Output Block"), id, parent)
{
}

Item OutputItemFactory::createItemObject(ItemConfig config)
{
    auto className = config.getClassName();
    return Item(new GraphicsItem(1,0,className,"CALC END","="), new OutputExpression() );
}

bool OutputItemFactory::isOutputFactory()
{
    return true;
}

