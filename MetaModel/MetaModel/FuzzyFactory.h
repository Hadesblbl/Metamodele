#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H

class FuzzyFactory : ExpressionFactory{
    public:
        Expression newAnd(Expression,Expression);
        Expression newOr(Expression,Expression);
        Expression newThen(Expression,Expression);
        Expression newAgg(Expression,Expression);
        Expression newDefuzz(Expression,Expression);
        ExpressionModel newNot(Expression);
        Expression newIs(Is,Expression);
        void changeAnd(And);
        void changeOr(Or);
        void changeThen(Then);
        void changeAgg(Agg);
}
#endif