#ifndef NULLOPERATOREXCEPTION_H
#define NULLOPERATOREXCEPTION_H

#include <exception>

using namespace std;

class NullOperatorException : public exception {
public:
	NullOperatorException() throw(){

	};
};

#endif