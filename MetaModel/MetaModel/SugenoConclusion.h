#ifndef SUGENOCONCLUSION_H
#define SUGENOCONCLUSION_H

#include "NaryExpression.h"
#include "Expression.h"

template<class T>
class SugenoDefuzz : public NaryExpression{
    public:
        T* coeff;
        T evaluate(Expression<T>**);
};

template <class T>
T SugenoDefuzz::evaluate(Expressions<T>** operands){
    T result=0;
    for(int i=0;i<strlen(coeff);i++){
        result+=coeff[i] * operands[i];
    }
    return result;
};
#endif