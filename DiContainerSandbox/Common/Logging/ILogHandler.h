#pragma once


#include <string>

#include "Util\memory.h"
#include "LogLevel.h"


namespace Common {
	namespace Logging {

		class ILogHandler
		{
		public:
			virtual void Write(const LogLevel& level, const std::string& name, const std::string& message) = 0;
		};

		DECLARE_POINTERS(ILogHandler);

	}
}