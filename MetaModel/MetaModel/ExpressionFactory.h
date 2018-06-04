#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

#include "Expression.h"
#include "UnaryExpression.h"
#include "BinaryExpression.h"
#include "NaryExpression.h"
#include "UnaryExpressionModel.h"
#include "BinaryExpressionModel.h"
#include <vector>

using namespace std;

namespace core {
	template<class T>
	class ExpressionFactory {
	public:
		//ExpressionFactory() {};
		~ExpressionFactory();
		Expression<T>* hold(Expression<T>*);
		Expression<T>* newUnary(UnaryExpression<T>*, Expression<T>*);
		Expression<T>* newBinary(BinaryExpression<T>*, Expression<T>*, Expression<T>*);
		//Expression<T>* newNary(NaryExpression<T>*,std::vector<Expression<T>*>*);

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
	Expression<T>* ExpressionFactory<T>::newUnary(UnaryExpression<T>* ope, Expression<T>* o) {
		return this->hold(new UnaryExpressionModel<T>(ope, o));
	};

	template<class T>
	Expression<T>* ExpressionFactory<T>::newBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r) {
		return this->hold(new BinaryExpressionModel<T>(ope, l, r));
	};
}
//newNary

#endif
