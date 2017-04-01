#include "inputitemfactory.h"
#include "graphicsitem.h"
#include "inputexpression.h"
#include "data.h"

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

    return Item(new GraphicsItem(0,1,className,itemName,stringValue), new InputExpression(value) );
}
