#include "sumexpression.h"
#include <QDebug>

SumExpression::SumExpression(unsigned inputsNumber)
    : ArithmeticExpression(inputsNumber)
{
}

Data SumExpression::evaluate()
{
    qDebug()<<"SumExpression::evaluate jestem\n";

    Data result = Data(0);
    IExpression *expression = nullptr;
    foreach (expression, inputs) {
        result += expression->evaluate();
    }
    return result;
}


