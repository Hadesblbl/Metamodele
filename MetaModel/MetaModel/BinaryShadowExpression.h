#ifndef BINARYSHADOWEXPRESSION_H
#define BINARYSHADOWEXPRESSION_H

#include "NullOperatorException.h"
#include "BinaryExpression.h"
#include "BinaryExpressionModel.h"
#include "Expression.h"
#include <stdexcept>

namespace core
{
	template <class T>
	class BinaryShadowExpression : public BinaryExpression<T> {
	public:
		BinaryShadowExpression(BinaryExpression<T>* target ) : target(target) {};
		virtual ~BinaryShadowExpression() {};
        
		T evaluate(Expression<T>*, Expression<T>*) const;
        BinaryExpression<T>* getTarget();
		void setTarget(BinaryExpression<T>*);
	private:
		BinaryExpression<T>* target;
	};

	template <class T>
    T BinaryShadowExpression<T>::evaluate(Expression<T>* l, Expression<T>* r) const{
		if (target == NULL) throw new NullOperatorException();
		return target->evaluate(l, r);
	}

    template <class T>
    BinaryExpression<T>* BinaryShadowExpression<T>::getTarget() {
        return target;
    }
    
	template <class T>
    void BinaryShadowExpression<T>::setTarget(BinaryExpression<T>* t) {
		target = t;
	}

}

#endif
