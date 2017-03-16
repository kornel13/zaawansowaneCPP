#include "mapper.h"
#include "itemfactory.h"
#include <QAction>

int Mapper::itemFactoryId = 0;
QMap<int,ItemFactory*> Mapper::idToItemFactoryMap = QMap<int,ItemFactory*>();
QMap<QAction*, Actions> Mapper::actionToEnumMap = QMap<QAction*, Actions>();
QMap<GraphicsItem*, IExpression*> Mapper::graphicsToExpessionMap  = QMap<GraphicsItem*, IExpression*>();

int Mapper::getItemFactoryId()
{
    return itemFactoryId++;
}
