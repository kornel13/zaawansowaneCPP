#ifndef SUMEXPRESSION_H
#define SUMEXPRESSION_H

#include "Expressions/arithmeticexpression.h"

#include <QList>

/**
 * @class SumExpression
 * @brief Klasa  reprezentująca logiczną reprezentację bloku sumującego
 */
class SumExpression : public ArithmeticExpression
{
public:
    /**
     * @brief Kostruktor
     * @param inputsNumber liczna wejść
     */
    SumExpression(unsigned inputsNumber);

    /**
     * @brief Zwraca sumę wartości na wejścia do wyjścia
     * @return Data Wynik obliczeń
     */
    Data evaluate() override;
};

#endif // SUMEXPRESSION_H
