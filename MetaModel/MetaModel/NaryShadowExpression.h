#ifndef NARYSHADOWEXPRESSION_H
#define NARYSHADOWEXPRESSION_H

using namespace core;
template <class T>
class NaryShadowExpression : public NaryExpression{
    public:
        NaryShadowExpression();
        T evaluate(Expression<T>[] *);
        void setTarget(NaryExpression<T>*);
    private:
        NaryExpression<T> target;
}

public T NaryShadowExpression<T>::evaluate(Expression<T>[]* o){
    if (target==null) throw NullOperatorException;
    target.evaluate(o);
}

#endif