#pragma once


#include "Common\Service\ServiceBase.h"


namespace Service {

	class ServiceB : public ServiceBase
	{
	public:
		ServiceB(Common::Logging::LoggerCPtr logger)
			: ServiceBase(logger)
		{};

		~ServiceB() {};

		virtual void OnInit()
		{
			logger->Info("Init ServiceB");
		}
	};
}