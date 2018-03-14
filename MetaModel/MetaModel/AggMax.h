#ifndef AggMax_h
#define AggMax_h
#include "BinaryExpression.h";
#include "Agg.h";

using namespace core;
template <class T>
class AggMax : public Agg<T> {

};

template <class T>
T AggMax<T>::evaluate(Expression *l, Expression *r) {
	T left = l->evaluate();
	T right = r->evaluate();
	return std::max(left,right);
}

#endif /* AggMax_h */