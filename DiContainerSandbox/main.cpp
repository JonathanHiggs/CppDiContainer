#include <iostream>
#include "IoC\DiContainer.h"
#include "Service\Logger.h"
#include "Service\ServiceA.h"
#include "Service\ServiceB.h"


using namespace std;
using namespace IoC;
using namespace Service;


DiContainer bootstrap()
{
	DiContainer container = DiContainer();

	container.Register<Logger>([](IResolver & r) { return make_shared<Logger>(cout); });
	container.Register<ServiceA>([](IResolver & r) { return make_shared<ServiceA>(r.Resolve<Logger>()); });
	container.Register<ServiceB>([](IResolver & r) { return make_shared<ServiceB>(r.Resolve<Logger>()); });

	return container;
}


int main()
{
	auto container = bootstrap();

	auto logger = container.Resolve<Logger>();

	logger->Info("Logger resolved");

	auto serviceA = container.Resolve<ServiceA>();
	serviceA->Init();

	auto serviceB = container.Resolve<ServiceB>();
	serviceB->Init();
}