#pragma once


#include "ServiceBase.h"


namespace Service {

	class ServiceB : public ServiceBase
	{
	public:
		ServiceB(std::shared_ptr<Logger> logger)
			: ServiceBase(logger, "ServiceB")
		{};

		~ServiceB() {};

		virtual void Init()
		{
			logger->Info("Init ServiceB");
		}
	};
}