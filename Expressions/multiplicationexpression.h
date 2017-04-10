#ifndef MULTIPLICATIONEXPRESSION_H
#define MULTIPLICATIONEXPRESSION_H


#include "Expressions/arithmeticexpression.h"

#include <QList>

/**
 * @class MultiplicationExpression
 * @brief Klasa  reprezentująca logiczną reprezentację bloku mnożącego
 */
class MultiplicationExpression : public ArithmeticExpression
{
public:
    /**
     * @brief Kostruktor
     * @param inputsNumber liczna wejść
     */
    MultiplicationExpression(unsigned inputsNumber);

    /**
     * @brief Zwraca sumę wartości na wejścia do wyjścia
     * @return Data Wynik obliczeń
     */
    Data evaluate() override;
};

#endif // MULTIPLICATIONEXPRESSION_H
