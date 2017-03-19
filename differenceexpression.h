#ifndef DIFFERENCEEXPRESSION_H
#define DIFFERENCEEXPRESSION_H

#include "arithmeticexpression.h"

#include <QList>

class DifferenceExpression : public ArithmeticExpression
{
public:
    DifferenceExpression(unsigned inputsNumber);
    Data evaluate();
};

#endif // DIFFERENCEEXPRESSION_H
