#ifndef ITEM_H
#define ITEM_H

#include <QMap>
#include <QList>
#include <QIcon>
#include <QString>
#include <QObject>
#include <QPair>

#include"Common/itemconfig.h"

class IExpression;
class GraphicsItem;

using Item = QPair<GraphicsItem*, IExpression*>;

class ItemFactory : public QObject
{
public:
    ItemFactory(QString name, int id, QObject *parent = nullptr);
    virtual Item createItemObject(ItemConfig config) = 0;
    virtual bool isOutputFactory();

    int getId();
    ItemConfig getDefaultConfig() { return defaultConfig; }

private:
    int id;

protected:
    ItemConfig defaultConfig;
};

#endif // ITEM_H
