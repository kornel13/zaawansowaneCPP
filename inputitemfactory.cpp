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
    Data value(0);
    value.fromString(config.getValue("Value"));

    return Item(new GraphicsItem(0,1), new InputExpression(value) );
}
