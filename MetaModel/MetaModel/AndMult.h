#ifndef AndMult_h
#define AndMult_h
#include "BinaryExpression.h";
#include "And.h";

using namespace core;
class AndMult : public And {

};

template <class T>
T AndMult::BinaryExpression::evaluate(Expression l, Expression r) {
	return evaluate(l)*evaluate(r);
}

#endif /* AndMult_h */