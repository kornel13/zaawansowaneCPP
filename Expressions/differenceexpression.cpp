#include "Expressions/differenceexpression.h"

DifferenceExpression::DifferenceExpression(unsigned inputsNumber)
    : ArithmeticExpression(inputsNumber)
{
}

Data DifferenceExpression::evaluate()
{
    Data tmp = validateInputs();
    if(!tmp.isValid())
        return tmp;

    Data result = inputs.first()->evaluate();
    if(!result.isValid()) return result;

    for (int i=1; i<inputs.size(); ++i)
    {
        tmp = inputs[i]->evaluate();
        if(!result.isValid()) return tmp;

        result -= tmp;
    }
    return result;
}
