#include "outputitemfactory.h"
#include "outputexpression.h"
#include "graphicsitem.h"

OutputItemFactory::OutputItemFactory(int id, QObject *parent)
    : ItemFactory(QString("Output Block"), id, parent)
{
}

Item OutputItemFactory::createItemObject(ItemConfig config)
{
    return Item(new GraphicsItem(1,0), new OutputExpression() );
}

bool OutputItemFactory::isOutputFactory()
{
    return true;
}

