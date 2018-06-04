#ifndef Agg_h
#define Agg_h

#include "BinaryExpression.h";

using namespace core;

namespace fuzzy
{
	template <class T>
	class Agg : public BinaryExpressions<T> {

	public:
		virtual ~Agg() {};
	};
}
#endif /* Agg_h */