#ifndef ADDITEMFACTORY_H
#define ADDITEMFACTORY_H

#include "Factories/itemfactory.h"


class AddItemFactory : public ItemFactory
{
public:
    AddItemFactory(int id, QObject *parent = nullptr);
    virtual Item createItemObject(ItemConfig config);
};

#endif // ADDITEMFACTORY_H
