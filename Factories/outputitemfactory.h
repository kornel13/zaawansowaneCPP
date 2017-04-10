#ifndef OUTPUTITEMFACTORY_H
#define OUTPUTITEMFACTORY_H

#include "Factories/itemfactory.h"

/**
 * @class OutputItemFactory
 * @brief Fabryka bloków wyjściowych
 */
class OutputItemFactory : public ItemFactory
{
public:
    /**
     * @brief Kostruktor
     *
     * @param id Identyfikator fabryki bloków
     * @param parent Adres obiektu nadrzędnego
     */
    OutputItemFactory(int id, QObject *parent = nullptr);

    /**
     * @brief Funkcjca, tworząca graficzną i logiczną reprezentację
     * bloku wyjściowego
     * @param config Konfiguracja obiektów
     * @return Item para reprezentacji bloków arytmetycznych - graficzna i logiczna
     */
    virtual Item createItemObject(ItemConfig config) override;

    /**
     * @brief Zwraca czy fabryka konstruuje bloki wyjściowe
     * @return bool
     */
    bool isOutputFactory() override;

};

#endif // OUTPUTITEMFACTORY_H
