#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

class ExpressionFactory{
    public:
       Expression Hold(Expression);
       Expression newUnary(UnaryExpression,Expression);
       Expression newBinary(BinaryExpression,Expression,Expression);
}
#endif