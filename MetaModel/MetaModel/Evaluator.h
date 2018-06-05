#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <vector>
#include "ValueModel.h"
#include "Expression.h"

using namespace std;

namespace core
{
	template <class T>
	class Evaluator
	{
	public:


		typedef pair<vector<T>, vector<T>> Shape;
		Shape BuildShape(const T&, const T&, const T&, ValueModel<T>*, Expression<T>*) const;
		ostream& PrintShape(ostream& , const Shape&) const;
	};

	template <class T>
	typename Evaluator<T>::Shape Evaluator<T>::BuildShape(const T& min, const T& max, const T& step, ValueModel<T>* val, Expression<T>* exp) const
	{
		vector<T> x, y;
		for (T i = min; i <= max; i += step)
		{
			val->SetValue(i);
			y.push_back(f(i));
			x.push_back(i);
		}
		return Shape(x, y);
	};

	template <class T>
	ostream& Evaluator<T>::PrintShape(ostream& os, const Shape& s) const
	{
		os << '[';
		typename vector<T>::const_iterator it = s.first.begin();
		for (; it != s.first.end(); ++it)
			os << *it << ' ';
		os << ']';
		os << endl;
		os << '[';
		it = s.second.begin();
		for (; it != s.second.end(); ++it)
			os << *it << ' ';
		os << ']';
		return os;
	};
}
#endif