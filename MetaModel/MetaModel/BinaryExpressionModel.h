#ifndef BINARYEXPRESSIONMODEL_H
#define BINARYEXPRESSIONMODEL_H
#include "BinaryExpression.h";
#include "Expression.h";

using namespace  core;
template <class T>
	class BinaryExpressionModel : public BinaryExpression<T>, public Expression<T> {
	};

	template <class T>
	T BinaryExpressionModel<T>::evaluate(Expression *l,Expression *r) const {
		if (operator==null) {
			throw NullOperatorException;
		}
		return operator.evaluate(l,r);
	};

	template <class T>
	T BinaryExpressionModel<T>::evaluate() const {
		if (l ==null) {
			throw LeftExpressionException;
		}
		if (r == null) {
			throw RightExpressionException;
		}
		return evaluate(l, r);
	};
#endif /* UNARYEXPRESSIONMODEL_H */