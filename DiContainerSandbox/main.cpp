#include <iostream>

#include "Bootstrap\DiContainer.h"
#include "Common\logging.h"
#include "Common\Service\ServiceA.h"
#include "Common\Service\ServiceB.h"
#include "Common\Service\ServiceC.h"
#include "Common\Service\ServiceD.h"


using namespace std;
using namespace Bootstrap;
using namespace Common::Logging;
using namespace Common::Service;


LoggingServicePtr setup_logging()
{
	auto loggingService = make_shared<LoggingService>();

	auto formatter = make_shared<LogFormatter>();

	auto streamHandler = make_shared<StreamHandler>(cout, formatter);
	auto fileHandler = make_shared<FileHandler>("log.log", formatter);

	loggingService->AddHandler(streamHandler);
	loggingService->AddHandler(fileHandler);

	return loggingService;
}


DiContainerPtr bootstrap(LoggingServicePtr loggingService)
{
	auto container = make_shared<DiContainer>(loggingService->GetLogger("DiContainer"));
	
	container->Register<DiContainer>(container);
	container->Register<LoggingService>(loggingService);
	container->Register<ServiceA>([](IResolver & r) { return make_shared<ServiceA>(r.Resolve<LoggingService>()->GetLogger("ServiceA")); }).AsMany();
	container->Register<ServiceB>([](IResolver & r) { return make_shared<ServiceB>(r.Resolve<LoggingService>()->GetLogger("ServiceB")); }).AsSinglePerGraph();
	container->Register<ServiceC>([](IResolver & r) { return make_shared<ServiceC>(r.Resolve<ServiceB>(), r.Resolve<LoggingService>()->GetLogger("ServiceC")); });
	container->Register<ServiceD>([](IResolver & r) { return make_shared<ServiceD>(r.Resolve<ServiceB>(), r.Resolve<ServiceC>(), r.Resolve<LoggingService>()->GetLogger("ServiceD")); });

	return container;
}


int main()
{
	auto loggingService = setup_logging();
	auto container = bootstrap(loggingService);
	container->LogMappings();

	auto loggingService2 = container->Resolve<LoggingService>();

	auto serviceA = container->Resolve<ServiceA>();
	serviceA->Init();
	
	auto serviceD = container->Resolve<ServiceD>();
	serviceD->Init();

	container->LogMappings();
}