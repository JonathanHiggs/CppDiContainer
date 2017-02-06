#pragma once


#include <memory>
#include <string>

#include "Util\memory.h"

#include "LogLevel.h"


namespace Common {
	namespace Logging {

		class ILogFormatter 
		{
		public:
			virtual std::string Format(const LogLevel& level, const std::string&name, const std::string& message) const = 0;

		protected:
			std::string StringFromLevel(const LogLevel& level) const
			{
				switch (level)
				{
				case Common::Logging::Debug:
					return "Debug";
				case Common::Logging::Info:
					return "Info";
				case Common::Logging::Warning:
					return "Warning";
				case Common::Logging::Exception:
					return "Exception";
				default:
					return "Unknown";
				}
			}
		};
		
		DECLARE_POINTERS(ILogFormatter);
	}
}