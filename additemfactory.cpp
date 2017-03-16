#include "additemfactory.h"
#include "graphicsitem.h"
#include "sumexpression.h"

AddItemFactory::AddItemFactory(int id, QObject *parent)
    : ItemFactory(QString("Summing Block"), id, parent)
{
}

Item AddItemFactory::createItemObject(QMap<QString, QString> config)
{
    return Item(new GraphicsItem(), new SumExpression() );
}
