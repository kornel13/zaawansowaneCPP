#include "arithmeticexpression.h"

ArithmeticExpression::ArithmeticExpression(unsigned inputsNumber)
{
    inputs.resize(inputsNumber);
}

void ArithmeticExpression::addExpression(IExpression *expression, unsigned index)
{
    inputs[index] = expression;
}

void ArithmeticExpression::removeExpression(unsigned index)
{
    inputs[index] = nullptr;
}
