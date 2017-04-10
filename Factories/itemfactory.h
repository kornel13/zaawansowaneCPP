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

/**
 * @brief Alias na pare: graficzna i logiczna reprezentacja bloków
 */
using Item = QPair<GraphicsItem*, IExpression*>;

/**
 * @class ItemFactory
 * @brief Fabryka abstrakcyjna wszystkich tworzonych bloków w aplikacji
 */
class ItemFactory : public QObject
{
public:
    /**
     * @brief Kostruktor
     *
     * @param name Nazwa klasy bloków
     * @param id Identyfikator fabryki bloków
     * @param parent Adres obiektu nadrzędnego
     */
    ItemFactory(QString name, int id, QObject *parent = nullptr);

    /**
     * @brief Abstrakcyjna funkcjca, tworząca pare obiektów: graficzna i logiczna reprezentacja
     * bloków arytmetycznych
     * @param config Konfiguracja obiektów
     * @return Item para reprezentacji bloków arytmetycznych - graficzna i logiczna
     */
    virtual Item createItemObject(ItemConfig config) = 0;

    /**
     * @brief Zwraca czy fabryka konstruuje bloki wyjściowe
     * @return bool
     */
    virtual bool isOutputFactory();

    /**
     * @brief Getter id fabryki bloków
     * @return int
     */
    int getId();

    /**
     * @brief Domyślna konfiguracja bloku
     * @return ItemConfig
     */
    ItemConfig getDefaultConfig() { return defaultConfig; }

private:
    int id;

protected:
    ItemConfig defaultConfig;
};

#endif // ITEM_H
