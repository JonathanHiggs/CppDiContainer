#include <iostream>
#include "Bootstrap\DiContainer.h"
#include "Common\logging.h"
#include "Common\Service\ServiceA.h"
#include "Common\Service\ServiceB.h"

#include <iomanip>
#include <ctime>

using namespace std;
using namespace Bootstrap;
using namespace Common::Logging;
using namespace Service;


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
	container->Register<ServiceB>([](IResolver & r) { return make_shared<ServiceB>(r.Resolve<LoggingService>()->GetLogger("ServiceB")); });

	return container;
}


int main()
{
	auto loggingService = setup_logging();
	auto container = bootstrap(loggingService);
	container->LogMappings();

	auto container2 = container->Resolve<DiContainer>();
	std::cout << "Container  " << container.get() << std::endl;
	std::cout << "Container2 " << container2.get() << std::endl;

	auto loggingService2 = container->Resolve<LoggingService>();

	auto serviceA = container->Resolve<ServiceA>();
	serviceA->Init();

	auto serviceA2 = container->Resolve<ServiceA>();
	serviceA2->Init();
	
	auto serviceB = container->Resolve<ServiceB>();
	serviceB->Init();

	auto serviceB2 = container->Resolve<ServiceB>();
	serviceB2->Init();

	std::cout << "ServiceA  " << serviceA.get() << std::endl;
	std::cout << "ServiceA2 " << serviceA2.get() << std::endl;
	std::cout << "ServiceB  " << serviceB.get() << std::endl;
	std::cout << "ServiceB2 " << serviceB2.get() << std::endl;
}