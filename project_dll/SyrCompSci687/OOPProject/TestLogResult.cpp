#include "TestLogResult.h"

 void TestLogResult::LogToFile(TestExecution result)
{

	std::ofstream testResultFile;

	testResultFile.open(LOGFILE, std::ios_base::app);

	testResultFile << result.getResults() << "\n";

	testResultFile.close();
}
