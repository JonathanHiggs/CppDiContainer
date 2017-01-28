#include "Logger.h"


using namespace std;


namespace Service {

	Logger::Logger(ostream& os)
		: os(os)
	{};


	void Logger::Info(string message)
	{
		os << "Log:  " << message << endl;
	}
}