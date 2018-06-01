#ifndef THENMIN_H
#define THENMIN_H

#include "BinaryExpression.h";
#include "Then.h";

using namespace core;
template <class T>
class ThenMin : public Then<T> {
	public:
		ThenMin();
		~ThenMin();
		T evaluate(Expression<T> *, Expression<T> *) const;

};

template <class T>
T ThenMin<T>::evaluate(Expression<T> *l, Expression<T> *r) {
	T left = l->evaluate();
	T right = r->evaluate();
	return std::min(left,right);
}

#endif /* ThenMin_h */