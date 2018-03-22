#ifndef OrMax_h
#define OrMax_h
#include "BinaryExpression.h";
#include "Or.h";

using namespace core;
template <class T>
class OrMax : public Or<T> {

};

template <class T>
T OrMax<T>::evaluate(Expression<T> *l, Expression<T> *r) {
	T left = l->evaluate();
	T right = r->evaluate();
	return std::max(left,right);
}

#endif /* OrMax_h */