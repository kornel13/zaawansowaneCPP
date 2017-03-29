#ifndef OUTPUTITEMFACTORY_H
#define OUTPUTITEMFACTORY_H

#include "itemfactory.h"

class OutputItemFactory : public ItemFactory
{
public:
    OutputItemFactory(int id, QObject *parent = nullptr);
    virtual Item createItemObject(ItemConfig config);

};

#endif // OUTPUTITEMFACTORY_H
