#include "Bootstrap\DiContainer.h"

using namespace Common::Logging;


namespace Bootstrap {

	DiContainer::DiContainer(LoggerCPtr logger)
		: IRegistrar(logger)
	{}


	DiResult DiContainer::ResolveAs(std::type_info const & sharedPtrType)
	{
		auto pair = items.find(sharedPtrType);
		return pair == items.end() ? nullptr : pair->second->Resolve(*this);
	}


	void DiContainer::RegisterAs(std::type_info const & sharedPtrType, std::shared_ptr<IDiItem> const & item)
	{
		std::type_index type(sharedPtrType);
		items.insert(ItemMap::value_type(type, item));
	}


	std::ostream& operator<< (std::ostream& os, DiContainer const & container)
	{
		for (auto pair : container.items)
		{
			os << Util::ClassName(pair.first) << " : " << *pair.second << std::endl;
		}
		return os;
	}
}