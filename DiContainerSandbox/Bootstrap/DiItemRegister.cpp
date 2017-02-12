#include "Bootstrap\DiItemRegister.h"


using namespace Common::Logging;
using namespace Bootstrap::DiItems;


namespace Bootstrap {

	DiItemRegister::DiItemRegister(LoggerCPtr logger)
		: IRegistrar(logger)
	{ }


	DiItems::DiItemPtrPtr DiItemRegister::RegisterAs(std::type_info const & sharedPtrType, DiItemPtr const & item)
	{
		std::type_index type(sharedPtrType);
		DiItemPtrPtr itemPtr = std::make_shared<DiItemPtr>(item);
		itemMap.insert(ItemMap::value_type(type, itemPtr));
		return itemPtr;
	}


	DiItemPtr DiItemRegister::Find(std::type_info const & sharedPtrType)
	{
		auto pair = itemMap.find(sharedPtrType);
		return pair == itemMap.end() ? nullptr : *pair->second.get();
	}


	void DiItemRegister::LogMappings() const
	{
		logger->Info("Mappings table");
		for (auto pair : itemMap)
		{
			std::stringstream line;
			line << ">> " << Util::ClassName(pair.first) << " : " << (*pair.second.get()->get());
			logger->Info(line.str());
		}
	}
}