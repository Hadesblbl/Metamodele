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
		FuzzyFactory(Not<T>* not , And<T>* and, Or<T>* or , Then<T>* then, Agg<T>* agg, CogDefuzz<T>* defuzz) : _not(not), _and(and), _or(or ), _then(then), _agg(agg), _defuzz(defuzz) {};
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
		BinaryShadowExpression<T>* _and;
		BinaryShadowExpression<T>* _or ;
		BinaryShadowExpression<T>* _then;
		BinaryShadowExpression<T>* _agg;
		BinaryShadowExpression<T>* _defuzz;
		UnaryShadowExpression<T>* _not;
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
		return newBinary(and, l, r);
	};

	template<class T>
	Expression<T>* FuzzyFactory<T>::newOr(Expression<T>* l, Expression<T>* r) {
		return newBinary(or , l, r);
	};

	template<class T>
	Expression<T>* FuzzyFactory<T>::newThen(Expression<T>* l, Expression<T>* r) {
		return newBinary(then, l, r);
	};

	template<class T>
	Expression<T>* FuzzyFactory<T>::newAgg(Expression<T>* l, Expression<T>* r) {
		return newBinary(agg, l, r);
	};

	template<class T>
	Expression<T>* FuzzyFactory<t>::newDefuzz(Expression<T>* l, Expression<T>* r, const T& min, const T& max, const T& step) {
		r->setMin(min);
		r->setMax(max);
		r->setStep(step);
		return newBinary(defuzz, l, r);
	};

	template<class T>
	Expression<T>* FuzzyFactory<T>::newNot(Expression<T>* o) {
		return newUnary(not, o);
	};

	template<class T>
	Expression<T>* FuzzyFactory<T>::newIs(Expression<T>* o, Is<T>* i) {
		return newUnary(i, o);
	};

	template<class T>
	void FuzzyFactory<T>::changeAnd(And<T>* o) {
		and.setTarget(o);
	};

	template<class T>
	void FuzzyFactory<T>::changeOr(Or<T>* o) {
		or .setTarget(o);
	};

	template<class T>
	void FuzzyFactory<T>::changeThen(Then<T>* o) {
		then.setTarget(o);
	};

	template<class T>
	void FuzzyFactory<T>::changeAgg(Agg<T>* o) {
		agg.setTarget(o);
	};

	template<class T>
	void FuzzyFactory<T>::changeNot(Not<T>* o) {
		not.setTarget(o);
	};
}
#endif

//Pensez a ajouter les sugenoDefuzz, SugenoConclusion, MamdaniDefuzz