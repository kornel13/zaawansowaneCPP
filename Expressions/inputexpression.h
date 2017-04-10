#ifndef INPUTEXPRESSION_H
#define INPUTEXPRESSION_H

#include "Expressions/iexpression.h"

/**
 * @class InputExpression
 * @brief Klasa reprezentująca blok wejściowy.
 */
class InputExpression : public IExpression
{
public:
    /**
     * @brief Kostruktor
     * @param value Zapisana wartość wyrażenia
     */
    InputExpression(Data value);

    /**
     * @brief Zwraca zapisane wartości na wyjście
     * @return Data Zapisane wartości
     */
    Data evaluate();

    /**
     * @brief Dodaje wyrażanie do wejścia o przekazanym indeksie
     * @param expression Adres wyrażnia
     * @param index Indeks wejścia
     */
    void addExpression(IExpression *expression, unsigned index);

    /**
     * @brief Usuwa wyrażanie z wejścia o przekazanym indeksie
     * @param index Indeks wejścia
     */
    void removeExpression(unsigned index);

    /**
     * @brief Usuwa wyrażanie z wejścia o przekazanym adresie
     * @param expression Adres wyrażnia
     */
    void removeExpression(IExpression *expression);

    /**
     * @brief Usuwa wszytkie przyłączone wyrażenia
     */
    void removeAllExpressions();

    /**
     * @brief Dodaje referencje na wyrażenie do wyjścia systemu
     * @param expression
     */
    void addOutput(IExpression *expression);

    /**
     * @brief Usuwa refencję na wyrażenie na wyjściu systemu
     */
    void removeOutput();

private:
    IExpression *output;
    Data value;
};

#endif // INPUTEXPRESSION_H
