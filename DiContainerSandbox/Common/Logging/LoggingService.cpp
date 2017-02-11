#include "Common\Logging\LoggingService.h"
#include "Common\Logging\Logger.h"


using namespace std;


namespace Common {
	namespace Logging {

		LoggingService::LoggingService()
			: handlers()
		{}


		void LoggingService::AddHandler(ILogHandlerPtr handler)
		{
			handlers.push_back(handler);
		}


		LoggerPtr LoggingService::GetLogger(string name) const
		{
			return make_shared<Logger>(name, make_shared<LoggingService>(*this));
		}


		void LoggingService::Debug(const string& name, string& message) const
		{
			Write(LogLevel::Debug, name, message);
		}

		
		void LoggingService::Info(const string& name, string& message) const
		{
			Write(LogLevel::Info, name, message);
		}


		void LoggingService::Warning(const string& name, string& message) const
		{
			Write(LogLevel::Warning, name, message);
		}


		void LoggingService::Exception(const string& name, string& message) const
		{
			Write(LogLevel::Exception, name, message);
		}


		void LoggingService::Write(const LogLevel level, const string& name, const string& message) const
		{
			for (auto handler : handlers)
				handler->Write(level, name, message);
		}
	}
}