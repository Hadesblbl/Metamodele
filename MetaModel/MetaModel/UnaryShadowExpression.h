#ifndef UNARYSHADOWEXPRESSION_H
#define UNARYSHADOWEXPRESSION_H

#include "UnaryExpression.h"
#include "Expression.h"
#include "NullOperatorException.h"

namespace core
{
	template <class T>
	class UnaryShadowExpression : public UnaryExpression {
	public:
		UnaryShadowExpression() {};
		virtual ~UnaryShadowExpression() {};
		T evaluate(Expression<T>*) const;
	private:
		UnaryExpression<T>* _target;
	};

	template <class T>
		T UnaryShadowExpression<T>::evaluate(Expression<T>* o) const{
		if (_target == null) throw NullOperatorException;
		_target ->evaluate(o);
	};
}
#endif