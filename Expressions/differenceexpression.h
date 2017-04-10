#ifndef DIFFERENCEEXPRESSION_H
#define DIFFERENCEEXPRESSION_H

#include "Expressions/arithmeticexpression.h"

#include <QList>

/**
 * @class DifferenceExpression
 * @brief Klasa  reprezentująca logiczną reprezentację bloku odejmującego
 */
class DifferenceExpression : public ArithmeticExpression
{
public:
    /**
     * @brief Kostruktor
     * @param inputsNumber liczna wejść
     */
    DifferenceExpression(unsigned inputsNumber);

    /**
     * @brief Zwraca rożnice pomiędzy pierwszym wejściem, a resztą wejść
     * @return Data Wynik obliczeń
     */
    Data evaluate();
};

#endif // DIFFERENCEEXPRESSION_H
