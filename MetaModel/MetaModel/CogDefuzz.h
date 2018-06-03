#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H

#include "MamdaniDefuzz.h";

namespace fuzzy
{
	template <class T>
	class CogDefuzz : public MamdaniDefuzz<T>{
		public:
			CogDefuzz() {};
			virtual ~CogDefuzz() {};

	protected:
		virtual T defuzz(const shape&);
	};


	template <class T>
	T CogDefuzz<T>::defuzz(const Shape * shape){
	}
}
#endif