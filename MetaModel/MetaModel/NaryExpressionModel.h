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
		NaryExpressionModel(NaryExpression<T>* operator, vector<Expression<T>*>* operands) : _operator(operator), _operands(operands) {};
		virtual ~NaryExceptionException() {};

		virtual T evaluate() const;
		virtual T evaluate(vector<Expression<T>*>*) const;

	private:
		NaryExpression<T>* _operator;
		vector<Expression<T>*>* _operands
	};

	template <class T>
	T NaryExpressionModel<T>::evaluate() const {
		if (_operandes->empty())
		{
			throw new NaryExpressionException();
		}
		return evaluate(_operands);
	};

	template <class T>
	T NaryExpressionModel<T>::evaluate(vector<Expression<T>*>* operands) const {
		if (_operator == null) {
			throw NullOperatorException();
		}
		return _operator->evaluate(operands);
	};

} 

#endif /* NARYEXPRESSIONMODEL_H */
