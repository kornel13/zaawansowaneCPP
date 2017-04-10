#ifndef MAPPER_H
#define MAPPER_H

#include <QMap>

class ItemFactory;
class IExpression;
class GraphicsItem;
class QAction;

/**
 * @enum Główne stany sceny
 */
enum Actions { Move, Insert };

/**
 * @class Mapper
 * @brief Uniwesalna klasa statyczna używana do mapowania
 */
class Mapper
{
public:
    /**
     * @brief Generuje ID dla fabryk bloków abstrakcyjnych
     * @return int
     */
    static int getItemFactoryId();

    static QMap<int,ItemFactory*> idToItemFactoryMap; /**< Mapa Id na adres Fabryki Bloków */
    static QMap<QAction*, Actions> actionToEnumMap; /**< Mapuje adresy obiektów Qactions na enuma Actions */
    static QMap<GraphicsItem*, IExpression*> graphicsToExpessionMap; /**< Mapuje graficzną reprezentację bloku na logiczną */


private:
    Mapper() = delete;
    static int itemFactoryId;


};

#endif // MAPPER_H
