#ifndef is_h
#define is_h

#include "UnaryExpression.h";
using namespace core;

namespace fuzzy
{
	template <class T>
	class is : public UnaryExpression<T> {
	public:
		virtual ~Is() {};
	};
}
#endif /* is_h */