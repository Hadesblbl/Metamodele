#include <exception>;
using namespace std;

class NullOperatorException : public exception {
public:
	NullOperatorException() throw(){

	};
};