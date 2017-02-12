#pragma once


#include "Common\Service\ServiceBase.h"


namespace Common {
	namespace Service {

		class ServiceB : public ServiceBase
		{
		public:
			ServiceB(Common::Logging::LoggerCPtr logger)
				: ServiceBase(logger)
			{};

			virtual ~ServiceB() {};

			virtual void OnInit()
			{
				logger->Info("Init ServiceB");
			}
		};

		DECLARE_POINTERS(ServiceB);

	}
}