#include "DiContainer.h"


using namespace std;
using namespace Common::Logging;


namespace IoC {

	DiContainer::DiContainer(LoggerCPtr logger)
		: IRegistrar(logger)
	{}


	// IResolver
	DiItem DiContainer::ResolveAs(type_info const & sharedTypeType)
	{
		auto getPair = items.find(sharedTypeType);
		return getPair == items.end() ? nullptr : getPair->second(*this);
	}


	// IRegistrar
	void DiContainer::RegisterAs(type_info const & sharedPtrType, DiCreates::Create const & create, bool isSingleton)
	{
		type_index type(sharedPtrType);

		if (isSingleton)
		{
			auto isCreated = false;
			DiItem singleton;
			auto createdSingleton = [=](IResolver & resolver) mutable {
				if (isCreated)
					return singleton;
				else
				{
					singleton = create(resolver);
					isCreated = true;
					return singleton;
				}
			};
			items.insert(ItemsMap::value_type(type, createdSingleton));
		}
		else
		{
			items.insert(make_pair(type, create));
		}
	}
}