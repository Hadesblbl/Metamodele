#ifndef AggPlus_h
#define AggPlus_h
#include "BinaryExpression.h";
#include "Agg.h";

using namespace core;
template <class T>
class AggPlus : public Agg<T> {

};

template <class T>
	T left = l->evaluate();
	T right = r->evaluate();
	return left + right;
}

#endif /* AggPlus_h */