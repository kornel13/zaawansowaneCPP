#include "subtractitemfactory.h"
#include "graphicsitem.h"
#include "differenceexpression.h"

SubtractItemFactory::SubtractItemFactory(int id, QObject *parent)
    : ItemFactory(QString("Difference Block"), id, parent)
{
    defaultConfig.addValue("Inputs number","2",OtherType,"^[1-4]$");
}

Item SubtractItemFactory::createItemObject(ItemConfig config)
{
    int inputs = config.getValue("Inputs number").toInt();
    return Item(new GraphicsItem(inputs,1), new DifferenceExpression(inputs) );
}
