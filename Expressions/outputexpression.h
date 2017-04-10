#ifndef OUTPUTEXPRESSION_H
#define OUTPUTEXPRESSION_H

#include "Expressions/iexpression.h"

/**
 * @class OutputExpression
 * @brief Klasa reprezentująca blok wejściowy.
 * Korzeń drzewa wyrażeń rozpoczynajacy wszystkie obliczenia
 */
class OutputExpression : public IExpression
{
public:
    OutputExpression();
    /**
     * @brief Rozpoczyna obliczenia zbudowanego drzewa wyrażeń
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
     * @brief Zwraca czy wyrażenie reprezuntuje wyjście (ostatni element) obliczeń
     * @return bool
     */
    virtual bool isOutput();

    /**
     * @brief Dodaje referencje na wyrażenie do wyjścia systemu
     * @param expression
     */
    virtual void addOutput(IExpression *expression);

    /**
     * @brief Usuwa refencję na wyrażenie na wyjściu systemu
     */
    virtual void removeOutput();

private:
    Data validateInputs();
    IExpression *input;
};

#endif // OUTPUTEXPRESSION_H
