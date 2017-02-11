#pragma once


#include "Common\Service\ServiceBase.h"


namespace Service {

	class ServiceA : public ServiceBase
	{
	public:
		ServiceA(Common::Logging::LoggerCPtr logger)
			: ServiceBase(logger)
		{};

		~ServiceA() {};

		virtual void OnInit()
		{
			logger->Info("Init ServiceA");
		};
	};
}

