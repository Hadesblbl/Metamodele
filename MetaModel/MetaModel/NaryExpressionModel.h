#ifndef NARYEXPRESSIONMODEL_H
#define NARYEXPRESSIONMODEL_H

#include "NaryExpression.h";
#include "Expression.h";
#include "NaryExpressionException.h"

using namespace std;

namespace core
{
	template <class T>
	class NaryExpressionModel : public NaryExpression<T>, public Expression<T> {
	public:
		NaryExpressionModel(NaryExpression<T>* ope, std::vector<Expression<T>*> operands) : _operator(ope), _operands(operands) {};
		virtual ~NaryExpressionModel() {};
		virtual T evaluate() const;
		virtual T evaluate(vector<Expression<T>*>) const;

	private:
		NaryExpression<T>* _operator;
		vector<Expression<T>*> _operands;
	};

	template <class T> T NaryExpressionModel<T>::evaluate() const {
		if (_operator != NULL) return evaluate(_operands);
		return NULL;
	};

	template <class T> T NaryExpressionModel<T>::evaluate(std::vector<Expression<T>*> o) const {
		if (_operator != NULL) return _operator->evaluate(o);
		return NULL;
	};
};

#endif /* NARYEXPRESSIONMODEL_H */
