#pragma once


#include <memory>
#include <string>
#include <vector>

#include "..\..\Util\memory.h"
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

			void Debug(std::string name, std::string message) const;
			void Info(std::string name, std::string message) const;
			void Warning(std::string name, std::string message) const;
			void Exception(std::string name, std::string message) const;

		private:
			void Write(LogLevel level, std::string name, std::string message) const;

			std::vector<ILogHandlerPtr> handlers;
		};

		DECLARE_POINTERS(LoggingService);

	}
}