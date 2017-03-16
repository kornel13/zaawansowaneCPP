#include "differenceexpression.h"

void DifferenceExpression::addExpression(IExpression *expression)
{
    inputs.append(expression);
}

Data DifferenceExpression::evaluate()
{
    Data result = Data();
    IExpression *expression = nullptr;
    foreach (expression, inputs) {
        result -= expression->evaluate();
    }
    return result;
}
