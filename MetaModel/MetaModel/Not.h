#ifndef Not_h
#define Not_h

#include "UnaryExpression.h"

using namespace core;

namespace fuzzy
{
	template <class T>
	class Not : public UnaryExpression<T> {
	public:
		virtual ~Not() {};
	};
}
#endif /* Not_h */