#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H

#include "MamdaniDefuzz.h";

namespace fuzzy
{
	template <class T>
	class CogDefuzz : public MamdaniDefuzz<T>{
		public:
			CogDefuzz();
			~CogDefuzz();

			T evaluate();
	};
	/*
	template <class T>
	T CogDefuzz<T>::defuzz(const Shape * shape){
	}*/
}
#endif