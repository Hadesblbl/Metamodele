#ifndef SUGENOTHEN_H
#define SUGENOTHEN_H

#include "Then.h"
#include "Expression.h"

namespace core {

	template<class T>
	class SugenoThen : public Then {
	public:
		SugenoThen() :premiseValue(0) {};
		virtual ~SugenoThen();
		T evaluate(Expression<T> *, Expression<T> *) const;
		T premiseValue();
	private:
		T _premiseValue;
	};

	template <class T>
	SugenoThen<T>::~SugenoThen() {
		delete _premiseValue
	};

	template <class T>
	T SugenoThen<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
		premiseValue = l->evaluate();
		return premiseValue * r->evaluate();
	};

	template<class T>
	T SugenoThen<T>::premiseValue() {
		return _premiseValue;
	};
};

#endif