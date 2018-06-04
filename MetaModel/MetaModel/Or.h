#ifndef Or_h
#define Or_h

#include "BinaryExpression.h"

using namespace core;

namespace fuzzy
{
	template <class T>
	class Or : public BinaryExpression<T> {
	public:
		virtual ~Or() {};
	};
}
#endif /* Or_h */