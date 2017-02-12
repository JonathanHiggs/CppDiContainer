#include "Bootstrap\DiContextResolver.h"


namespace Bootstrap {

	DiContextResolver::DiContextResolver(DiItemRegisterPtr const & itemRegister)
		: itemRegister(itemRegister)
	{ }


	DiResultPtr DiContextResolver::GetSinglePerGraph(std::type_info const & sharedPtrType) const
	{
		auto pair = resultMap.find(sharedPtrType);
		return pair == resultMap.end() ? nullptr : pair->second;
	}


	void DiContextResolver::AddSinglePerGraph(std::type_info const & sharedPtrType, DiResult const & result)
	{
		std::type_index type(sharedPtrType);
		resultMap.insert(ResultMap::value_type(type, std::make_shared<DiResult>(result)));
	}


	DiResult DiContextResolver::ResolveAs(std::type_info const & sharedPtrType)
	{
		auto itemPtr = itemRegister->Find(sharedPtrType);
		return itemPtr->Resolve(*this);
	}
}