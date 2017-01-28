#pragma once


#include "Logger.h"
#include <memory>
#include <string>


namespace Service {

	class ServiceBase
	{
	public:
		ServiceBase(std::shared_ptr<Logger> logger, std::string serviceName)
			: logger(std::shared_ptr<Logger>(new NamedLogger(logger, serviceName)))
		{ };

		~ServiceBase() {};

		virtual void Init() = 0;

	protected:
		const std::shared_ptr<Logger> logger;
	};
}