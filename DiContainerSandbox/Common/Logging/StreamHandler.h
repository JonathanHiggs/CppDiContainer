#pragma once


#include "Common\Logging\ILogHandler.h"
#include "Common\Logging\ILogFormatter.h"


namespace Common {
	namespace Logging {

		class StreamHandler : public ILogHandler
		{
		public:
			StreamHandler(std::ostream& os, ILogFormatterPtr formatter);

			virtual void Write(const LogLevel& level, const std::string& name, const std::string& message);

		private:
			std::ostream& os;
			ILogFormatterPtr formatter;
		};

	}
}