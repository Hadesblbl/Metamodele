#ifndef AndMult_h
#define AndMult_h
#include "BinaryExpression.h";
#include "And.h";

using namespace core;
template <class T>
class AndMult : public And<T> {

};

template <class T>
T AndMult<T>::evaluate(Expression<T> *l, Expression<T> *r) {
	T left = l->evaluate();
	T right = r->evaluate();
	return left * right;
}

#endif /* AndMult_h */