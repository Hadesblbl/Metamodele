#ifndef NARYEXPRESSION_H
#define NARYEXPRESSION_H
#include "Expression.h";

namespace core {
	template <class T>
	class NaryExpression abstract {
	public:
		virtual T evaluate(Expression<T>[] o) const;
	};
}
#endif