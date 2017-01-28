#pragma once


#include "ServiceBase.h"


namespace Service {

	class ServiceA : public ServiceBase
	{
	public:
		ServiceA(std::shared_ptr<Logger> logger)
			: ServiceBase(logger)
		{};

		~ServiceA() {};

		virtual void Init()
		{
			logger->Info("Init ServiceA");
		};
	};
}

