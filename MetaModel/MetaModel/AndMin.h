#ifndef AndMin_h
#define AndMin_h

#include "BinaryExpression.h";
#include "And.h";
using namespace core;

template <class T>
class AndMin : public And<T> {
	public:
		AndMin();
		~AndMin();
		T evaluate(Expression<T> *, Expression<T> *) const;
};

template <class T>
T AndMin<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
	T left = l->evaluate();
	T right = r->evaluate();
	return std::min(left,right);
}

#endif /* AndMin_h */