#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H

#include "ExpressionFactory.h"

template<class T>
class FuzzyFactory : ExpressionFactory<T>{
    public:
        FuzzyFactory();
        FuzzyFactory(Not<T>*,And<T>*,Or<T>*,Then<T>*,Or<T>*,CogDefuzz<T>*)
        ~FuzzyFactory();

        Expression<T> newAnd(Expression<T>*,Expression<T>*);
        Expression<T> newOr(Expression<T>*,Expression<T>*);
        Expression<T> newThen(Expression<T>*,Expression<T>*);
        Expression<T> newAgg(Expression<T>*,Expression<T>*);
        Expression<T> newDefuzz(Expression<T>*,Expression<T>*);
        Expression<T> newNot(Expression<T>*);
        Expression<T> newIs(Is,Expression<T>*);

        void changeAnd(And);
        void changeOr(Or);
        void changeThen(Then);
        void changeAgg(Agg);

    private:
        BinaryShadowExpression<T> and;
        BinaryShadowExpression<T> or;
        BinaryShadowExpression<T> then;
        BinaryShadowExpression<T> agg;
        BinaryShadowExpression<T> defuzz;

        UnaryShadowExpression<T> not;
};

template<class T>
Expression<T> FuzzyFactory<T>::newAnd(Expression<T>* l,Expression<T>* r){
    return newBinary(and,l,r);
}

template<class T>
Expression<T> FuzzyFactory<T>::newOr(Expression<T>* l,Expression<T>* r){
    return newBinary(or,l,r);
}

template<class T>
Expression<T> FuzzyFactory<T>::newThen(Expression<T>* l,Expression<T>* r){
    return newBinary(then,l,r);
}

template<class T>
Expression<T> FuzzyFactory<T>::newAgg(Expression<T>* l,Expression<T>* r){
    return newBinary(agg,l,r);
}

template<class T>
Expression<T> FuzzyFactory<t>::newDefuzz(Expression<T>* l,Expression<T>* r){
    return newBinary(defuzz,l,r);
}

template<class T>
Expression<T> FuzzyFactory<T>::newNot(Expression<T>* o){
    return newUnary(not,o);
}

template<class T>
void FuzzyFactory<T>::changeAnd(And o){
    and.setTarget(o);
}

template<class T>
void FuzzyFactory<T>::changeOr(Or o){
    or.setTarget(o);
}

template<class T>
void FuzzyFactory<T>::changeThen(Then o){
    then.setTarget(o);
}

template<class T>
void FuzzyFactory<T>::changeAgg(Agg o){
    agg.setTarget(o);
}
#endif