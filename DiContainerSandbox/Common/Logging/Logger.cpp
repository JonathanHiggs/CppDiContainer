#include "Logger.h"


using namespace std;


namespace Common {
	namespace Logging {

		Logger::Logger(string name, shared_ptr<LoggingService> service)
			: name(name), service(service)
		{}


		void Logger::Debug(std::string message) const
		{
			service->Debug(name, message);
		}


		void Logger::Info(std::string message) const
		{
			service->Info(name, message);
		}


		void Logger::Warning(std::string message) const
		{
			service->Warning(name, message);
		}


		void Logger::Exception(std::string message) const
		{
			service->Exception(name, message);
		}
	}
}