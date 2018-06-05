#ifndef SUGENOTHEN_H
#define SUGENOTHEN_H

#include "Then.h"
#include "Expression.h"

template<class T>
class SugenoThen : public Then{
    public:
        T evaluate(Expression<T> *,Expression<T> *);
        T premiseValue();
    private:
        T premiseValue;
};

#endif