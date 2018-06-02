#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H

#include "ExpressionFactory.h"

#include "Agg.h"
#include "Not.h"
#include "And.h"
#include "is.h"
#include "Then.h"
#include "Or.h"

#include "UnaryShadowExpression.h"
#include "BinaryShadowExpression.h"
#include "NaryShadowExpression.h"

using namespace core;


namespace fuzzy
{
	template<class T>
	class FuzzyFactory : ExpressionFactory<T> {
	public:
		FuzzyFactory() {};
		FuzzyFactory(Not<T>* _not, And<T>* _and, Or<T>* _or, Then<T>* _then, Agg<T>* _agg, CogDefuzz<T>* _defuzz) : not(_not), and(_then), or(_or), then(_then), agg(_agg), defuzz(_defuzz) {};
		virtual ~FuzzyFactory() {};

		Expression<T> newAnd(Expression<T>*, Expression<T>*);
		Expression<T> newOr(Expression<T>*, Expression<T>*);
		Expression<T> newThen(Expression<T>*, Expression<T>*);
		Expression<T> newAgg(Expression<T>*, Expression<T>*);
		Expression<T> newDefuzz(Expression<T>*, Expression<T>*);
		Expression<T> newNot(Expression<T>*);
		Expression<T> newIs(Is, Expression<T>*);

		void changeAnd(And);
		void changeOr(Or);
		void changeThen(Then);
		void changeAgg(Agg);
		void changeNot(Not);

	private:
		BinaryShadowExpression<T>* and;
		BinaryShadowExpression<T>* or ;
		BinaryShadowExpression<T>* then;
		BinaryShadowExpression<T>* agg;
		BinaryShadowExpression<T>* defuzz;
		UnaryShadowExpression<T> not;
	};

	template<class T>
	FuzzyFactory::~FuzzyFactory()
	{
		delete and;
		delete or;
		delete then;
		delete agg;
		delete defuzz;
		delete not;
	}

	template<class T>
	Expression<T> FuzzyFactory<T>::newAnd(Expression<T>* l, Expression<T>* r) {
		return newBinary(and, l, r);
	}

	template<class T>
	Expression<T> FuzzyFactory<T>::newOr(Expression<T>* l, Expression<T>* r) {
		return newBinary(or , l, r);
	}

	template<class T>
	Expression<T> FuzzyFactory<T>::newThen(Expression<T>* l, Expression<T>* r) {
		return newBinary(then, l, r);
	}

	template<class T>
	Expression<T> FuzzyFactory<T>::newAgg(Expression<T>* l, Expression<T>* r) {
		return newBinary(agg, l, r);
	}

	template<class T>
	Expression<T> FuzzyFactory<t>::newDefuzz(Expression<T>* l, Expression<T>* r) {
		return newBinary(defuzz, l, r);
	}

	template<class T>
	Expression<T> FuzzyFactory<T>::newNot(Expression<T>* o) {
		return newUnary(not, o);
	}

	template<class T>
	Expression<T> FuzzyFactory<T>::newIs(Is<T>* i, Expression<T>* o) {
		return newUnary(i, o);
	}

	template<class T>
	void FuzzyFactory<T>::changeAnd(And o) {
		and.setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeOr(Or o) {
		or .setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeThen(Then o) {
		then.setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeAgg(Agg o) {
		agg.setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeNot(Not o) {
		not.setTarget(o);
	}
}
#endif

//Pensez a ajouter les sugenoDefuzz, SugenoConclusion, MamdaniDefuzz