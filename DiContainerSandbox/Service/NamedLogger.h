#pragma once


#include "Logger.h"
#include <memory>
#include <sstream>
#include <string>


namespace Service {

	class NamedLogger : public Logger
	{
	public:
		NamedLogger(std::shared_ptr<Logger> logger, std::string name);

		virtual void Info(std::string message);
		virtual void Warn(std::string message);
		virtual void Write(std::string message);
		
	protected:
		std::string FormatMessage(std::string message, std::string alertLevel) const;

	private:
		const std::string name;
		const std::shared_ptr<Logger> innerLogger;
	};

}