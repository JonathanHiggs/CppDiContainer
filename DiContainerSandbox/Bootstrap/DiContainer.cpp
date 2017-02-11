#include "Bootstrap\DiContainer.h"

using namespace Common::Logging;


namespace Bootstrap {

	DiContainer::DiContainer(LoggerCPtr logger)
		: IRegistrar(logger)
	{}


	DiResult DiContainer::ResolveAs(std::type_info const & sharedPtrType)
	{
		auto pair = items.find(sharedPtrType);
		return pair == items.end() ? nullptr : pair->second->get()->Resolve(*this);
	}


	DiItemPtrPtr DiContainer::RegisterAs(std::type_info const & sharedPtrType, DiItemPtr const & item)
	{
		std::type_index type(sharedPtrType);
		DiItemPtrPtr itemPtr = std::make_shared<DiItemPtr>(item);
		items.insert(ItemMap::value_type(type, itemPtr));
		return itemPtr;
	}


	std::ostream& operator<< (std::ostream& os, DiContainer const & container)
	{
		for (auto pair : container.items)
		{
			os << Util::ClassName(pair.first) << " : " << (*pair.second.get()->get()) << std::endl;
		}
		return os;
	}
}