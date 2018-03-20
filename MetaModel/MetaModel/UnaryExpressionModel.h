#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H
#include "UnaryExpression.h";
#include "Expression.h";

template <class T>
class UnaryExpressionModel : public UnaryExpression<T> , public Expression<T> {
};

template <class T>
T UnaryExpressionModel<T>::evaluate(Expression *o) const {
	if (operator==null) {
		throw NullOperatorException;
	}
	return operator.evaluate(o);
};

template <class T>
T UnaryExpressionModel<T>::evaluate() const {
	if (operand == null) {
		throw NullOperandException;
	}
	return evaluate(operand);
};
#endif // !UNARYEXPRESSIONMODEL_H