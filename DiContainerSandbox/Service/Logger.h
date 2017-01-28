#pragma once


#include <string>


namespace Service {

	class Logger
	{
	public:
		virtual void Info(std::string message) = 0;
		virtual void Warn(std::string message) = 0;
		virtual void Write(std::string message) = 0;
	};
}