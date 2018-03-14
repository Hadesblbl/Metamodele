#ifndef ThenMin_h
#define ThenMin_h
#include "BinaryExpression.h";
#include "Then.h";

using namespace core;
template <class T>
class ThenMin : public Then<T> {

};

template <class T>
T ThenMin<T>::evaluate(Expression *l, Expression *r) {
	T left = l->evaluate();
	T right = r->evaluate();
	return std::min(left,right);
}

#endif /* ThenMin_h */