#ifndef IEXPRESSION_H
#define IEXPRESSION_H

#include "Data/genericData.h"

/**
 * @class IExpression
 * @brief Interfejs reprezentujący zachowanie logiczych bloków arytmetycznych
 */
class IExpression
{
public:
    /**
     * @brief Główna funkcja logicznego bloku arytmetycznego
     * Oblicza wertość wyjścia na podstawie wartości wejściowych
     * @return Data Wynik obliczeń
     */
    virtual Data evaluate() = 0;

    /**
     * @brief Dodaje wyrażanie do wejścia o przekazanym indeksie
     * @param expression Adres wyrażnia
     * @param index Indeks wejścia
     */
    virtual void addExpression(IExpression *expression, unsigned index) = 0;

    /**
     * @brief Usuwa wyrażanie z wejścia o przekazanym indeksie
     * @param index Indeks wejścia
     */
    virtual void removeExpression(unsigned index) = 0;

    /**
     * @brief Usuwa wyrażanie z wejścia o przekazanym adresie
     * @param expression Adres wyrażnia
     */
    virtual void removeExpression(IExpression *expression) = 0;

    /**
     * @brief Usuwa wszytkie przyłączone wyrażenia
     */
    virtual void removeAllExpressions() = 0;

    /**
     * @brief Zwraca czy wyrażenie reprezuntuje wyjście (ostatni element) obliczeń
     * @return bool
     */
    virtual bool isOutput() { return false; }

    /**
     * @brief Dodaje referencje na wyrażenie do wyjścia systemu
     * @param expression
     */
    virtual void addOutput(IExpression *expression) = 0;

    /**
     * @brief Usuwa refencję na wyrażenie na wyjściu systemu
     */
    virtual void removeOutput() = 0;

    /**
     * @brief Destruktor
     */
    virtual ~IExpression(){};
};

#endif // IEXPRESSION_H
