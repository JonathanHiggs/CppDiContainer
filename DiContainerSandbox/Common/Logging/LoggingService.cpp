#include "LoggingService.h"
#include "Logger.h"


using namespace std;


namespace Common {
	namespace Logging {

		LoggingService::LoggingService()
			: handlers()
		{}


		void LoggingService::AddHandler(LogHandlerPtr handler)
		{
			handlers.push_back(handler);
		}


		LoggerPtr LoggingService::GetLogger(string name) const
		{
			return make_shared<Logger>(name, make_shared<LoggingService>(*this));
		}


		void LoggingService::Debug(string name, string message) const
		{
			Write(LogLevel::Debug, name, message);
		}

		
		void LoggingService::Info(string name, string message) const
		{
			Write(LogLevel::Info, name, message);
		}


		void LoggingService::Warning(string name, string message) const
		{
			Write(LogLevel::Warning, name, message);
		}


		void LoggingService::Exception(string name, string message) const
		{
			Write(LogLevel::Exception, name, message);
		}


		void LoggingService::Write(LogLevel level, string name, string message) const
		{
			for (auto handler : handlers)
				handler->Write(level, name, message);
		}
	}
}