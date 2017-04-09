#ifndef INPUTEXPRESSION_H
#define INPUTEXPRESSION_H

#include "Expressions/iexpression.h"

class InputExpression : public IExpression
{
public:
    InputExpression(Data value);
    Data evaluate();
    void addExpression(IExpression*, unsigned);
    void removeExpression(unsigned);
    void removeExpression(IExpression *expression);
    void removeAllExpressions();
    void addOutput(IExpression *expression);
    void removeOutput();

private:
    IExpression *output;
    Data value;
};

#endif // INPUTEXPRESSION_H
