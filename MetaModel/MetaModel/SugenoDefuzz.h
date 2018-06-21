#ifndef SUGENODEFUZZ_H
#define SUGENODEFUZZ_H

#include "NaryExpression.h"
#include "Expression.h"

using namespace core;
namespace fuzzy {

	template <class T>
	class SugenoDefuzz : public NaryExpression<T> {
	private:
		std::vector<SugenoConclusion<T>*> conclusions;
	public:
		SugenoDefuzz(std::vector<SugenoConclusion<T>*>);
		virtual ~SugenoDefuzz();
		virtual T evaluate(std::vector<Expression<T>*>) const;
	};

	template<class T>
	SugenoDefuzz<T>::SugenoDefuzz(std::vector<SugenoConclusion<T>*> _conclusions) :conclusions(_conclusions)
	{
	};

	template<class T>
	SugenoDefuzz<T>::~SugenoDefuzz()
	{
	};

	template<class T>
	T SugenoDefuzz<T>::evaluate(std::vector<Expression<T>*> operands) const
	{
		T x, y, num = 0, den = 0;

		for (unsigned int i = 2; i < (operands.size()); i++) {
			x = conclusions.at(i - 2)->evaluate(std::vector<Expression<T>*>({ operands.at(0),operands.at(1) }));
			y = operands.at(i)->evaluate();
			std::cout << "x: " << x << " ,y: " << y << std::endl;
			num += (x * y);
			den += y;
		};
		std::cout << "num: " << num << " ,den: " << den << std::endl;
		return num / end;
	};
};
#endif