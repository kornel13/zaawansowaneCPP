#include "Factories/multiplyfactory.h"
#include "GraphicsItems/graphicsitem.h"
#include "Expressions/multiplicationexpression.h"

MultiplyFactory::MultiplyFactory(int id, QObject *parent)
    : ItemFactory(QString("Multiplying Block"), id, parent)
{
    defaultConfig.addValue("Inputs number","2",OtherType,"^[1-4]$");
}

Item MultiplyFactory::createItemObject(ItemConfig config)
{
    auto className = config.getClassName();
    auto itemName = config.getValue("itemName");
    int inputs = config.getValue("Inputs number").toInt();
    return Item(new GraphicsItem(inputs,1,className,itemName,QString("*")), new MultiplicationExpression(inputs) );
}
