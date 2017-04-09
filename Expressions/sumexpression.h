#ifndef SUMEXPRESSION_H
#define SUMEXPRESSION_H

#include "Expressions/arithmeticexpression.h"

#include <QList>

class SumExpression : public ArithmeticExpression
{
public:
    SumExpression(unsigned inputsNumber);
    Data evaluate() override;
};

#endif // SUMEXPRESSION_H
