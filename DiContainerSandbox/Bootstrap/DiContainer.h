#pragma once


#include <typeindex>
#include <unordered_map>

#include "Common\logging.h"

#include "DiResult.h"
#include "DiMapping.h"
#include "IRegistrar.h"
#include "IResolver.h"


namespace Bootstrap {

	class DiContainer : public IResolver, public IRegistrar
	{
	public:
		DiContainer(Common::Logging::LoggerCPtr logger);
		~DiContainer() {};

	private:
		typedef std::unordered_map<std::type_index, DiMapping> ItemMap;
		ItemMap items;

		virtual DiResult ResolveAs(std::type_info const & sharedPtrType);

		virtual void RegisterAs(
			std::type_info const & sharedPtrType,
			DiMapping const & item
		);
	};

}