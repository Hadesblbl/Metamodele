#ifndef ANDMIN_H
#define ANDMIN_H

#include "BinaryExpression.h"
#include "And.h"

using namespace core;

namespace fuzzy
{
	template <class T>
	class AndMin : public And<T> {
	public:
		AndMin() {};
		virtual ~AndMin() {};
		T evaluate(Expression<T> *, Expression<T> *) const;
	};

	template <class T>
	T AndMin<T>::evaluate(Expression<T> *l, Expression<T> *r) const {
		T left = l->evaluate();
		T right = r->evaluate();
		return std::min(left, right);
	};
}
#endif /* AndMin_h */