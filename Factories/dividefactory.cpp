#include "Factories/dividefactory.h"
#include "GraphicsItems/graphicsitem.h"
#include "Expressions/divisionexpressions.h"

DivideFactory::DivideFactory(int id, QObject *parent)
    : ItemFactory(QString("Dividing Block"), id, parent)
{
    defaultConfig.addValue("Inputs number","2",OtherType,"^[1-4]$");
}

Item DivideFactory::createItemObject(ItemConfig config)
{
    auto className = config.getClassName();
    auto itemName = config.getValue("itemName");
    int inputs = config.getValue("Inputs number").toInt();
    return Item(new GraphicsItem(inputs,1,className,itemName,QString("/")), new DivisionExpressions(inputs) );
}
