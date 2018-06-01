#ifndef NotMinus1_h
#define NotMinus1_h

#include "UnaryExpression.h";
#include "Not.h";
using namespace core;

template <class T>
class NotMinus1 : public Not<T> {
	public:
		NotMinus1();
		~NotMinus1();
		T evaluate(Expression<T> *) const;
};

template <class T>
T NotMinus1<T>::evaluate(Expression<T> *expr) {
	T val = expr->evaluate();
	return -val-1;
}

#endif /* AggMax_h */