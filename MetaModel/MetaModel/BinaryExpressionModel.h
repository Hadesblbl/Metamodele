#ifndef BINARYEXPRESSIONMODEL_H
#define BINARYEXPRESSIONMODEL_H
#include "BinaryExpression.h";
#include "Expression.h";

using namespace core;
template <class T>
	class BinaryExpressionModel : public BinaryExpression<T>, public Expression<T> {
	public:
		BinaryExpressionModel

		virtual T evaluate() const;
		virtual T evaluate(Expression<T>*, Expression<T>*) const;

		virtual BinaryExpression<T>* getOpe();
		virtual Expression<T>* getLeft();
		virtual Expression<T>* getRight();
		virtual void setOpe(BinaryExpression<T>*);
		virtual void setLeft(Expression<T>*);
		virtual void setRight(Expression<T>*);
	private:
		BinaryExpression<T> *ope;
		Expression<T> *l;
		Expression<T> *r;
	};

	template <class T>
	T BinaryExpressionModel<T>::evaluate(Expression *l,Expression *r) const {
		if (ope==null) {
			throw NullOperatorException();
		}
		return ope->evaluate(l,r);
	};

	template <class T>
	T BinaryExpressionModel<T>::evaluate() const {
		if (l ==null) {
			throw LeftExpressionException();
		}
		if (r == null) {
			throw RightExpressionException();
		}
		return evaluate(l, r);
	};

	template <class T>
	BinaryExpression<T>* BinaryExpressionModel::getOpe() {
		return this.ope;
	};

	template <class T>
	Expression<T>* BinaryExpressionModel::getLeft() {
		return this.l;
	};

	template <class T>
	Expression<T>* BinaryExpressionModel::getRight() {
		return this.r;
	};

	template <class T>
	void BinaryExpressionModel::setOpe(BinaryExpression<T>* be) {
		ope = be;
	};

	template <class T>
	void BinaryExpressionModel::setLeft(Expression<T>* left) {
		l = left;
	};
#endif /* UNARYEXPRESSIONMODEL_H */