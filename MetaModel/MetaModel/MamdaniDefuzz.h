#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H

#include "BinaryExpression.h"
#include "Expression.h"
#include <vector>

using namespace std;
using namespace core;

namespace fuzzy 
{
	template <class T>
	class MamdaniDefuzz: public BinaryExpression<T> {
	public:
		virtual ~MamdaniDefuzz() {};
		virtual T evaluate(Expression<T>*, Expression<T>*) const =0;
	};

}
#endif