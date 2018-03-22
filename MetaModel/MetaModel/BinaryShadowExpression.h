#ifndef BINARYSHADOWEXPRESSION_H
#define BINARYSHADOWEXPRESSION_H

using namespace core;
template <class T>
class BinaryShadowExpression : public BinaryExpression{
    public:
        BinaryShadowExpression();
        T evaluate(Expression<T>* l,Expression<T>* r);
    private:
        BinaryExpression<T> target;
}

public T BinaryShadowExpression::evaluate(Expression<T>* l,Expression<T>* r){
    if target==null throw NullOperatorException;
    target.evaluate(l,r);
}

#endif