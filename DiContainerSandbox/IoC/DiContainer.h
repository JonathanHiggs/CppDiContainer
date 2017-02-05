#pragma once


#include "IResolver.h"
#include "IRegistrar.h"
#include "..\Common\logging.h"
#include <functional>
#include <memory>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>


namespace IoC {

	class DiContainer : public IResolver, public IRegistrar
	{
	public:
		DiContainer(std::shared_ptr<Common::Logging::Logger> logger);
		~DiContainer() {};

	private:
		typedef std::unordered_multimap<std::type_index, DiCreates::Create> ItemsMap;
		ItemsMap items;

		// IResolver
		virtual DiItem ResolveAs(std::type_info const & sharedPtrType);

		// IRegistrar
		virtual void RegisterAs(
			std::type_info const & sharedPtrType,
			DiCreates::Create const & create,
			bool isSingleton = true
		);
	};
}