#ifndef isTriangle_h
#define isTriangle_h

#include "UnaryExpression.h";
#include "is.h";
using namespace core;

namespace fuzzy
{
	template <class T>
	class IsTriangle : public Is<T> {
	public:
		IsTriangle(T _min, T _mid, T _max) : min(_min), mid(_mid), max(_max) {};
		virtual ~IsTriangle() {};

		T evaluate(Expression<T>*) const;

	private:
		T min;
		T max;
		T mid;
	};

	template <class T>
	T IsTriangle<T>::evaluate(Expression<T> *expr) const{
		T val = expr->evaluate();

		if (val >= min && val < mid) {
			return (val - min) / (mid - min);
		}
		else if (val >= mid && val <= max) {
			return (max - val) / (max - mid);
		}

		return 0;
	}

}
#endif /* AggMax_h */