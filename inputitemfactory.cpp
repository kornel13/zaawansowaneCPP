#include "inputitemfactory.h"
#include "graphicsitem.h"
#include "inputexpression.h"

InputItemFactory::InputItemFactory(int id, QObject *parent)
    : ItemFactory(QString("Input Block"), id, parent)
{

}

Item InputItemFactory::createItemObject(QMap<QString, QString> config)
{
    return Item(new GraphicsItem(0,1), new InputExpression() );
}
