#pragma once


#include <fstream>
#include <string>

#include "ILogHandler.h"
#include "ILogFormatter.h"


namespace Common {
	namespace Logging {

		class FileHandler : public ILogHandler
		{
		public:
			FileHandler(std::string name, LogFormatterPtr formatter);
			~FileHandler();

			virtual void Write(LogLevel level, std::string name, std::string message);

		private:
			std::ofstream fileStream;
			LogFormatterPtr formatter;
		};

	}
}