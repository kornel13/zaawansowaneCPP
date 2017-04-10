#ifndef SUBTRACTITEMFACTORY_H
#define SUBTRACTITEMFACTORY_H

#include "Factories/itemfactory.h"

/**
 * @class SubtractItemFactory
 * @brief Fabryka bloków odejmujących
 */
class SubtractItemFactory : public ItemFactory
{
public:
    /**
     * @brief Kostruktor
     *
     * @param id Identyfikator fabryki bloków
     * @param parent Adres obiektu nadrzędnego
     */
    SubtractItemFactory(int id, QObject *parent = nullptr);

    /**
     * @brief Funkcjca, tworząca graficzną i logiczną reprezentację
     * bloku odejmującego
     * @param config Konfiguracja obiektów
     * @return Item para reprezentacji bloków arytmetycznych - graficzna i logiczna
     */
    virtual Item createItemObject(ItemConfig config);
};

#endif // SUBTRACTITEMFACTORY_H
