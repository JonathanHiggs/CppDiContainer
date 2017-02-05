#pragma once


#include <sstream>

#include "ILogFormatter.h"


namespace Common {
	namespace Logging {

		class LogFormatter : public ILogFormatter
		{
		public:
			virtual std::string Format(LogLevel level, std::string name, std::string message) const
			{
				std::stringstream ss;
				ss << "[" << StringFromLevel(level) << "][" << name << "] " << message << std::endl;
				return ss.str();
			}
		};

	}
}