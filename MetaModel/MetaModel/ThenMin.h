#ifndef ThenMin_h
#define ThenMin_h
#include "BinaryExpression.h";
#include "Then.h";

using namespace core;
class ThenMin : public Then {

};

template <class T>
T ThenMin::BinaryExpression::evaluate(Expression l, Expression r) {
	return std::min(evaluate(l),evaluate(r));
}

#endif /* ThenMin_h */