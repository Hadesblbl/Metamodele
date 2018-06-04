#ifndef UNARYSHADOWEXPRESSION_H
#define UNARYSHADOWEXPRESSION_H

#include "UnaryExpression.h"
#include "Expression.h"
#include "NullOperatorException.h"

namespace core
{
	template <class T>
	class UnaryShadowExpression : public UnaryExpression<T> {
	public:
		UnaryShadowExpression(UnaryExpression<T>* target): _target(target) {};
		virtual ~UnaryShadowExpression() {};
		T evaluate(Expression<T>*) const;
	private:
		UnaryExpression<T>* _target;
	};

	template <class T>
    T UnaryShadowExpression<T>::evaluate(Expression<T>* o) const{
		if (_target == NULL) throw new NullOperatorException();
		return _target->evaluate(o);
	}
}
#endif
