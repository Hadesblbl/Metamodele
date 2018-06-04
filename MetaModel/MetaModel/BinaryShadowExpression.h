#ifndef BINARYSHADOWEXPRESSION_H
#define BINARYSHADOWEXPRESSION_H

#include "NullOperatorException.h"
#include "BinaryExpression.h"
#include "BinaryExpressionModel.h"
#include "Expression.h"

namespace core
{
	template <class T>
	class BinaryShadowExpression : public BinaryExpression<T> {
	public:
		BinaryShadowExpression() {};
		T evaluate(Expression<T>*, Expression<T>*);
		void setTarget(BinaryExpression<T>*);
	private:
		BinaryExpression<T>* target;
	};

	template <class T>
		T BinaryShadowExpression<T>::evaluate(Expression<T>* l, Expression<T>* r) {
		if (target == null) throw nullOperatorException;
		target.evaluate(l, r);
	};

	template <class T>
		void BinaryShadowExpression<T>::setTarget(BinaryExpression<T>* t) {
		target = t;
	};

}

#endif