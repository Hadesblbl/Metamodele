#ifndef AndMin_h
#define AndMin_h
#include "BinaryExpression.h";
#include "And.h";
using namespace core;
template <class T>
class AndMin : public And<T> {

};

template <class T>
T AndMin<T>::evaluate(Expression *l, Expression *r) {
	T left = l->evaluate();
	T right = r->evaluate();
	return std::min(left,right);
}

#endif /* AndMin_h */