#ifndef is_h
#define is_h

#include "UnaryExpression.h"
using namespace core;

namespace fuzzy
{
	template <class T>
	class Is : public UnaryExpression<T> {
	};
}
#endif /* is_h */