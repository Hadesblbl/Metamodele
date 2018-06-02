#ifndef isTriangle_h
#define isTriangle_h

#include "UnaryExpression.h";
#include "is.h";
using namespace core;

template <class T>
class IsTriangle : public is<T> {
public:
	IsTriangle(T,T,T);
	~IsTriangle();

	T getMin();
	T getMid();
	T getMax();
	setMin(T min);
	setMid(T mid);
	setMax(T max);

private:
	T min;
	T max;
	T mid;
};

template <class T>
T IsTriangle<T>::evaluate(Expression<T> *expr) {
	T val = evaluate(expr);
	if (val >= min && val < mid) {
		return;
	}
	else if (val >= mid && val <= max) {
		return;
	}
	else {
		return;
	}
}

template <class T>
T IsTriangle<T>::getMax() {
	return max;
}

template <class T>
T IsTriangle<T>::getMin() {
	return min;
}

template <class T>
T IsTriangle<T>::getMid() {
	return mid;
}

template <class T>
void IsTriangle<T>::setMax(T max) {
	this.max = max;
}

template <class T>
void IsTriangle<T>::setMid(T mid) {
	this.mid = mid;
}

template <class T>
void IsTriangle<T>::setMin(T min) {
	this.min = min;
}
#endif /* AggMax_h */