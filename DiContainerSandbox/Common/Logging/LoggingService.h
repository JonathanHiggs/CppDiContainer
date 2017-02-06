#pragma once


#include <memory>
#include <string>
#include <vector>

#include "Util\memory.h"
#include "LogLevel.h"
#include "ILogHandler.h"


namespace Common {
	namespace Logging {
		
		class Logger;
		DECLARE_POINTERS(Logger);
		
		class LoggingService 
		{
		public:
			LoggingService();

			void AddHandler(ILogHandlerPtr handler);
			LoggerPtr GetLogger(std::string name) const;

			void Debug(const std::string& name, std::string& message) const;
			void Info(const std::string& name, std::string& message) const;
			void Warning(const std::string& name, std::string& message) const;
			void Exception(const std::string& name, std::string& message) const;

		private:
			void Write(const LogLevel level, const std::string& name, const std::string& message) const;

			std::vector<ILogHandlerPtr> handlers;
		};

		DECLARE_POINTERS(LoggingService);

	}
}