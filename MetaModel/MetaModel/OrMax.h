#ifndef OrMax_h
#define OrMax_h
#include "BinaryExpression.h";
#include "Or.h";

using namespace core;
class OrMax : public Or {

};

template <class T>
T OrMax::BinaryExpression::evaluate(Expression l, Expression r) {
	return std::max(evaluate(l),evaluate(r));
}

#endif /* OrMax_h */