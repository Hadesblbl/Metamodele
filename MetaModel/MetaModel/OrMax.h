#ifndef ORMAX_H
#define ORMAX_H

#include "BinaryExpression.h";
#include "Or.h";

using namespace core;

namespace fuzzy
{
	template <class T>
	class OrMax : public Or<T> {
	public:
		OrMax() {};
		virtual ~OrMax() {};
		T evaluate(Expression<T> *, Expression<T> *) const;
	};

	template <class T>
	T OrMax<T>::evaluate(Expression<T> *l, Expression<T> *r) const{
		T left = l->evaluate();
		T right = r->evaluate();
		return std::max(left, right);
	};
}
#endif /* OrMax_h */