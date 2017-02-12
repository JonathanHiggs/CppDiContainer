#pragma once


#include <typeinfo>
#include <sstream>

#include "Util\types.h"
#include "Common\logging.h"
#include "Bootstrap\DiItems\IDiItem.h"


namespace Bootstrap {

	class IRegistrar
	{
	public:
		IRegistrar(Common::Logging::LoggerCPtr logger)
			: logger(logger)
		{};


		virtual ~IRegistrar() {};

		
		virtual void LogMappings() const = 0;
		

	protected:
		virtual DiItems::DiItemPtrPtr RegisterAs(
			std::type_info const & sharedPtrType,
			DiItems::DiItemPtr const & item
		) = 0;

		const Common::Logging::LoggerCPtr logger;
	};

}