#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H
#include "Expression.h";

namespace core {
	template <class T>
	class BinaryExpression abstract {
	public:
		virtual T evaluate(Expression<T> *l,Expression<T> *r) const;
	};
}
#endif