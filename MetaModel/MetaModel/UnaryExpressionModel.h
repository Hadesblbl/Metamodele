#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H
#include "UnaryExpression.h";
#include "Expression.h";

namespace core
{
	template <class T>
	class UnaryExpressionModel : public UnaryExpression<T>, public Expression<T> {
	public:
		UnaryExpressionModel(UnaryExpression<T>*, Expression<T>*);

		virtual T evaluate() const;
		virtual T evaluate(Expression<T>*) const;

		virtual UnaryExpression<T>* getOperator();
		virtual Expression<T>* getOperand();
		virtual void setOperator(UnaryExpression<T>*);
		virtual void setOperand(Expression<T>*);
	private:
		UnaryExpression<T> *ope;
		Expression<T> *operand;
	};

	template <class T>
	UnaryExpressionModel<T>::UnaryExpressionModel(UnaryExpression<T>* ope, Expression<T>* operand) {
		this->ope = ope; this->operand = operand;
	};

	template <class T>
	T UnaryExpressionModel<T>::evaluate(Expression *o) const {
		if (ope == null) {
			throw NullOperatorException();
		}
		return ope->evaluate(o);
	};

	template <class T>
	T UnaryExpressionModel<T>::evaluate() const {
		if (operand == null) {
			throw NullOperandException();
		}
		return evaluate(operand);
	};

	template <class T>
	UnaryExpression<T>* UnaryExpressionModel<T>::getOperator() {
		return ope;
	};

	template <class T>
	Expression<T>* UnaryExpressionModel<T>::getOperand() {
		return operand;
	};

	template <class T>
	void UnaryExpressionModel<T>::setOperator(UnaryExpression<T>* ope) {
		this->ope = ope;
	};

	template <class T>
	void UnaryExpressionModel<T>::setOperand(Expression<T>* operand) {
		this->operand = operand;
	};
}
#endif // !UNARYEXPRESSIONMODEL_H