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
		// WTF?

		virtual ~FuzzyFactory();

		Expression<T>* newAnd(Expression<T>*, Expression<T>*);
		Expression<T>* newOr(Expression<T>*, Expression<T>*);
		Expression<T>* newThen(Expression<T>*, Expression<T>*);
		Expression<T>* newAgg(Expression<T>*, Expression<T>*);
		Expression<T>* newDefuzz(Expression<T>*, Expression<T>*, const T&, const T&, const T&);
		Expression<T>* newNot(Expression<T>*);
		Expression<T>* newIs(Expression<T>*, Is<T>*);

		void changeAnd(And<T>*);
		void changeOr(Or<T>*);
		void changeThen(Then<T>*);
		void changeAgg(Agg<T>*);
		void changeNot(Not<T>*);

	private:
		UnaryShadowExpression<T>* _not;
		BinaryShadowExpression<T>* _or;
		BinaryShadowExpression<T>* _and;
		BinaryShadowExpression<T>* _then;
		BinaryShadowExpression<T>* _agg;
		BinaryShadowExpression<T>* _defuzz;

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
		((CogDefuzz<T>*) r)->setMin(min);
		((CogDefuzz<T>*) r)->setMax(max);
		((CogDefuzz<T>*) r)->setStep(step);
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
}
#endif

//Pensez a ajouter les sugenoDefuzz, SugenoConclusion, MamdaniDefuzz
