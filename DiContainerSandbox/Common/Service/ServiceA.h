#pragma once


#include "ServiceBase.h"


namespace Service {

	class ServiceA : public ServiceBase
	{
	public:
		ServiceA(Common::Logging::LoggerCPtr logger)
			: ServiceBase(logger)
		{};

		~ServiceA() {};

		virtual void Init()
		{
			logger->Info("Init ServiceA");
		};
	};
}

