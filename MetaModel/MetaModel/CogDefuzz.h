#ifndef CogDefuzz_H
#define CogDefuzz_H
#include "MamdaniDefuzz.h";

namespace Fuzzy {
	template <class T>
	class CogDefuzz : public MamdaniDefuzz<T> {
	};

	template <class T>
	T CogDefuzz<T>::defuzz(const &shape) {

	}
}
#endif