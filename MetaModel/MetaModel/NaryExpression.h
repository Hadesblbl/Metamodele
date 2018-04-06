#ifndef NARYEXPRESSION_H
#define NARYEXPRESSION_H
#include "Expression.h";

namespace core {
	template <class T>
	class NaryExpression abstract {
	public:
<<<<<<< HEAD
		virtual T evaluate(Expression**) const;
=======
		virtual T evaluate(Expression<T>[] o) const;
>>>>>>> 6680505190c9798b1ec08b3bcfaf05ab963a2e61
	};
}
#endif