#ifndef SUMEXPRESSION_H
#define SUMEXPRESSION_H

#include "arithmeticexpression.h"

#include <QList>

class SumExpression : public ArithmeticExpression
{
public:
    SumExpression(unsigned inputsNumber);
    Data evaluate() override;
};

#endif // SUMEXPRESSION_H
