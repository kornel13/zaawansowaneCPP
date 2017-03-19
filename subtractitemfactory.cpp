#include "subtractitemfactory.h"
#include "graphicsitem.h"
#include "differenceexpression.h"

SubtractItemFactory::SubtractItemFactory(int id, QObject *parent)
    : ItemFactory(QString("Difference Block"), id, parent)
{

}

Item SubtractItemFactory::createItemObject(QMap<QString, QString> config)
{
    return Item(new GraphicsItem(2,1), new DifferenceExpression(2) );
}
