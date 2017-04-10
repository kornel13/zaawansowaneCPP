#ifndef MULTIPLYFACTORY_H
#define MULTIPLYFACTORY_H

#include "Factories/itemfactory.h"

/**
 * @class MultiplyFactory
 * @brief Fabryka bloków mnożących
 */
class MultiplyFactory : public ItemFactory
{
public:
    /**
     * @brief Kostruktor
     *
     * @param id Identyfikator fabryki bloków
     * @param parent Adres obiektu nadrzędnego
     */
    MultiplyFactory(int id, QObject *parent = nullptr);

    /**
     * @brief Funkcjca, tworząca graficzną i logiczną reprezentację
     * bloku mnożącego
     * @param config Konfiguracja obiektów
     * @return Item para reprezentacji bloków arytmetycznych - graficzna i logiczna
     */
    virtual Item createItemObject(ItemConfig config);
};

#endif // MULTIPLYFACTORY_H
