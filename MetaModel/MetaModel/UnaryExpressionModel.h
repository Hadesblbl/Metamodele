#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H

#include "UnaryExpression.h"
#include "Expression.h"
#include "NullOperatorException.h"
#include "NullOperandException.h"

namespace core
{
	template <class T>
	class UnaryExpressionModel : public UnaryExpression<T>, public Expression<T> {
	public:
		UnaryExpressionModel(UnaryExpression<T>* ope, Expression<T>* operand) : _ope(ope), _operand(operand) {};
		virtual ~UnaryExpressionModel() {};

		virtual T evaluate() const;
		virtual T evaluate(Expression<T>*) const;

		virtual UnaryExpression<T>* getOperator();
		virtual Expression<T>* getOperand();
		virtual void setOperator(UnaryExpression<T>*);
		virtual void setOperand(Expression<T>*);
	private:
		UnaryExpression<T>* _ope;
		Expression<T>* _operand;
	};

	template <class T>
	T UnaryExpressionModel<T>::evaluate(Expression<T> *o) const {
		if (_ope == NULL) {
			throw NullOperatorException();
		}
		return _ope->evaluate(o);
	};

	template <class T>
	T UnaryExpressionModel<T>::evaluate() const {
		if (_operand == NULL) {
			throw NullOperandException();
		}
		return evaluate(_operand);
	};

	template <class T>
	UnaryExpression<T>* UnaryExpressionModel<T>::getOperator() {
		return _ope;
	};

	template <class T>
	Expression<T>* UnaryExpressionModel<T>::getOperand() {
		return _operand;
	};

	template <class T>
	void UnaryExpressionModel<T>::setOperator(UnaryExpression<T>* ope) {
		this->_ope = ope;
	};

	template <class T>
	void UnaryExpressionModel<T>::setOperand(Expression<T>* operand) {
		this->_operand = operand;
	};
}
#endif // !UNARYEXPRESSIONMODEL_H
