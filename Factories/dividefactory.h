#ifndef DIVIDEFACTORY_H
#define DIVIDEFACTORY_H

#include "Factories/itemfactory.h"


/**
 * @class DivideFactory
 * @brief Fabryka bloków dzielących
 */
class DivideFactory : public ItemFactory
{
public:
    /**
     * @brief Kostruktor
     *
     * @param id Identyfikator fabryki bloków
     * @param parent Adres obiektu nadrzędnego
     */
    DivideFactory(int id, QObject *parent = nullptr);

    /**
     * @brief Funkcjca, tworząca graficzną i logiczną reprezentację
     * bloku dzielącego
     * @param config Konfiguracja obiektów
     * @return Item para reprezentacji bloków arytmetycznych - graficzna i logiczna
     */
    virtual Item createItemObject(ItemConfig config);
};

#endif // DIVIDEFACTORY_H
