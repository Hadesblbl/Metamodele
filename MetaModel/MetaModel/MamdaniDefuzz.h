#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H

#include "BinaryExpression.h"
#include "Evaluator.h"
#include <vector>

using namespace std;

namespace Fuzzy 
{
	template <class T>
	class MamdaniDefuzz: public BinaryExpression<T> {
	public:

		typedef pair <vector<T>, vector<T>> Shape;

		MamdaniDefuzz(const T& min, const T& max, const T& step) : _min(min), _max(max), _step(step) {};
		virtual ~MamdaniDefuzz() {};

		virtual T evaluate(Expression<T>*, Expression<T>*) const;

	protected:
		virtual T defuzz(const shape&) = 0;

	private:
		T _min;
		T _max;
		T _step;
	};

	template <class T>
	T MamdaniDefuzz<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
		Evaluator<T> eval;
		Evaluator<T>::Shape shape = eval.BuildShape(_min, _max, _step, (ValueModel<T>*) l, r);
		return defuzz(shape);
	}
}
#endif