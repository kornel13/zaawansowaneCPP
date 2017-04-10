#ifndef DIVISIONEXPRESSIONS_H
#define DIVISIONEXPRESSIONS_H

#include "Expressions/arithmeticexpression.h"

#include <QList>

/**
 * @class DivisionExpressions
 * @brief Klasa  reprezentująca logiczną reprezentację bloku dzielącego
 */
class DivisionExpressions : public ArithmeticExpression
{
public:
    /**
     * @brief Kostruktor
     * @param inputsNumber liczna wejść
     */
    DivisionExpressions(unsigned inputsNumber);

    /**
     * @brief Zwraca rożnice pomiędzy pierwszym wejściem, a resztą wejść
     * @return Data Wynik obliczeń
     */
    Data evaluate();
};

#endif // DIVISIONEXPRESSIONS_H
