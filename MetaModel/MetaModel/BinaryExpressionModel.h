#ifndef BINARYEXPRESSIONMODEL_H
#define BINARYEXPRESSIONMODEL_H
#include "BinaryExpression.h";
#include "Expression.h";

template <class T>
	class BinaryExpressionModel : public BinaryExpression<T>, public Expression<T> {
	};

	template <class T>
	T BinaryExpressionModel<T>::BinaryExpression<T>::evaluate(Expression *l,Expression *r) const {
		if (operator!=null) {
			return operator.evaluate(l,r);
		}
	};

	template <class T>
	T BinaryExpressionModel<T>::Expression<T>::evaluate() const {
		if (l != null && r != null) {
			return evaluate(l,r);
		}
	};
#endif /* UNARYEXPRESSIONMODEL_H */