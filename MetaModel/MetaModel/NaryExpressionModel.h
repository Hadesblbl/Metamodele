#ifndef NARYEXPRESSIONMODEL_H
#define NARYEXPRESSIONMODEL_H
#include "NaryExpression.h";
#include "Expression.h";

using namespace core;
template <class T>
class NaryExpressionModel : public NaryExpression<T>, public Expression<T> {
public:
	NaryExpressionModel(BinaryExpression<T>*, Expression<T>**);

	virtual T evaluate() const;
	virtual T evaluate(Expression<T>**) const;

	virtual NaryExpression<T>* getOperator();
	virtual Expression<T>[]* getOperands();
	virtual void setOpe(BinaryExpression<T>*);
	virtual void setOperands(Expression<T>**);
private:
	NaryExpression<T> *ope;
	Expression<T> **operands;
};

template <class T>
T NaryExpressionModel<T>::evaluate(Expression<T> **operands) const {
	if (ope == null) {
		throw NullOperatorException();
	}
	return ope->evaluate(operands);
};

template<class T>
NaryExpressionModel<T>::NaryExpressionModel(NaryExpression<T>* ope, Expression<T> **operands)
{
	this->ope = ope; this->operands=operands;
}

template <class T>
T NaryExpressionModel<T>::evaluate() const {
	for (int i = 0; i < operands.strlen(); i++) {
		if (operands[i] == null) {
			throw NaryExpressionException();
		}
	}
	return evaluate(operands);
};

template <class T>
NaryExpression<T>* NaryExpressionModel::getOperator() {
	return ope;
};

template <class T>
Expression<T>** NaryExpressionModel::getOperands() {
	return operands;
};

template <class T>
void NaryExpressionModel::setOpe(BinaryExpression<T>* be) {
	ope = be;
};

template <class T>
void NaryExpressionModel::setOperands(Expression<T> **oper) {
	operands = oper;
};
