#ifndef IDATASERIES_H
#define IDATASERIES_H

#include <list>

/**
 * @class IDataSeries
 * @brief Iterfejs reprzentujący serie daycn typu double.
 * Używany przy plotowaniu wykresu
 */
class IDataSeries
{
public:
    /**
     * @brief Zwraca serię danych w postaci listy elementów typu double
     * @return std::list<double>
     */
    virtual std::list<double> getList() = 0;
};


#endif // IDATASERIES_H
