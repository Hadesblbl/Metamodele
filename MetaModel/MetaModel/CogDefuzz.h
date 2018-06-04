#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H

#include "MamdaniDefuzz.h"
#include "ValueModel.h"
#include <stdio.h>
#include <stdexcept>

using namespace core;

namespace fuzzy
{
	template <class T>
	class CogDefuzz : public MamdaniDefuzz<T> {
	public:
		CogDefuzz(){};
		virtual ~CogDefuzz() {};
		
		T evaluate(Expression<T>*, Expression<T>*) const;
		void setMin(const T&);
		void setMax(const T&);
		void setStep(const T&);

	private:
		T _min;
		T _max;
		T _step;
	};

	template <class T>
	T CogDefuzz<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
		T area = 0;
		T weightedArea = 0;
		for (int i = _min; i < _max; i += _step) {
            ((ValueModel<T>*) l)->setValue(i);
			T value = r->evaluate();
			area += value;
			weightedArea += value * i;
		}
		if (area == 0) { return -1; }
		else { return weightedArea / area; }
	}

	template<class T>
	void CogDefuzz<T>::setMin(const T& min) {
		_min = min;
	}

	template<class T>
	void CogDefuzz<T>::setMax(const T& max) {
		_max = max;
	}

	template<class T>
	void CogDefuzz<T>::setStep(const T& step) {
		_step = step;
	}
}
#endif
