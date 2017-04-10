#ifndef INPUTITEMFACTORY_H
#define INPUTITEMFACTORY_H

#include "Factories/itemfactory.h"

/**
 * @class InputItemFactory
 * @brief Fabryka bloków wejściowych
 */
class InputItemFactory : public ItemFactory
{
public:
    /**
     * @brief Kostruktor
     *
     * @param id Identyfikator fabryki bloków
     * @param parent Adres obiektu nadrzędnego
     */
    InputItemFactory(int id, QObject *parent = nullptr);

    /**
     * @brief Funkcjca, tworząca graficzną i logiczną reprezentację
     * bloku wejściowego
     * @param config Konfiguracja obiektów
     * @return Item para reprezentacji bloków arytmetycznych - graficzna i logiczna
     */
    virtual Item createItemObject(ItemConfig config);
};

#endif // INPUTITEMFACTORY_H
