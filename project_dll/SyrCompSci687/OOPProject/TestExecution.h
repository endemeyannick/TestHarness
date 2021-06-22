//Luke Davitt
// CIS 687 Adv OOP
// Syracuse University
// 05/02/2021


#include <vector>
#include <string>
//#include "ThreadTest.h"
//#include "Test.h"
#include <sstream>
#include <thread>
#include <memory>
#include <algorithm>
#include "TestLibrary.h"

using std::vector;
using std::string;
using std::stringstream;

#pragma once

class TestExecution
{
	private:
		vector<ThreadTest*> _threadTests;
		vector<Test*> _tests;
		int _passed = 0;
		int _failed = 0;
		bool _clear = false;
		string _passedMsg = "";
		string _failedMsg = "";
		void outputResults(vector<Test*>);

	public:
		void addThreadTest(string, int);
		void addTest(string);
		void run();
		int size();
		string getResults();
		void reset();
};

