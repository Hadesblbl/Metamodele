#ifndef NARYEXPRESSION_H
#define NARYEXPRESSION_H

#include "Expression.h";
#include <vector>;

using namespace std;

namespace core {
	template <class T>
	class NaryExpression abstract {
	public:
		virtual T evaluate(vector<Expression<T>*>*) const=0;
	};
}
#endif