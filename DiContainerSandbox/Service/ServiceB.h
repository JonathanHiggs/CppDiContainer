#pragma once


#include "ServiceBase.h"


namespace Service {

	class ServiceB : public ServiceBase
	{
	public:
		ServiceB(std::shared_ptr<Common::Logging::Logger> logger)
			: ServiceBase(logger)
		{};

		~ServiceB() {};

		virtual void Init()
		{
			logger->Info("Init ServiceB");
		}
	};
}