#ifndef SUBTRACTITEMFACTORY_H
#define SUBTRACTITEMFACTORY_H

#include "itemfactory.h"

class SubtractItemFactory : public ItemFactory
{
public:
    SubtractItemFactory(int id, QObject *parent = nullptr);
    virtual Item createItemObject(QMap<QString, QString> config);
};

#endif // SUBTRACTITEMFACTORY_H
