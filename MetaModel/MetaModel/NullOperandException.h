#ifndef NULLOPERANDEXCEPTION_H
#define NULLOPERANDEXCEPTION_H

#include <exception>
using namespace std;

class NullOperandException : public exception {
public:
	NullOperandException() throw() {

	};
};

#endif