#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H

class FuzzyFactory : ExpressionFactory{
    public:
        Expression newAnd(Expression,Expression);
        Expression newOr(Expression,Expression);
        Expression newThen(Expression,Expression);
        Expression newAgg(Expression,Expression);
        Expression newDefuzz(Expression,Expression);
        Expression newNot(Expression);
        Expression newIs(Is,Expression);

        void changeAnd(And);
        void changeOr(Or);
        void changeThen(Then);
        void changeAgg(Agg);

    private:
        BinaryShadowExpression and;
        BinaryShadowExpression or;
        BinaryShadowExpression then;
        BinaryShadowExpression agg;
        BinaryShadowExpression defuzz;

        UnaryShadowExpression not;
}
public Expression FuzzyFactory::newAnd(Expression l,Expression r){
    return newBinary(and,l,r);
}
public Expression FuzzyFactory::newOr(Expression l,Expression r){
    return newBinary(or,l,r);
}
public Expression FuzzyFactory::newThen(Expression l,Expression r){
    return newBinary(then,l,r);
}
public Expression FuzzyFactory::newAgg(Expression l,Expression r){
    return newBinary(agg,l,r);
}
public Expression FuzzyFactory::newDefuzz(Expression l,Expression r){
    return newBinary(defuzz,l,r);
}
public Expression FuzzyFactory::newNot(Expression o){
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