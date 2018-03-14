#ifndef VALUE_H
#define VALUE_H
#include "Expression.h";

template <class T>
class ValueModel : public Expression<T> {
	private:
		T value;
	public:
		void setValue(T v);
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