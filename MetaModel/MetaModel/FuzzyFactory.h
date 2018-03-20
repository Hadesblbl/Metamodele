#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H

class FuzzyFactory{
    public:
        Expression newAnd(Expression,Expression);
        Expression newOr(Expression,Expression);
        Expression newIs(Is,Expression);
        Expression newThen(Expression,Expression);
        Expression newAgg(Expression,Expression);
        void changeAnd(And);
        void changeOr(Or);
        void changeThen(Then);

}
#endif