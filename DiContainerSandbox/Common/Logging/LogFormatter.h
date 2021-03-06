#pragma once


#include <string>
#include <sstream>
#include <ctime>

#include "Common\Logging\ILogFormatter.h"


namespace Common {
	namespace Logging {

		class LogFormatter : public ILogFormatter
		{
		public:
			virtual std::string Format(const LogLevel& level, const std::string& name, const std::string& message) const
			{
				auto t = std::time(nullptr);
				std::tm timeinfo;
				localtime_s(&timeinfo, &t);
				char buffer[80];
				strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", &timeinfo);
				std::string time_str(buffer);
				
				std::stringstream ss;
				ss << "[" << time_str << "][" << StringFromLevel(level) << "][" << name << "] " << message << std::endl;
				return ss.str();
			}
		};

	}
}