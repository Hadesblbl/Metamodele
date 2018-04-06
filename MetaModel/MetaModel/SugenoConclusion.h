#ifndef SUGENOCONCLUSION_H
#define SUGENOCONCLUSION_H

#include "NaryExpression.h"

template<class T>
class SugenoDefuzz : public NaryExpression{
    public:
        T* coeff;
        T evaluate(Expression<T>**);
}

public T SugenoDefuzz::evaluate(Expressions<T>** operands){
    T result=0;
    for(int i=0;i<strlen(coeff);i++){
        result+=coeff[i] * operands[i];
    }
    return result;
}
#endif