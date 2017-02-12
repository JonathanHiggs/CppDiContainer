#pragma once


#include "Common\Service\ServiceBase.h"
#include "Common\Service\ServiceB.h"
#include "Common\Service\ServiceC.h"


namespace Common {
	namespace Service {

		class ServiceD : public ServiceBase
		{
		public:
			ServiceD(ServiceBPtr serviceB, ServiceCPtr serviceC, Common::Logging::LoggerCPtr logger)
				: ServiceBase(logger), serviceB(serviceB), serviceC(serviceC)
			{};

			virtual ~ServiceD() {};

			virtual void OnInit()
			{
				logger->Info("Init ServiceD");
				serviceB->Init();
				serviceC->Init();
			}


			static std::shared_ptr<ServiceD> DiCreate(Bootstrap::IResolver & r)
			{
				return std::make_shared<ServiceD>(
					r.Resolve<ServiceB>(),
					r.Resolve<ServiceC>(),
					r.Resolve<Common::Logging::LoggingService>()->GetLogger("ServiceD")
					);
			}

		private:
			ServiceBPtr serviceB;
			ServiceCPtr serviceC;
		};

		DECLARE_POINTERS(ServiceC);

	}
}