#include "TestExecution.h"


void TestExecution::addThreadTest(string nam, int dur){
	string name = "ThreadTest " + nam;
	ThreadTest * test = new ThreadTest(name.c_str(), dur);
	_threadTests.push_back(test);
}

void TestExecution::addTest(string nam) {
	string name = "Test " + nam;
	Test* test = new Test(name.c_str());
	_tests.push_back(test);
}

void TestExecution::run() {
	for (const auto& tst : _tests) {
		tst->run();
	}

	//Creates Threads based off how many tests user has requested 

	vector<std::thread> _threadTestsVec;

	for(const auto& tst: _threadTests){
		_threadTestsVec.push_back(std::thread(&ThreadTest::run, tst));
		_tests.push_back(tst);
	}
	std::for_each(_threadTestsVec.begin(), _threadTestsVec.end(), [](std::thread& t)
	{
		t.join();
	});
	outputResults(_tests);
}

string TestExecution::getResults() {
	string results = "The following " + std::to_string(_passed) + " test(s) passed:\n" + _passedMsg;
	results += "\n\nThe following " + std::to_string(_failed) + " test(s) failed:\n" + _failedMsg;
	return results;
}

int TestExecution::size() {
	return _tests.size() + _threadTests.size();
}


void TestExecution::reset() {
	_tests.clear();
	_threadTests.clear();
	_failedMsg = "";
	_failed = 0;
	_passed = 0;
	_passedMsg = "";
}

void TestExecution::outputResults(vector<Test*> _theTests) {
	for (const auto& tst : _theTests) {
		if (tst->passed()) {
			_passed += 1;
			string tmp = tst->getName();
			_passedMsg += tst->getName() + ": passed\n";
		}
		else {
			_failed += 1;
			_failedMsg += tst->getName() + ": failed with exception -- " + tst->getException() + "\n\n\n";
		}
	}
}