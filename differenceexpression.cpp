#include "differenceexpression.h"

DifferenceExpression::DifferenceExpression(unsigned inputsNumber)
    : ArithmeticExpression(inputsNumber)
{
}

Data DifferenceExpression::evaluate()
{
    Data result = inputs.first()->evaluate();
    for (int i=1; i<inputs.size(); ++i) {
        result -= inputs[i]->evaluate();
    }
    return result;
}
