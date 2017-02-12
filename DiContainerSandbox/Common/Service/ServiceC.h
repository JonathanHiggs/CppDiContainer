#pragma once


#include "Common\Service\ServiceBase.h"
#include "Common\Service\ServiceB.h"


namespace Common {
	namespace Service {

		class ServiceC : public ServiceBase
		{
		public:
			ServiceC(ServiceBPtr serviceB, Common::Logging::LoggerCPtr logger)
				: ServiceBase(logger), serviceB(serviceB)
			{};

			virtual ~ServiceC() {};

			virtual void OnInit()
			{
				logger->Info("Init ServiceC");
				serviceB->Init();
			}

		private:
			ServiceBPtr serviceB;
		};

		DECLARE_POINTERS(ServiceC);

	}
}