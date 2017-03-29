#ifndef INPUTEXPRESSION_H
#define INPUTEXPRESSION_H

#include "iexpression.h"

class InputExpression : public IExpression
{
public:
    InputExpression(Data value);
    Data evaluate();
    void addExpression(IExpression*, unsigned);
    void removeExpression(unsigned);

private:
    Data value;
};

#endif // INPUTEXPRESSION_H
