#ifndef AggPlus_h
#define AggPlus_h

#include "BinaryExpression.h"
#include "Agg.h"
#include "Expression.h"

using namespace core;

namespace fuzzy
{
	template <class T>
	class AggPlus : public Agg<T> {
	public:
		AggPlus() {};
		virtual ~AggPlus() {};
		T evaluate(Expression<T> *, Expression<T> *) const;
	};

	template <class T>
	T AggPlus<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
		T left = l->evaluate();
		T right = r->evaluate();
		return left + right;
	}
}
#endif /* AggPlus_h */