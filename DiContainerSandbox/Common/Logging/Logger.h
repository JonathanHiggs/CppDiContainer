#pragma once


#include <memory>
#include <string>

#include "LoggingService.h"


namespace Common {
	namespace Logging {

		class Logger
		{
		public:
			Logger(std::string name, std::shared_ptr<LoggingService> service);
			
			void Debug(std::string message) const;
			void Info(std::string message) const;
			void Warning(std::string message) const;
			void Exception(std::string message) const;

		private:
			std::string name;
			std::shared_ptr<LoggingService> service;
		};
	}
}