#pragma once


#include "ILogHandler.h"
#include "ILogFormatter.h"


namespace Common {
	namespace Logging {

		class StreamHandler : public ILogHandler
		{
		public:
			StreamHandler(std::ostream& os, LogFormatterPtr formatter);

			virtual void Write(LogLevel level, std::string name, std::string message);

		private:
			std::ostream& os;
			LogFormatterPtr formatter;
		};

	}
}