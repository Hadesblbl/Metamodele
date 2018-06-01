#ifndef ORMAX_H
#define ORMAX_H

#include "BinaryExpression.h";
#include "Or.h";

using namespace core;
template <class T>
class OrMax : public Or<T> {
	public:
		OrMax();
		~OrMax();
		T evaluate(Expression<T> *, Expression<T> *) const;
};

template <class T>
T OrMax<T>::evaluate(Expression<T> *l, Expression<T> *r) {
	T left = l->evaluate();
	T right = r->evaluate();
	return std::max(left,right);
}

#endif /* OrMax_h */