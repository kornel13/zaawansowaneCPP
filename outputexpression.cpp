#include "outputexpression.h"
#include <QDebug>

OutputExpression::OutputExpression()
{
    input = nullptr;
}

void OutputExpression::addExpression(IExpression *expression, unsigned)
{
    input = expression;
    expression->addOutput(this);
}

void OutputExpression::removeExpression(unsigned)
{
    if(input) input->removeOutput();
    input = nullptr;
}

void OutputExpression::removeExpression(IExpression *)
{
    if(input) input->removeOutput();
    input = nullptr;
}

void OutputExpression::removeAllExpressions()
{
    removeExpression(nullptr);
}

Data OutputExpression::evaluate()
{
    Data errorData = validateInputs();
    if(!errorData.isValid())
        return errorData;
    return input->evaluate();
}

Data OutputExpression::validateInputs()
{
    Data data(0);
    if(input == nullptr)
        data.setErrorMsg("No input");
    return data;
}

bool OutputExpression::isOutput()
{
    return true;
}

void OutputExpression::addOutput(IExpression *expression)
{
}

void OutputExpression::removeOutput()
{
}


