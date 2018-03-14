#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H
#include "UnaryExpression.h";
#include "Expression.h";

template <class T>
class UnaryExpressionModel : public UnaryExpression<T> , public Expression<T> {
};

template <class T>
T UnaryExpressionModel<T>::UnaryExpression<T>::evaluate(Expression *o) const {
	if (operator!=null) {
		return operator.evaluate(o);
	}
};

template <class T>
T UnaryExpressionModel<T>::Expression<T>::evaluate() const {
	if (operand != null) {
		return evaluate(operand);
	}
};
#endif // !UNARYEXPRESSIONMODEL_H