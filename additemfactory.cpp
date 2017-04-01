#include "additemfactory.h"
#include "graphicsitem.h"
#include "sumexpression.h"

AddItemFactory::AddItemFactory(int id, QObject *parent)
    : ItemFactory(QString("Summing Block"), id, parent)
{
    defaultConfig.addValue("Inputs number","2",OtherType,"^[1-4]$");
}

Item AddItemFactory::createItemObject(ItemConfig config)
{
    auto className = config.getClassName();
    auto itemName = config.getValue("itemName");
    int inputs = config.getValue("Inputs number").toInt();
    return Item(new GraphicsItem(inputs,1,className,itemName,QString("+")), new SumExpression(inputs) );
}
