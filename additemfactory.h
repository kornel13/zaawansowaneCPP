#ifndef ADDITEMFACTORY_H
#define ADDITEMFACTORY_H

#include "itemfactory.h"


class AddItemFactory : public ItemFactory
{
public:
    AddItemFactory(int id, QObject *parent = nullptr);
    virtual Item createItemObject(QMap<QString, QString> config);
};

#endif // ADDITEMFACTORY_H
