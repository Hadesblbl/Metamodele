#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

#include "Expression.h"
#include "UnaryExpression.h"
#include "BinaryExpression.h"
#include "NaryExpression.h"

template<class T>
class ExpressionFactory{
    public:
		ExpressionFactory() {};
		Expression<T> Hold(Expression<T>&);
		Expression<T> newUnary(UnaryExpression<T>&, Expression<T>&);
		Expression<T> newBinary(BinaryExpression<T>&, Expression<T>&, Expression<T>&);
		Expression<T> newNary(NaryExpression<T>&, /*liste d'expression*/);

    private:
        Expression<T> * memory;
};

template<class T>
	Expression<T> ExpressionFactory<T>::Hold(Expression<T> exp){
    memory[strlen(memory)]=exp;//a corriger
    return exp;
}

template<class T>
	Expression<T> ExpressionFactory<T>::newUnary(UnaryExpression<T> ope,Expression<T> o){
    return new UnaryExpressionModel(ope,o);
}

template<class T>
	Expression<T> ExpressionFactory<T>::newBinary(BinaryExpression<T> ope,Expression<T> l,Expression<T> r){
    return new BinaryExpressionModel(ope,l, r);
}

//newNary

#endif