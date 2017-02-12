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


			static std::shared_ptr<ServiceC> DiCreate(Bootstrap::IResolver & r)
			{
				return std::make_shared<ServiceC>(
					r.Resolve<ServiceB>(),
					r.Resolve<Common::Logging::LoggingService>()->GetLogger("ServiceC")
					);
			}

		private:
			ServiceBPtr serviceB;
		};

		DECLARE_POINTERS(ServiceC);

	}
}