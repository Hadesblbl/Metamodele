#ifndef MamdaniDefuzz_H
#define MamdaniDefuzz_H

namespace Fuzzy {
	template <class T>
	class MamdaniDefuzz abstract {
	public:
		virtual T evaluate() const;
		shape buildshape(int min,int max,int step);
		virtual defuzz(const &shape) = 0;
	};

	template <class T>
	T MamdaniDefuzz<T>::evaluate() const {
		defuzz(buildshape(min,max,step));
	}
}
#endif