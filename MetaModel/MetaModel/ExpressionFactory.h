#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

#include "Expression.h"
#include "UnaryExpression.h"
#include "BinaryExpression.h"

template<class T>
class ExpressionFactory{
    public:
       Expression<T> Hold(Expression<T>);
       Expression<T> newUnary(UnaryExpression<T>,Expression<T>);
       Expression<T> newBinary(BinaryExpression<T>,Expression<T>,Expression<T>);

    private:
        Expression<T> * memory;
};

template<class T>
public Expression<T> ExpressionFactory<T>::Hold(Expression<T> exp){
    memory[strlen(memory)]=exp;//a corriger
    return exp;
}

template<class T>
public Expression<T> ExpressionFactory<T>::newUnary(UnaryExpression<T> ope,Expression<T> o){
    return new UnaryExpressionModel(ope,o);
}

template<class T>
public Expression<T> ExpressionFactory<T>::newBinary(BinaryExpression<T> ope,Expression<T> l,Expression<T> r){
    return new BinaryExpressionModel(ope,l, r);
}

#endif