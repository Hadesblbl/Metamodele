#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H

#include "ExpressionFactory.h"
#include "Expression.h"

#include "Agg.h"
#include "Not.h"
#include "And.h"
#include "is.h"
#include "Then.h"
#include "Or.h"

#include "CogDefuzz.h"

#include "UnaryShadowExpression.h"
#include "BinaryShadowExpression.h"
#include "NaryShadowExpression.h"

using namespace core;


namespace fuzzy
{
	template<class T>
	class FuzzyFactory : public ExpressionFactory<T> {
	public:
		FuzzyFactory(Not<T>* _not, And<T>* _and, Or<T>* _or, Then<T>* _then, Agg<T>* _agg, CogDefuzz<T>* _defuzz) : 
			_not(new UnaryShadowExpression<T>(_not)),
			_and(new BinaryShadowExpression<T>(_and)),
			_or(new BinaryShadowExpression<T>(_or)),
			_then(new BinaryShadowExpression<T>(_then)),
			_agg(new BinaryShadowExpression<T>(_agg)),
			_defuzz(new BinaryShadowExpression<T>(_defuzz))
		{};

		ValueModel<T>* newValue(T);

		virtual ~FuzzyFactory();

		Expression<T>* newAnd(Expression<T>*, Expression<T>*);
		Expression<T>* newOr(Expression<T>*, Expression<T>*);
		Expression<T>* newThen(Expression<T>*, Expression<T>*);
		Expression<T>* newAgg(Expression<T>*, Expression<T>*);
		Expression<T>* newDefuzz(Expression<T>*, Expression<T>*, const T&, const T&, const T&);
		Expression<T>* newNot(Expression<T>*);
		Expression<T>* newIs(Expression<T>*, Is<T>*);
		NaryExpression<T>* newSugeno(std::vector<Expression<T>*>);

		void changeAnd(And<T>*);
		void changeOr(Or<T>*);
		void changeThen(Then<T>*);
		void changeAgg(Agg<T>*);
		void changeNot(Not<T>*);
		void changeDefuzz(BinaryExpression<T>*);
		void changeSugeno(NaryExpression<T>*);

	private:
		UnaryShadowExpression<T>* _not;
		BinaryShadowExpression<T>* _or;
		BinaryShadowExpression<T>* _and;
		BinaryShadowExpression<T>* _then;
		BinaryShadowExpression<T>* _agg;
		BinaryShadowExpression<T>* _defuzz;
		NaryShadowExpression<T>* _sugeno;
	};

	template<class T>
	FuzzyFactory<T>::~FuzzyFactory()
	{
		delete _and;
		delete _or;
		delete _then;
		delete _agg;
		delete _defuzz;
		delete _not;
		delete _sugeno;
	};

	template <class T> ValueModel<T>* FuzzyFactory<T>::newValue(T val) {
		return new ValueModel<T>(val);
	};

	template<class T>
	Expression<T>* FuzzyFactory<T>::newAnd(Expression<T>* l, Expression<T>* r) {
		return newBinary(_and, l, r);
	};

	template<class T>
	Expression<T>* FuzzyFactory<T>::newOr(Expression<T>* l, Expression<T>* r) {
		return newBinary(_or , l, r);
	};

	template<class T>
	Expression<T>* FuzzyFactory<T>::newThen(Expression<T>* l, Expression<T>* r) {
		return this->newBinary(_then, l, r);
	};

	template<class T>
	Expression<T>* FuzzyFactory<T>::newAgg(Expression<T>* l, Expression<T>* r) {
		return this->newBinary(_agg, l, r);
	};


	template<class T>
	Expression<T>* FuzzyFactory<T>::newNot(Expression<T>* o) {
		return this->newUnary(_not, o);
	};

	template<class T>
	Expression<T>* FuzzyFactory<T>::newDefuzz(Expression<T>* l, Expression<T>* r, const T& min, const T& max, const T& step) {
        CogDefuzz<T>* cogdefuzz=(CogDefuzz<T>*) _defuzz->getTarget();
		cogdefuzz->setMin(min);
		cogdefuzz->setMax(max);
		cogdefuzz->setStep(step);
		return this->newBinary(_defuzz, l, r);
	};


	template<class T>
	Expression<T>* FuzzyFactory<T>::newIs(Expression<T>* o, Is<T>* i) {
		return this->newUnary(i, o);
	};

	template<class T>
	void FuzzyFactory<T>::changeAnd(And<T>* o) {
		_and->setTarget(o);
	};

	template<class T>
	void FuzzyFactory<T>::changeOr(Or<T>* o) {
		_or->setTarget(o);
	};

	template<class T>
	void FuzzyFactory<T>::changeThen(Then<T>* o) {
		_then->setTarget(o);
	};

	template<class T>
	void FuzzyFactory<T>::changeAgg(Agg<T>* o) {
		_agg->setTarget(o);
	};

	template<class T>
	void FuzzyFactory<T>::changeNot(Not<T>* o) {
		_not->setTarget(o);
	};

	template<class T>
	void FuzzyFactory<T>::changeSugeno(NaryExpression<T>* o) {
		_sugeno->setTarget(o);
	};

	template<class T>
	void FuzzyFactory<T>::changeDefuzz(BinaryExpression<T>* o) {
		_defuzz->setTarget(o);
	};
}
#endif