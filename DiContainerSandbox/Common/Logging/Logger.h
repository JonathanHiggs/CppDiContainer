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
			
			void Debug(const std::string message) const;
			void Info(const std::string message) const;
			void Warning(const std::string message) const;
			void Exception(const std::string message) const;

		private:
			std::string name;
			std::shared_ptr<LoggingService> service;
		};
	}
}