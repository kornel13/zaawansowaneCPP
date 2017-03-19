#ifndef INPUTITEMFACTORY_H
#define INPUTITEMFACTORY_H

#include "itemfactory.h"

class InputItemFactory : public ItemFactory
{
public:
    InputItemFactory(int id, QObject *parent = nullptr);
    virtual Item createItemObject(QMap<QString, QString> config);
};

#endif // INPUTITEMFACTORY_H
