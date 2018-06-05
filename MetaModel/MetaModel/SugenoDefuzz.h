#ifndef SUGENODEFUZZ_H
#define SUGENODEFUZZ_H

#include "NaryExpression.h"
#include "Expression.h"

template<class T>
class SugenoDefuzz : public NaryExpression{
    public:
        T* coeff;
        T evaluate(Expression<T>**);
};

#endif