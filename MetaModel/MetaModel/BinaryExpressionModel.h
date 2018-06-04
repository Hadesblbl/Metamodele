#ifndef BINARYEXPRESSIONMODEL_H
#define BINARYEXPRESSIONMODEL_H

#include "BinaryExpression.h"
#include "Expression.h"
#include "NullOperandException.h"
#include "NullOperatorException.h"
#include "LeftExpressionException.h"
#include "RightExpressionException.h"

namespace core
{
	template <class T>
	class BinaryExpressionModel : public BinaryExpression<T>, public Expression<T> {
	public:
		BinaryExpressionModel(BinaryExpression<T>* ope, Expression<T>* left, Expression<T>* right) : _ope(ope), _l(left), _r(right) {};
		virtual ~BinaryExpressionModel() {};

		virtual T evaluate() const;
		virtual T evaluate(Expression<T>*, Expression<T>*) const;

		virtual BinaryExpression<T>* getOperator() const;
		virtual Expression<T>* getLeft() const;
		virtual Expression<T>* getRight() const;
		virtual void setOpe(BinaryExpression<T>*);
		virtual void setLeft(Expression<T>*);
		virtual void setRight(Expression<T>*);

	private:
		BinaryExpression<T>* _ope;
		Expression<T> *l;
		Expression<T> *r;
	};

	template <class T>
	T BinaryExpressionModel<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
		if (ope == null) {
			throw NullOperatorException();
		}
		return ope->evaluate(l, r);
	};

	template <class T>
	T BinaryExpressionModel<T>::evaluate() const {
		if (_l == null) {
			throw LeftExpressionException();
		}
		if (_r == null) {
			throw RightExpressionException();
		}
		return evaluate(_l, _r);
	};

	template <class T>
	BinaryExpression<T>* BinaryExpressionModel<T>::getOperator() const {
		return this->_ope;
	};

	template <class T>
	Expression<T>* BinaryExpressionModel<T>::getLeft() const {
		return this->_l;
	};

	template <class T>
	Expression<T>* BinaryExpressionModel<T>::getRight() const {
		return this->_r;
	};

	template <class T>
	void BinaryExpressionModel<T>::setOpe(BinaryExpression<T>* be) {
		_ope = be;
	};

	template <class T>
	void BinaryExpressionModel<T>::setLeft(Expression<T>* left) {
		_l = left;
	};

	template <class T>
	void BinaryExpressionModel<T>::setRight(Expression<T>* right) {
		_r = right;
	};
}
#endif /* UNARYEXPRESSIONMODEL_H */