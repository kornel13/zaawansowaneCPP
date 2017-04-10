#include "multiplicationexpression.h"

MultiplicationExpression::MultiplicationExpression(unsigned inputsNumber)
    : ArithmeticExpression(inputsNumber)
{
}

Data MultiplicationExpression::evaluate()
{
    Data tmp = validateInputs();
    if(!tmp.isValid())
        return tmp;

    Data result = Data(1);
    for (int i=0; i<inputs.size(); ++i)
    {
        tmp = inputs[i]->evaluate();
        if(!result.isValid()) return tmp;

        result *= tmp;
    }
    return result;
}
