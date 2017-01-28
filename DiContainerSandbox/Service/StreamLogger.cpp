#include "StreamLogger.h"
#include <sstream>


using namespace std;


namespace Service {

	StreamLogger::StreamLogger(ostream& os)
		: os(os)
	{};


	void StreamLogger::Info(string message)
	{
		Write(FormatMessage(message, "Info"));
	}


	void StreamLogger::Warn(string message)
	{
		Write(FormatMessage(message, "Warn"));
	}


	void StreamLogger::Write(string message)
	{
		os << message;
	}


	std::string StreamLogger::FormatMessage(string message, string alertLevel) const
	{
		stringstream m;
		m << "[" << alertLevel << "] " << message << endl;
		return m.str();
	}
}