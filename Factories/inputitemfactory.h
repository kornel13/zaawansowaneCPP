#ifndef INPUTITEMFACTORY_H
#define INPUTITEMFACTORY_H

#include "Factories/itemfactory.h"

class InputItemFactory : public ItemFactory
{
public:
    InputItemFactory(int id, QObject *parent = nullptr);
    virtual Item createItemObject(ItemConfig config);
};

#endif // INPUTITEMFACTORY_H
