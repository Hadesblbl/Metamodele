#ifndef OrPlus_h
#define OrPlus_h
#include "BinaryExpression.h"
#include "Or.h"

using namespace core;

namespace fuzzy
{
	template <class T>
	class OrPlus : public Or<T> {
	public:
		OrPlus() {};
		virtual ~OrPlus() {};
		T evaluate(Expression<T> *, Expression<T> *) const;

	};

	template <class T>
	T OrPlus<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
		T left = l->evaluate();
		T right = r->evaluate();
		return left + right;
	}
}
#endif /* OrPlus_h */