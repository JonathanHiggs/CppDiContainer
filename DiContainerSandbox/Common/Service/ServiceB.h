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

			static std::shared_ptr<ServiceB> DiCreate(Bootstrap::IResolver & r)
			{
				return std::make_shared<ServiceB>(r.Resolve<Common::Logging::LoggingService>()->GetLogger("ServiceB"));
			}
		};

		DECLARE_POINTERS(ServiceB);

	}
}