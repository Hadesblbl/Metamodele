#ifndef Then_h
#define Then_h

#include "BinaryExpression.h"

using namespace core;

namespace fuzzy
{
	template <class T>
	class Then : public BinaryExpression<T> {};
};
#endif /* Then_h */