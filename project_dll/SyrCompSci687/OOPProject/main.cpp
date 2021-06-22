// Greg Boehler
// Luke Davitt
// Syracuse University
// main
// 5.15.21

#include "TestExecution.h"
#include "TestLogResult.h"
#include <iostream>




using std::cout;
using std::cin;
string choice = "we like tests love em theyre great";
string exitClause = "we do not like tests anymore please get me out of here";
int duration;
int testNumber = 0;
int enterDuration() {
	int dur;
	cout << "Enter the amount of seconds for the test:  ";
	cin >> dur;
	cout << "\n";
	return dur;
}

int main() {
	srand(time(0));
	//welcome banner for the program
	cout << "#################################################" << std::endl;
	cout << "#                                               #" << std::endl;
	cout << "#          Welcome to the Test Harness          #" << std::endl;
	cout << "#                                               #" << std::endl;
	cout << "#################################################" << std::endl;

	TestExecution testHarness;
	TestLogResult testLogger;
	while (choice != exitClause) {
		testNumber += 1;
		cout << "Please select the type of test you would like to run:" << std::endl;
		cout << "Enter 1 to add a Threaded Test run asyncronously" << std::endl;
		cout << "Enter 2 to add a Basic Test run concurrently" << std::endl;
		cout << "Enter r to run the tests" << std::endl;
		cout << "Enter q to leave" << std::endl;
		
		cin >> choice;

		if (choice == "r") {
			if (testHarness.size() > 0) {
				testHarness.run();
				cout << testHarness.getResults();
				testLogger.LogToFile(testHarness);
				testHarness.reset();
			}
			else {
				cout << "You need to actually enter a test if you want to ... test it\nSo do that\n";
			}
		}
		else if (choice == "q") {
			choice = exitClause;
		}
		else if (choice == "1") {
			duration = enterDuration();
			string testName = std::to_string(testNumber);
			testHarness.addThreadTest(testName, duration);
		}else if(choice == "2"){
			string testName = std::to_string(testNumber);
			testHarness.addTest(testName);
		} else {
			cout << "Invalid entry \n\n";

		}
		
	}


	cout << "Goodbye";
}

