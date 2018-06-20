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
		virtual ~MamdaniDefuzz() {};
		T evaluate(Expression<T>*, Expression<T>*) const;
		virtual T defuzz(const typename Eval<T>::Shape&) const = 0;
	private:
		T min, max, step;
	};

	template<class T>
	MamdaniDefuzz<T>::MamdaniDefuzz(T _min, T _max, T _step) :min(_min), max(_max), step(_step)
	{
	}

	template<class T>
	T MamdaniDefuzz<T>::evaluate(Expression<T>* l, Expression<T>* r) const
	{
		return defuzz(Eval<T>::BuildShape(min, max, step, (ValueModel<T>*)l, r));
	}

	template<class T>
	MamdaniDefuzz<T>::MamdaniDefuzz()
	{
		delete min;
		delete max;
		delete step;
	};

}
#endif