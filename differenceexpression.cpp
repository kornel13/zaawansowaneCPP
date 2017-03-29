#include "differenceexpression.h"

DifferenceExpression::DifferenceExpression(unsigned inputsNumber)
    : ArithmeticExpression(inputsNumber)
{
}

Data DifferenceExpression::evaluate()
{
    Data result = Data(0);
    IExpression *expression = nullptr;
    foreach (expression, inputs) {
        result -= expression->evaluate();
    }
    return result;
}
