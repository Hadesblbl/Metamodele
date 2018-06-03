#ifndef NARYSHADOWEXPRESSION_H
#define NARYSHADOWEXPRESSION_H

namespace core
{
	template <class T>
	class NaryShadowExpression : public NaryExpression {
	public:
		NaryShadowExpression(NaryExpression<T>* target) : _target(target) {};
		T evaluate(vector<Expression<T>*>*) const;
		void setTarget(NaryExpression<T>*);
	private:
		NaryExpression<T>* _target;
	};

	template <class T>
		T NaryShadowExpression<T>::evaluate(vector<Expression<T>*>* operands) const{
		if (_target == null) throw NullOperatorException();
		_target->evaluate(operands);
	};

	template <class T>
		void NaryShadowExpression::setTarget(NaryExpression<T>* exp) {
		_target = exp;
	};

}
#endif