#pragma once


#include "ServiceBase.h"


namespace Service {

	class ServiceB : public ServiceBase
	{
	public:
		ServiceB(Common::Logging::LoggerCPtr logger)
			: ServiceBase(logger)
		{};

		~ServiceB() {};

		virtual void Init()
		{
			logger->Info("Init ServiceB");
		}
	};
}