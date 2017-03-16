#include "sumexpression.h"

void SumExpression::addExpression(IExpression *expression)
{
    inputs.append(expression);
}

Data SumExpression::evaluate()
{
    Data result = Data();
    IExpression *expression = nullptr;
    foreach (expression, inputs) {
        result += expression->evaluate();
    }
    return result;
}
