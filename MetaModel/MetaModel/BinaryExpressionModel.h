#ifndef BINARYEXPRESSIONMODEL_H
#define BINARYEXPRESSIONMODEL_H
#include "BinaryExpression.h";
#include "Expression.h";

namespace core {
	template <class T>;
	class BinaryExpressionModel : public BinaryExpression, public Expression {
	};

	T BinaryExpressionModel::BinaryExpression:evaluate(Expression *l,Expression *r) const {
		if (operator!=null) {
			return operator.evaluate(l,r);
		}
	}

	T BinaryExpressionModel::Expression:evaluate() const {
		if (l != null && r != null) {
			return evaluate(l,r);
		}
	}
}
#endif // !UNARYEXPRESSIONMODEL_H