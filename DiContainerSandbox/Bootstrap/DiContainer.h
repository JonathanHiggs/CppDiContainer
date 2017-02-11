#pragma once


#include <typeindex>
#include <unordered_map>

#include "Util\types.h"
#include "Common\logging.h"
#include "Bootstrap\DiResult.h"
#include "Bootstrap\DiSingleton.h"
#include "Bootstrap\IRegistrar.h"
#include "Bootstrap\IResolver.h"


namespace Bootstrap {

	class DiContainer : public IResolver, public IRegistrar
	{
	public:
		DiContainer(Common::Logging::LoggerCPtr logger);
		~DiContainer() {};

		friend std::ostream& operator<< (std::ostream& os, DiContainer const & container);

	private:
		typedef std::unordered_map<std::type_index, std::shared_ptr<IDiItem>> ItemMap;
		ItemMap items;

		// IResolver
		virtual DiResult ResolveAs(std::type_info const & sharedPtrType);

		// IRegistrar
		virtual void RegisterAs(
			std::type_info const & sharedPtrType,
			std::shared_ptr<IDiItem> const & item
		);
	};

}