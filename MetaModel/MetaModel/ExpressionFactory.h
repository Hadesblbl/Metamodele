#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

#include "Expression.h"
#include "UnaryExpression.h"
#include "BinaryExpression.h"
#include "NaryExpression.h"
#include "UnaryExpressionModel.h"
#include "BinaryExpressionModel.h"
#include "NaryExpressionModel.h"
#include <vector>

using namespace std;

namespace core {
	template<class T>
	class ExpressionFactory {
	public:
		//ExpressionFactory() {};
		~ExpressionFactory();
		Expression<T>* hold(Expression<T>*);
		UnaryExpressionModel<T>* newUnary(UnaryExpression<T>*, Expression<T>*);
		BinaryExpressionModel<T>* newBinary(BinaryExpression<T>*, Expression<T>*, Expression<T>*);
		NaryExpressionModel<T>* newNary(NaryExpression<T>*,std::vector<Expression<T>*>);

	private:
		vector<Expression<T>*> memory;
	};

	template<class T>
	ExpressionFactory<T>::~ExpressionFactory() {

        for (typename vector<Expression<T>*>::iterator it = memory.begin(); it != memory.end(); it++)
		{
			delete* it;
		}
	};

	template<class T>
	Expression<T>* ExpressionFactory<T>::hold(Expression<T>* exp) {
		memory.push_back(exp);
		return exp;
	};

	template<class T>
	UnaryExpressionModel<T>* ExpressionFactory<T>::newUnary(UnaryExpression<T>* ope, Expression<T>* o) {
		return new UnaryExpressionModel<T>(ope, o);
	};

	template<class T>
	BinaryExpressionModel<T>* ExpressionFactory<T>::newBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r) {
		return new BinaryExpressionModel<T>(ope, l, r);
	};

	template <class T> 
	NaryExpressionModel<T>* ExpressionFactory<T>::newNary(NaryExpression<T>* ope, std::vector<Expression<T>*> exp) {
		return new NaryExpressionModel<T>(ope, exp);
	};
};
#endif
