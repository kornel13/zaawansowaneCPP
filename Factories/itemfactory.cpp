#include "Factories/itemfactory.h"
#include "Common/itemnameprovider.h"

ItemFactory::ItemFactory(QString name, int id, QObject *parent)
    : QObject(parent), id(id)
{
    defaultConfig.setClassName(name);
    defaultConfig.addValue("itemName",ItemNameProvider::getNextItemName(),OtherType);
}

int ItemFactory::getId()
{
    return id;
}

bool ItemFactory::isOutputFactory()
{
    return false;
}



