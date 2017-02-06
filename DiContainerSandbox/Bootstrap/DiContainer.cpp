#include "DiContainer.h"


using namespace std;
using namespace Common::Logging;


namespace Bootstrap {

	DiContainer::DiContainer(LoggerCPtr logger)
		: IRegistrar(logger)
	{}


	DiResult DiContainer::ResolveAs(type_info const & sharedPtrType)
	{
		auto pair = items.find(sharedPtrType);
		return pair == items.end() ? nullptr : pair->second.Get(*this);
	}


	void DiContainer::RegisterAs(type_info const & sharedPtrType, DiMapping const & item)
	{
		type_index type(sharedPtrType);
		items.insert(ItemMap::value_type(type, item));
	}
}