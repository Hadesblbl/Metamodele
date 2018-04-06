#ifndef OrPlus_h
#define OrPlus_h
#include "BinaryExpression.h";
#include "Or.h";

using namespace core;
template <class T>
class OrPlus : public Or<T> {

};

template <class T>
T OrPlus<T>::evaluate(Expression<T> *l, Expression<T> *r) {
	T left = l->evaluate();
	T right = r->evaluate();
	return left + right;
}

#endif /* OrPlus_h */