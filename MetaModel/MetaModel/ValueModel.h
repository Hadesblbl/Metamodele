#ifndef VALUE_H
#define VALUE_H
#include "Expression.h";

namespace core {
	template <class T>;
	class ValueModel : public Expression {
	private:
		T value;
	public:
		void setValue(T v);
	};

	void ValueModel::setValue(T v) {
		value = v;
	}

	T ValueModel::Expression:evaluate() const {
		return value;
	}
}
#endif // !VALUE_H