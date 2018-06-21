#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H

#include "BinaryExpression.h"
#include "Expression.h"
#include <vector>

using namespace core;

namespace fuzzy 
{
	template <class T>
	class MamdaniDefuzz: public BinaryExpression<T> {
	public:
		MamdaniDefuzz(T _min, T _max, T _step);
		virtual ~MamdaniDefuzz();
		T evaluate(Expression<T>*, Expression<T>*) const=0;
	private:
		T min, max, step;
	};

	template<class T>
	MamdaniDefuzz<T>::MamdaniDefuzz(T _min, T _max, T _step) :min(_min), max(_max), step(_step)
	{
	};

	template<class T>
	MamdaniDefuzz<T>::~MamdaniDefuzz()
	{
	};

}
#endif