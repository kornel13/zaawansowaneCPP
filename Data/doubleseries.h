#ifndef DOUBLESERIES_H
#define DOUBLESERIES_H

#include <type_traits>
#include <list>
#include <iostream>

#include "Data/idataseries.h"


/**
 * @class DoubleSeries
 * @brief Reprezentuje seria danych tyu double
 */
class DoubleSeries : public IDataSeries
{
public:
    /**
     * @brief Kostruktor domyślny
     */
    DoubleSeries(): DoubleSeries(0.0){}

    /**
     * @brief Konstruktor
     * @param val pierwsza wartość w serii danych
     */
    DoubleSeries(double val);

    /**
     * @brief Operator dodawania
     */
    DoubleSeries operator + (DoubleSeries other);

    /**
     * @brief Operator odejmowania
     */
    DoubleSeries operator - (DoubleSeries other);

    /**
     * @brief Operator mnożenia
     */
    DoubleSeries operator * (DoubleSeries other);

    /**
     * @brief Operator dzielenia
     */
    DoubleSeries operator / (DoubleSeries other);

    /**
     * @brief Operator dodawania i przypisania
     */
    void operator += (DoubleSeries other);

    /**
     * @brief Operator odejmowania i przypisania
     */
    void operator -= (DoubleSeries other);

    /**
     * @brief Operator mnożenia i przypisania
     */
    void operator *= (DoubleSeries other);

    /**
     * @brief Operator dzielenia i przypisania
     */
    void operator /= (DoubleSeries other);

    /**
     * @brief Przeładowanie streamu wyjściowego
     * @param s Referencja streamu wyjściowego
     * @param p Referencja na obiekt DoubleSeries
     * @return std::ostream &operator
     */
    friend std::ostream& operator<<(std::ostream& s, const DoubleSeries& p);

    /**
     * @brief Przeładowanie streamu wejściowego
     * @param s Referencja streamu wejściowego
     * @param p Referencja na obiekt DoubleSeries
     * @return std::istream &operator
     */
    friend std::istream& operator>>(std::istream& s, DoubleSeries& p);

    /**
     * @brief Getter listy danych
     * @return std::list<double>
     */
    std::list<double> getList() override;

private:
    std::list<double> valueList;
};

/**
 * @brief
 *
 */
namespace std
{
    template<>

    struct is_arithmetic<DoubleSeries>{
      static const bool value = true;
    };
}




#endif // DOUBLESERIES_H
