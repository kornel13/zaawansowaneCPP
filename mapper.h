#ifndef MAPPER_H
#define MAPPER_H

#include <QMap>

class ItemFactory;
class IExpression;
class GraphicsItem;
class QAction;

enum Actions { Move, Insert };

class Mapper
{
public:
    static int getItemFactoryId();

    static QMap<int,ItemFactory*> idToItemFactoryMap;
    static QMap<QAction*, Actions> actionToEnumMap;
    static QMap<GraphicsItem*, IExpression*> graphicsToExpessionMap;


private:
    Mapper() = delete;
    static int itemFactoryId;


};

#endif // MAPPER_H
