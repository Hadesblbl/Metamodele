#ifndef EXPRESSION_H
#define EXPRESSION_H

namespace core {
	template <class T>
	class Expression abstract {
	public:
		virtual T evaluate() const;
	};
}
#endif