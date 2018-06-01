#ifndef AggMax_h
#define AggMax_h
#include "BinaryExpression.h";
#include "Agg.h";

using namespace core;
template <class T>
class AggMax : public Agg<T> {
	public:
		AggMax();
		~AggMax();
		T evaluate(Expression<T> *, Expression<T> *) const;
};

template <class T>
T AggMax<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
	T left = l->evaluate();
	T right = r->evaluate();
	return std::max(left,right);
}

#endif /* AggMax_h */