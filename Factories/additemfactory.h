#ifndef ADDITEMFACTORY_H
#define ADDITEMFACTORY_H

#include "Factories/itemfactory.h"


/**
 * @class AddItemFactory
 * @brief Fabryka bloków sumujących
 */
class AddItemFactory : public ItemFactory
{
public:
    /**
     * @brief Kostruktor
     *
     * @param id Identyfikator fabryki bloków
     * @param parent Adres obiektu nadrzędnego
     */
    AddItemFactory(int id, QObject *parent = nullptr);

    /**
     * @brief Funkcjca, tworząca graficzną i logiczną reprezentację
     * bloku sumującego
     * @param config Konfiguracja obiektów
     * @return Item para reprezentacji bloków arytmetycznych - graficzna i logiczna
     */
    virtual Item createItemObject(ItemConfig config);
};

#endif // ADDITEMFACTORY_H
