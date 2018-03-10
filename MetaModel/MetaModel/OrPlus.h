#ifndef OrPlus_h
#define OrPlus_h
#include "BinaryExpression.h";
#include "Or.h";

using namespace core;
class OrPlus : public Or {

};

template <class T>
T OrPlus::BinaryExpression::evaluate(Expression l, Expression r) {
	return evaluate(l)+evaluate(r);
}

#endif /* OrPlus_h */