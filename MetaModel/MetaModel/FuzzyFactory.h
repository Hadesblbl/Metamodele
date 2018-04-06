#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H


template<class T>
class FuzzyFactory : ExpressionFactory<T>{
    public:

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
    return newBinary(and,l,r);
}

template<class T>
    return newBinary(or,l,r);
}

template<class T>
    return newBinary(then,l,r);
}

template<class T>
    return newBinary(agg,l,r);
}

template<class T>
    return newBinary(defuzz,l,r);
}

template<class T>
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