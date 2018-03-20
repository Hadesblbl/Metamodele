#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H


template<class T>
class FuzzyFactory : ExpressionFactory<T>{
    public:
        Expression<T> newAnd(Expression<T>,Expression<T>);
        Expression<T> newOr(Expression<T>,Expression<T>);
        Expression<T> newThen(Expression<T>,Expression<T>);
        Expression<T> newAgg(Expression<T>,Expression<T>);
        Expression<T> newDefuzz(Expression<T>,Expression<T>);
        Expression<T> newNot(Expression<T>);
        Expression<T> newIs(Is,Expression<T>);

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
}

template<class T>
public Expression<T> FuzzyFactory::newAnd(Expression<T> l,Expression<T> r){
    return newBinary(and,l,r);
}

template<class T>
public Expression<T> FuzzyFactory::newOr(Expression<T> l,Expression<T> r){
    return newBinary(or,l,r);
}

template<class T>
public Expression<T> FuzzyFactory::newThen(Expression<T> l,Expression<T> r){
    return newBinary(then,l,r);
}

template<class T>
public Expression<T> FuzzyFactory::newAgg(Expression<T> l,Expression<T> r){
    return newBinary(agg,l,r);
}

template<class T>
public Expression<T> FuzzyFactory::newDefuzz(Expression<T> l,Expression<T> r){
    return newBinary(defuzz,l,r);
}

template<class T>
public Expression<T> FuzzyFactory::newNot(Expression<T> o){
    return newUnary(not,o);
}

public void FuzzyFactory::changeAnd(And o){
    and.setTarget(o);
}

public void FuzzyFactory::changeOr(Or o){
    or.setTarget(o);
}

public void FuzzyFactory::changeThen(Then o){
    then.setTarget(o);
}

public void FuzzyFactory::changeAgg(Agg o){
    agg.setTarget(o);
}
#endif