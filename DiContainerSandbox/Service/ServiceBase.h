#pragma once


#include "Logger.h"
#include <memory>


namespace Service {

	class ServiceBase
	{
	public:
		ServiceBase(std::shared_ptr<Logger> logger)
			: logger(logger)
		{};

		~ServiceBase() {};

		virtual void Init() = 0;

	protected:
		const std::shared_ptr<Logger> logger;
	};
}