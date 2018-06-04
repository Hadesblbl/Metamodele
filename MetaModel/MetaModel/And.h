#ifndef And_h
#define And_h

#include "BinaryExpression.h"

using namespace core;

namespace fuzzy
{
	template <class T>
	class And : public BinaryExpression<T> {
	public:
		virtual ~And() {};
	};
}
#endif /* And_h */