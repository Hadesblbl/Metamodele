#ifndef VALUE_H
#define VALUE_H

#include "Expression.h"

namespace core
{
	template <class T>
	class ValueModel : public Expression<T> {
	public:
		ValueModel() {};
		ValueModel(const T& v) : _val(v) {};
		~ValueModel() {};
        
		void setValue(const T&);
        
        T evaluate() const;
	private:
		T _val;
	};

	template <class T>
	void ValueModel<T>::setValue(const T& v) {
		this->_val = v;
	};

	template <class T>
	T ValueModel<T>::evaluate() const {
		return _val;
	};
}
#endif // !VALUE_H
