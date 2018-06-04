#ifndef NotMinus1_h
#define NotMinus1_h

#include "UnaryExpression.h"
#include "Not.h"
using namespace core;

namespace fuzzy
{
	template <class T>
	class NotMinus1 : public Not<T> {
	public:
		NotMinus1() {};
		virtual ~NotMinus1() {};
		T evaluate(Expression<T> *) const;
	};

	template <class T>
	T NotMinus1<T>::evaluate(Expression<T> *expr) const {
		T val = expr->evaluate();
		return 1 - val;
	};
}
#endif /* AggMax_h */