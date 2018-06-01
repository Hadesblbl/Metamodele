#ifndef isTriangle_h
#define isTriangle_h

#include "UnaryExpression.h";
#include "is.h";
using namespace core;

template <class T>
class isTriangle : public is<T> {
private:
	T min;
	T max;
	T mid;

public:
	T getMin();
	T getMid();
	T getMax();
	setMin(T min);
	setMid(T mid);
	setMax(T max);
};

template <class T>
T isTriangle<T>::evaluate(Expression<T> *expr) {
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
T isTriangle<T>::getMax() {
	return max;
}

template <class T>
T isTriangle<T>::getMin() {
	return min;
}

template <class T>
T isTriangle<T>::getMid() {
	return mid;
}

template <class T>
void isTriangle<T>::setMax(T max) {
	this.max = max;
}

template <class T>
void isTriangle<T>::setMid(T mid) {
	this.mid = mid;
}

template <class T>
void isTriangle<T>::setMin(T min) {
	this.min = min;
}
#endif /* AggMax_h */