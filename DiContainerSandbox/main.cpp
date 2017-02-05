#include <iostream>
#include "IoC\DiContainer.h"
#include "Common\logging.h"
#include "Common\Service\ServiceA.h"
#include "Common\Service\ServiceB.h"

#include <iomanip>
#include <ctime>

using namespace std;
using namespace IoC;
using namespace Common::Logging;
using namespace Service;


shared_ptr<LoggingService> setup_logging()
{
	auto loggingService = make_shared<LoggingService>();

	auto formatter = make_shared<LogFormatter>();

	auto streamHandler = make_shared<StreamHandler>(cout, formatter);
	auto fileHandler = make_shared<FileHandler>("log.log", formatter);

	loggingService->AddHandler(streamHandler);
	loggingService->AddHandler(fileHandler);

	return loggingService;
}


DiContainer bootstrap(shared_ptr<LoggingService> loggingService)
{
	DiContainer container = DiContainer(loggingService->GetLogger("DiContainer"));

	container.Register<LoggingService>([=](IResolver & r) { return shared_ptr<LoggingService>(loggingService); });
	container.Register<ServiceA>([](IResolver & r) { return make_shared<ServiceA>(r.Resolve<LoggingService>()->GetLogger("ServiceA")); });
	container.Register<ServiceB>([](IResolver & r) { return make_shared<ServiceB>(r.Resolve<LoggingService>()->GetLogger("ServiceB")); });

	return container;
}


int main()
{
	auto loggingService = setup_logging();
	auto container = bootstrap(loggingService);

	auto serviceA = container.Resolve<ServiceA>();
	serviceA->Init();

	auto serviceB = container.Resolve<ServiceB>();
	serviceB->Init();

}