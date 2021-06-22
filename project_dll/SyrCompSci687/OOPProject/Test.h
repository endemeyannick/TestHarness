//Luke Davitt
// CIS 687 Adv OOP
// Syracuse University
// 05/02/2021


#pragma once


#include <vector>
#include <string>
#include "Exception.h"
#include <iostream>
#include <ctime>
#include <windows.h>

using std::vector;
using std::string;

class Test
{
	protected:
		Exception _exception;
		bool _pass;
		string _name;

	public:
		Test();
		Test(string);
		void run();
		bool passed();
		string getException();
		string getName();
};

