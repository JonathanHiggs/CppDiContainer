#pragma once


#include "..\Common\logging.h"
#include <memory>
#include <string>


namespace Service {

	class ServiceBase
	{
	public:
		ServiceBase(std::shared_ptr<Common::Logging::Logger> logger)
			: logger(logger)
		{ };

		~ServiceBase() {};

		virtual void Init() = 0;

	protected:
		std::shared_ptr<Common::Logging::Logger> logger;
	};
}