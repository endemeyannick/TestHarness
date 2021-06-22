#include "TestExecution.h"
#include <fstream>

class TestLogResult
{

private:
	const string LOGFILE = "TestResultFile.txt"; 

public:
	TestLogResult() {
		std::ofstream testResultFile;

		testResultFile.open(LOGFILE, std::ios_base::app);

		testResultFile << "#################################################\n";
		testResultFile << "#                                               #\n";
		testResultFile << "#   Welcome to the Test Harness Log             #\n";
		testResultFile << "#                                               #\n";
		testResultFile << "#################################################\n";

		testResultFile.close();
	}

	void LogToFile(TestExecution result);
	//void LogtoDb();
};

	
