#ifndef OUTPUTEXPRESSION_H
#define OUTPUTEXPRESSION_H

#include "Expressions/iexpression.h"

class OutputExpression : public IExpression
{
public:
    OutputExpression();
    Data evaluate();
    void addExpression(IExpression *expression, unsigned);
    void removeExpression(unsigned);
    void removeExpression(IExpression *);
    void removeAllExpressions();
    bool isOutput() override;
    void addOutput(IExpression *expression);
    void removeOutput();

private:
    Data validateInputs();
    IExpression *input;
};

#endif // OUTPUTEXPRESSION_H
