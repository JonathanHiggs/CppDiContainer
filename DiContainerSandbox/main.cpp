#include <iostream>
#include "IoC\DiContainer.h"
#include "Service\StreamLogger.h"
#include "Service\NamedLogger.h"
#include "Service\ServiceA.h"
#include "Service\ServiceB.h"


using namespace std;
using namespace IoC;
using namespace Service;


DiContainer bootstrap()
{
	auto logger = make_shared<StreamLogger>(cout);

	DiContainer container = DiContainer(make_shared<NamedLogger>(logger, "DiContainer"));

	container.Register<Logger>([=](IResolver & r) { return shared_ptr<Logger>(logger); });
	container.Register<ServiceA>([](IResolver & r) { return make_shared<ServiceA>(r.Resolve<Logger>()); });
	container.Register<ServiceB>([](IResolver & r) { return make_shared<ServiceB>(r.Resolve<Logger>()); });

	return container;
}


int main()
{
	auto container = bootstrap();

	auto logger = make_shared<StreamLogger>(cout);
	auto namedLogger = NamedLogger(logger, "Logger");

	namedLogger.Info("Testing this logger");

	auto serviceA = container.Resolve<ServiceA>();
	serviceA->Init();

	auto serviceB = container.Resolve<ServiceB>();
	serviceB->Init();
}