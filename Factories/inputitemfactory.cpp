#include "Factories/inputitemfactory.h"
#include "GraphicsItems/graphicsitem.h"
#include "Expressions/inputexpression.h"
#include "Data/genericData.h"

InputItemFactory::InputItemFactory(int id, QObject *parent)
    : ItemFactory(QString("Input Block"), id, parent)
{
    defaultConfig.addValue("Value","0",DataType);
}

Item InputItemFactory::createItemObject(ItemConfig config)
{
    auto className = config.getClassName();
    auto itemName = config.getValue("itemName");
    auto stringValue = config.getValue("Value");

    Data value(0);
    value.fromString(stringValue);

    return Item(new GraphicsItem(0,1,className,itemName,"In"), new InputExpression(value) );
}
