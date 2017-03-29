#include "itemfactory.h"

ItemFactory::ItemFactory(QString name, int id, QObject *parent)
    : QObject(parent), id(id)
{
    defaultConfig.setClassName(name);
    defaultConfig.addValue("itemName","",OtherType);
}

int ItemFactory::getId()
{
    return id;
}

