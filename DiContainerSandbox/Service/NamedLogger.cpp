#include "NamedLogger.h"


using namespace std;


namespace Service {

	NamedLogger::NamedLogger(shared_ptr<Logger> logger, string name)
		: name(name), innerLogger(logger)
	{}
	

	void NamedLogger::Info(std::string message)
	{
		innerLogger->Write(FormatMessage(message, "Info"));
	}


	void NamedLogger::Warn(std::string message)
	{
		innerLogger->Write(FormatMessage(message, "Warn"));
	}


	std::string NamedLogger::FormatMessage(std::string message, std::string alertLevel) const
	{
		std::stringstream m;
		m << "[" << alertLevel << "][" << name << "] " << message << endl;
		return m.str();
	}


	void NamedLogger::Write(std::string message)
	{
		innerLogger->Write(message);
	}

}