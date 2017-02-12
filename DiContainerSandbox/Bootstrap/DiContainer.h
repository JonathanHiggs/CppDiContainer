#pragma once


#include <typeindex>
#include <unordered_map>

#include "Util\memory.h"
#include "Util\types.h"
#include "Common\logging.h"
#include "Bootstrap\DiResult.h"
#include "Bootstrap\DiItemSingle.h"
#include "Bootstrap\IRegistrar.h"
#include "Bootstrap\IResolver.h"


namespace Bootstrap {

	class DiContainer : public IResolver, public IRegistrar
	{
	public:
		DiContainer(Common::Logging::LoggerCPtr logger);
		~DiContainer() {};

		void LogMappings();

		friend std::ostream& operator<< (std::ostream& os, DiContainer const & container);

	private:
		typedef std::unordered_map<std::type_index, DiItemPtrPtr> ItemMap;
		ItemMap items;

		// IResolver
		virtual DiResult ResolveAs(std::type_info const & sharedPtrType);

		// IRegistrar
		virtual DiItemPtrPtr RegisterAs(
			std::type_info const & sharedPtrType,
			DiItemPtr const & item
		);
	};


	DECLARE_POINTERS(DiContainer);

}