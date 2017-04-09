#include "Expressions/sumexpression.h"
#include <QDebug>

SumExpression::SumExpression(unsigned inputsNumber)
    : ArithmeticExpression(inputsNumber)
{
}

Data SumExpression::evaluate()
{
    Data tmp = validateInputs();
    if(!tmp.isValid())
        return tmp;

    Data result = Data(0);
    for (int i=0; i<inputs.size(); ++i)
    {
        tmp = inputs[i]->evaluate();
        if(!result.isValid()) return tmp;

        result += tmp;
    }
    return result;
}


