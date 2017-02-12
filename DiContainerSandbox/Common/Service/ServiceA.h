#pragma once


#include "Common\Service\ServiceBase.h"


namespace Common {
	namespace Service {

		class ServiceA : public ServiceBase
		{
		public:
			ServiceA(Common::Logging::LoggerCPtr logger)
				: ServiceBase(logger)
			{};

			virtual ~ServiceA() {};

			virtual void OnInit()
			{
				logger->Info("Init ServiceA");
			};
		};

		DECLARE_POINTERS(ServiceA);

	}
}

