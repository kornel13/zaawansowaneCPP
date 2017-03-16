#include "itemfactory.h"

ItemFactory::ItemFactory(QString name, int id, QObject *parent)
    : QObject(parent), name(name), id(id)
{
    AddCommonAttributes();
}

int ItemFactory::getId()
{
    return id;
}

QIcon ItemFactory::getIcon()
{
    return icon;
}
QString ItemFactory::getName()
{
    return name;
}

void ItemFactory::AddCommonAttributes()
{
    attributes.append("InputsNumber");
}

void ItemFactory::setIcon(QIcon &icon)
{
    this->icon = icon;
}

