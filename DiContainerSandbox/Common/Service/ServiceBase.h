#pragma once


#include <memory>
#include <string>

#include "Common\logging.h"


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