#ifndef BINARYSHADOWEXPRESSION_H
#define BINARYSHADOWEXPRESSION_H

using namespace core;
template <class T>
class BinaryShadowExpression : public BinaryExpression{
    public:
        BinaryShadowExpression();
        T evaluate(Expression<T>*,Expression<T>*);
        void setTarget(BinaryExpression<T>*);
    private:
        BinaryExpression<T> target;
}

public T BinaryShadowExpression<T>::evaluate(Expression<T>* l,Expression<T>* r){
    if (target==null) throw NullOperatorException;
    target.evaluate(l,r);
}

public void BinaryShadowExpression<T>::setTarget(BinaryExpression<T>* t){
    target=t;
}

#endif