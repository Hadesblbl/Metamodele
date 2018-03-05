#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H
#include "UnaryExpression.h";
#include "Expression.h";

namespace core {
	template <class T>;
	class UnaryExpressionModel : public UnaryExpression , public Expression {
	};

	T UnaryExpressionModel::UnaryExpression:evaluate(Expression *o) const {
		if (operator!=null) {
			return operator.evaluate(*o);
		}
	}

	T UnaryExpressionModel::Expression:evaluate() const {
		if (operand != null) {
			return evaluate(*operand);
		}
	}
}
#endif // !UNARYEXPRESSIONMODEL_H