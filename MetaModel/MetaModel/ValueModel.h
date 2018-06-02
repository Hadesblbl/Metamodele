#ifndef VALUE_H
#define VALUE_H
#include "Expression.h";

using namespace core;
template <class T>
class ValueModel : public Expression<T> {
	public:
		ValueModel();
		ValueModel(T);
		~ValueModel();

		void setValue(T);
	private:
		T value;
	};

template <class T>
void ValueModel<T>::setValue(T v) {
	value = v;
};

template <class T>
T ValueModel<T>::Expression<T>::evaluate() const {
	return value;
}
#endif // !VALUE_H