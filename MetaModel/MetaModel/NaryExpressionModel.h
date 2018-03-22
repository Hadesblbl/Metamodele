#ifndef NARYEXPRESSIONMODEL_H
#define NARYEXPRESSIONMODEL_H
#include "NaryExpression.h";
#include "Expression.h";

using namespace core;
template <class T>
class NaryExpressionModel : public NaryExpression<T> , public Expression<T> {
private:
	NaryExpression<T> operator;
	Expression<T>[] operand;
};

template <class T>
T NaryExpressionModel<T>::evaluate(Expression<T>[] *o) const {
	if (operator==null) {
		throw NullOperatorException();
	}
	return operator->evaluate(o);
};

template <class T>
T NaryExpressionModel<T>::evaluate() const {
	if (operand == null) {
		throw NullOperandException();
	}
	return evaluate(operand);
};
#endif