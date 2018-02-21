#ifndef UNARYEXPRESSION_H
#define UNARYEXPRESSION_H
#include "Expression.h";

using namespace core;

template <class T>
class UnaryExpression abstract {
public:
	virtual T evaluate(Expression o) const;
};
#endif