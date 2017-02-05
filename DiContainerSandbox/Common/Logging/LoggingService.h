#pragma once


#include <memory>
#include <string>
#include <vector>

#include "LogLevel.h"
#include "ILogHandler.h"


namespace Common {
	namespace Logging {

		using LogHandlerPtr = std::shared_ptr<ILogHandler>;

		class Logger;
		
		class LoggingService 
		{
		public:
			LoggingService();

			void AddHandler(LogHandlerPtr handler);
			Logger GetLogger(std::string name) const;

			void Debug(std::string name, std::string message) const;
			void Info(std::string name, std::string message) const;
			void Warning(std::string name, std::string message) const;
			void Exception(std::string name, std::string message) const;

		private:
			void Write(LogLevel level, std::string name, std::string message) const;

			std::vector<LogHandlerPtr> handlers;
		};

	}
}