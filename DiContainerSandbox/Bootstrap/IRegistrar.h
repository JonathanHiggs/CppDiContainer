#pragma once


#include <typeinfo>
#include <sstream>

#include "Common\logging.h"

#include "IDiItem.h"
#include "DiSingleton.h"


namespace Bootstrap {

	class IRegistrar
	{
	public:
		IRegistrar(Common::Logging::LoggerCPtr logger)
			: logger(logger)
		{};

		template<class T>
		void Register(DiCreates::Create const & create)
		{
			std::stringstream message;
			message << "Registering " << typeid(T).name();
			logger->Info(message.str());

			RegisterAs(typeid(T), std::make_shared<DiSingleton>(create));
		};

		virtual ~IRegistrar() {};

	protected:
		virtual void RegisterAs(
			std::type_info const & sharedPtrType,
			std::shared_ptr<IDiItem> const & item
		) = 0;

	private:
		Common::Logging::LoggerCPtr logger;
	};

}