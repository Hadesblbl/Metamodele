#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H
#include "UnaryExpression.h";

using namespace core;

template <class T>;
class UnaryExpressionModel : public UnaryExpression {
};

T UnaryExpressionModel::UnaryExpression:evaluate(Expression o) const {
	if (operator!=null) {
		return operator.evaluate(o);
	}
}

T UnaryExpressionModel::Expression:evaluate() const {
	if (operand != null) {
		return evaluate(operand);
	}
}
#endif // !UNARYEXPRESSIONMODEL_H