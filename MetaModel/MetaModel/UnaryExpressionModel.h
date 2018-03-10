#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H
#include "UnaryExpression.h";
#include "Expression.h";

class UnaryExpressionModel : public UnaryExpression , public Expression {
};

template <class T>
T UnaryExpressionModel::UnaryExpression::evaluate(Expression *o) const {
	if (operator!=null) {
		return operator.evaluate(*o);
	}
};

template <class T>
T UnaryExpressionModel::Expression::evaluate() const {
	if (operand != null) {
		return evaluate(*operand);
	}
};
#endif // !UNARYEXPRESSIONMODEL_H