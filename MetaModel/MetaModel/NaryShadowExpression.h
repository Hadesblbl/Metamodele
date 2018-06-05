#ifndef NARYSHADOWEXPRESSION_H
#define NARYSHADOWEXPRESSION_H
#include "NaryExpression.h"
#include "Expression.h"
#include "NullOperatorException.h"

namespace core
{
	template <class T>
	class NaryShadowExpression : public NaryExpression<T> {
	public:
		NaryShadowExpression(NaryExpression<T>* target) : _target(target) {};
		T evaluate(vector<Expression<T>*>*) const;
		void setTarget(NaryExpression<T>*);
	private:
		NaryExpression<T>* _target;
	};

	template <class T>
		T NaryShadowExpression<T>::evaluate(vector<Expression<T>*>* operands) const{
		if (_target == NULL) throw new NullOperatorException();
		_target->evaluate(operands);
	};

	template <class T>
		void NaryShadowExpression<T>::setTarget(NaryExpression<T>* exp) {
		_target = exp;
	};

}
#endif
