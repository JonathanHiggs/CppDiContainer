#pragma once


#include <iostream>
#include <string>


namespace Service {

	class Logger
	{
	public:
		Logger(std::ostream& os);

		void Info(std::string message);

	private:
		std::ostream& os;
	};
}