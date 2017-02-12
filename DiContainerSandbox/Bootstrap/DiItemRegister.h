#pragma once


#include <typeindex>
#include <unordered_map>

#include "Util\memory.h"
#include "Bootstrap\IRegistrar.h"


namespace Bootstrap {
	namespace DiItems {

		class IDiItem;
		using DiItemPtr = std::shared_ptr<IDiItem>;
		using DiItemPtrPtr = std::shared_ptr<DiItemPtr>;

	}


	class DiItemRegister : public IRegistrar
	{
	public:
		DiItemRegister(Common::Logging::LoggerCPtr logger);

		virtual ~DiItemRegister() {};

		virtual DiItems::DiItemPtrPtr RegisterAs(
			std::type_info const & sharedPtrType,
			DiItems::DiItemPtr const & item
		);

		DiItems::DiItemPtr Find(std::type_info const & sharedPtrType);
		
		virtual void LogMappings() const;

	private:
		typedef std::unordered_map<std::type_index, DiItems::DiItemPtrPtr> ItemMap;
		ItemMap itemMap;
	};

	DECLARE_POINTERS(DiItemRegister);

}