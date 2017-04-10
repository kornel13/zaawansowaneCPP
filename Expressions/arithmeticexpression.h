#ifndef ARITHMETICEXPRESSION_H
#define ARITHMETICEXPRESSION_H

#include "Expressions/iexpression.h"
#include <QVector>
#include "Data/genericData.h"

/**
 * @class ArithmeticExpression
 * @brief Klasa abstrakcyjna reprezentujący zachowanie logiczych bloków wykonujących
 * działania arytmetyczne. Dostarcza funkcjonialności wspólnych dla wszystkich blokow tego typu.
 */
class ArithmeticExpression : public IExpression
{
public:
    /**
     * @brief Kostruktor
     * @param inputsNumber liczna wejść
     */
    ArithmeticExpression(unsigned inputsNumber);

    /**
     * @brief Główna funkcja logicznego bloku arytmetycznego
     * Oblicza wertość wyjścia na podstawie wartości wejściowych
     * @return Data Wynik obliczeń
     */
    virtual Data evaluate();

    /**
     * @brief Dodaje wyrażanie do wejścia o przekazanym indeksie
     * @param expression Adres wyrażnia
     * @param index Indeks wejścia
     */
    virtual void addExpression(IExpression *expression, unsigned index);

    /**
     * @brief Usuwa wyrażanie z wejścia o przekazanym indeksie
     * @param index Indeks wejścia
     */
    virtual void removeExpression(unsigned index);

    /**
     * @brief Usuwa wyrażanie z wejścia o przekazanym adresie
     * @param expression Adres wyrażnia
     */
    virtual void removeExpression(IExpression *expression);

    /**
     * @brief Usuwa wszytkie przyłączone wyrażenia
     */
    virtual void removeAllExpressions();

    /**
     * @brief Dodaje referencje na wyrażenie do wyjścia systemu
     * @param expression
     */
    virtual void addOutput(IExpression *expression);

    /**
     * @brief Usuwa refencję na wyrażenie na wyjściu systemu
     */
    virtual void removeOutput();

protected:
    Data validateInputs();
    QVector<IExpression*> inputs;
    IExpression* output;
};

#endif // ARITHMETICEXPRESSION_H
