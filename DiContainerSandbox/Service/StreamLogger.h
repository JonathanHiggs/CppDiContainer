#pragma once


#include "Logger.h"
#include <iostream>


namespace Service {

	class StreamLogger : public Logger
	{
	public:
		StreamLogger(std::ostream& os);

		virtual void Info(std::string message);
		virtual void Warn(std::string message);
		virtual void Write(std::string message);

	protected:
		std::string FormatMessage(std::string message, std::string alertLevel) const;

	private:
		std::ostream& os;
	};
}