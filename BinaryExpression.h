#ifndef BinaryExpression_h
#define BinaryExpression_h
using namespace core;

template <class T>
class BinaryExpression{
public:
    virtual T evaluate(Expression l,Expression r);
}


#endif /* BinaryExpression_h */
