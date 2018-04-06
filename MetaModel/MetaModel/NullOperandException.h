#include <exception>;
using namespace std;

class NullOperandException : public exception {
public:
	NullOperandException() throw() {

	};
};