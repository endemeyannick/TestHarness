#include "Exception.h"

void Exception::setMessage(string exception) {
	this->_message = exception;
}

string Exception::getMessage() {
	return _message;
}