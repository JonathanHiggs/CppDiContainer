#pragma once


#include <fstream>
#include <string>

#include "Common\Logging\ILogHandler.h"
#include "Common\Logging\ILogFormatter.h"


namespace Common {
	namespace Logging {

		class FileHandler : public ILogHandler
		{
		public:
			FileHandler(std::string name, ILogFormatterPtr formatter);
			~FileHandler();

			virtual void Write(const LogLevel& level, const std::string& name, const std::string& message);

		private:
			std::ofstream fileStream;
			ILogFormatterPtr formatter;
		};

	}
}