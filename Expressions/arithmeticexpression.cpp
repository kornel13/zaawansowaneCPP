#include "Expressions/arithmeticexpression.h"

ArithmeticExpression::ArithmeticExpression(unsigned inputsNumber)
{
    inputs.resize(inputsNumber);
    for(int i=0; i < inputs.size(); ++i) inputs[i] = nullptr;
    output = nullptr;
}

void ArithmeticExpression::addExpression(IExpression *expression, unsigned index)
{
    inputs[index] = expression;
    expression->addOutput(this);
}

void ArithmeticExpression::removeExpression(unsigned index)
{
    inputs[index]->removeOutput();
    inputs[index] = nullptr;
}

void ArithmeticExpression::removeExpression(IExpression *expression)
{
    for(int i=0; i < inputs.size(); ++i)
        if(inputs[i] == expression) removeExpression(i);
}

void ArithmeticExpression::removeAllExpressions()
{
    for(int i=0; i < inputs.size(); ++i)
        if(inputs[i]) removeExpression(i);
    if(output) output->removeExpression(this);
}

void ArithmeticExpression::addOutput(IExpression *expression)
{
    output = expression;
}

void ArithmeticExpression::removeOutput()
{
    output = nullptr;
}

Data ArithmeticExpression::validateInputs()
{
    Data data(0);;
    if(output == nullptr) data.setErrorMsg("No output");
    for(int i=0; i < inputs.size(); ++i)
    {
        if(inputs[i] == nullptr)
        {
            data.setErrorMsg("No input art");
            break;
        }
    }
    return data;
}
