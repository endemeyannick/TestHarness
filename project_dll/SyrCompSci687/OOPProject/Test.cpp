#include "Test.h"

Test::Test() {}

Test::Test(string nam) {
	_name = nam;
}

void Test::run() {
	
	int max;
	srand(time(0));
	max = 100;
	int result = rand() % max;
	if (result % 2 == 0) {
		_pass = true;
	}
	else {
		_pass = false;
	}
}

bool Test::passed()
{
	return _pass;
};

string Test::getException() {
	return _exception.getMessage();
}

string Test::getName() {
	return _name;
}