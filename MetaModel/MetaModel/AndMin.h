#ifndef AndMin_h
#define AndMin_h
#include "BinaryExpression.h";
using namespace core;
template <class T>;
class AndMin : public And {

};

T AndMin::BinaryExpression:evaluate(Expression l, Expression r) {
	return std::min(evaluate(l), evaluate(r));
}

#endif /* AndMin_h */