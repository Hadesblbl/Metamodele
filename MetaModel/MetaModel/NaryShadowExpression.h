#ifndef NARYSHADOWEXPRESSION_H
#define NARYSHADOWEXPRESSION_H

namespace core
{
	template <class T>
	class NaryShadowExpression : public NaryExpression {
	public:
		NaryShadowExpression();
		T evaluate(Expression<T>[] * );
		void setTarget(NaryExpression<T>*);
	private:
		NaryExpression<T> target;
	};

	template <class T>
		T NaryShadowExpression<T>::evaluate(Expression<T>[] * o) {
		if (target == null) throw NullOperatorException;
		target.evaluate(o);
	};

	template <class T>
		void NaryShadowExpression::setTarget(NaryExpression<T>* exp) {
		target = exp;
	};

}
#endif