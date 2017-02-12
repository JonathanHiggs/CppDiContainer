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

			static std::shared_ptr<ServiceA> DiCreate(Bootstrap::IResolver & r)
			{
				return std::make_shared<ServiceA>(r.Resolve<Common::Logging::LoggingService>()->GetLogger("ServiceA"));
			}
		};

		DECLARE_POINTERS(ServiceA);
		
	}
}

