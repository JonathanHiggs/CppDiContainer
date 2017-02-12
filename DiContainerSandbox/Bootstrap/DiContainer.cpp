#include "Bootstrap\DiContainer.h"
#include "Bootstrap\DiContextResolver.h"
#include <sstream>

using namespace Common::Logging;
using namespace Bootstrap::DiItems;

namespace Bootstrap {

	DiContainer::DiContainer(LoggerCPtr logger)
		: itemRegister(std::make_shared<DiItemRegister>(logger)), logger(logger)
	{}


	DiResult DiContainer::ResolveAs(std::type_info const & sharedPtrType)
	{
		DiContextResolver resolver(itemRegister);
		return resolver.ResolveAs(sharedPtrType);
	}


	DiItemPtrPtr DiContainer::RegisterAs(std::type_info const & sharedPtrType, DiItemPtr const & itemPtr)
	{
		return itemRegister->RegisterAs(sharedPtrType, itemPtr);
	}


	void DiContainer::LogMappings() const
	{
		itemRegister->LogMappings();
	}
}