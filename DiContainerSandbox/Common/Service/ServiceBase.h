#pragma once


#include "..\logging.h"
#include <memory>
#include <string>


namespace Service {

	class ServiceBase
	{
	public:
		ServiceBase(Common::Logging::LoggerCPtr logger)
			: logger(logger)
		{ };

		~ServiceBase() {};

		virtual void Init() = 0;

	protected:
		Common::Logging::LoggerCPtr logger;
	};
}