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


/* Adapted from: http://turncoder.blogspot.co.uk/2014/02/a-simple-c11-ioc-container-thats-all.html */


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
	container->Register<ServiceA>(ServiceA::DiCreate).AsMany();
	container->Register<ServiceB>(ServiceB::DiCreate).AsSinglePerGraph();
	container->Register<ServiceC>(ServiceC::DiCreate);
	container->Register<ServiceD>(ServiceD::DiCreate);

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