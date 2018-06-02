#ifndef UNARYSHADOWEXPRESSION_H
#define UNARYSHADOWEXPRESSION_H

namespace core
{
	template <class T>
	class UnaryShadowExpression : public UnaryExpression {
	public:
		UnaryShadowExpression();
		T evaluate(Expression<T>*);
	private:
		UnaryExpression<T> target;
	};

	template <class T>
		 UnaryShadowExpression<T>::evaluate(Expression<T>* o) {
		if (target == null) throw NullOperatorException;
		target.evaluate(o);
	};
}
#endif