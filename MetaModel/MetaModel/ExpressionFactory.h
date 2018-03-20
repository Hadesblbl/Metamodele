#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

class ExpressionFactory{
    public:
       Expression Hold(Expression);
       Expression newUnary(UnaryExpression,Expression);
       Expression newBinary(BinaryExpression,Expression,Expression);

    private:
        Expression * memory;
}

public Expression ExpressionFactory::newUnary(UnaryExpression ope,Expression o){
    return new UnaryExpressionModel(ope,o);
}

public Expression ExpressionFactory::newBinary(BinaryExpression ope,Expression l,Expression r){
    return new BinaryExpressionModel(ope,l, r);
}
#endif