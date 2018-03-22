#ifndef SUGENODEFUZZ_H
#define SUGENODEFUZZ_H

#include "NaryExpression.h"

template<class T>
class SugenoDefuzz : public NaryExpression{
    public:
        T[] coeff;
        T evaluate(Expression<T>[] *);
}

#endif