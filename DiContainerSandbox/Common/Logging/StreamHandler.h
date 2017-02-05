#pragma once


#include "ILogHandler.h"
#include "ILogFormatter.h"


namespace Common {
	namespace Logging {

		class StreamHandler : public ILogHandler
		{
		public:
			StreamHandler(std::ostream& os, ILogFormatterPtr formatter);

			virtual void Write(LogLevel level, std::string name, std::string message);

		private:
			std::ostream& os;
			ILogFormatterPtr formatter;
		};

	}
}