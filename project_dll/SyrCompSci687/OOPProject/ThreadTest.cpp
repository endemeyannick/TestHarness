#include "ThreadTest.h"

ThreadTest::ThreadTest() {}

ThreadTest::ThreadTest(string n, int s) {
	self = this;
	_threadDuration = s*1000;
	_displayThread = s;
	_name = n;
}

int ThreadTest::getThreadDuration() {
	return _threadDuration;
}

void ThreadTest::run() {
	static std::mutex mutex; // this needs to be static, otherwise the class creates a new mutex every instance and defeats the whole purpose
	mutex.lock();
	std::cout <<" "<< getName()  <<" with " << _displayThread << " seconds is starting."<<std::endl;
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
	std::cout << " " << getName() << " with " << _displayThread << " seconds is now sleeping. " << std::endl;
	mutex.unlock();
	Sleep(_threadDuration);
	mutex.lock();
	std::cout << " " << getName() << " with " << _displayThread << " seconds is finishing. " << std::endl;
	mutex.unlock();
}