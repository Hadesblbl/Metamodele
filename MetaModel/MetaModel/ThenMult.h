#ifndef ThenMult_h
#define ThenMult_h
#include "BinaryExpression.h";
#include "Then.h";

using namespace core;
template <class T>
class ThenMult : public Then<T> {
	public:
		ThenMult();
		~ThenMult();
		T evaluate(Expression<T> *, Expression<T> *) const;
};

template <class T>
T ThenMult<T>::evaluate(Expression<T> *l, Expression<T> *r) {
	T left = l->evaluate();
	T right = r->evaluate();
	return left * right;
}

#endif /* ThenMult_h */