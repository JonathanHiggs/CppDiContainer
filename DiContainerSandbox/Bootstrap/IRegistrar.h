#pragma once


#include <typeinfo>
#include <sstream>

#include "Util\types.h"
#include "Common\logging.h"
#include "Bootstrap\IDiItem.h"
#include "Bootstrap\DiSingleton.h"


namespace Bootstrap {

	class IRegistrar
	{
	public:
		IRegistrar(Common::Logging::LoggerCPtr logger)
			: logger(logger)
		{};


		virtual ~IRegistrar() {};


		template<class T>
		void Register(DiCreates::Constructor const & create)
		{
			std::stringstream message;
			message << "Registering " << Util::ClassName<T>();
			logger->Info(message.str());

			RegisterAs(typeid(T), std::make_shared<DiSingleton>(create));
		};


		template<class TAs, class TOriginal>
		void Register(DiCreates::Constructor const & create)
		{
			static_assert(std::is_base_of<TAs, TOriginal>::value, "Types do not derive");

			std::stringstream message;
			message << "Registering " << Util::ClassName<TOriginal>();
			message << " as " << Util::ClassName<TAs>();
			logger->Info(message.str());

			RegisterAs(typeid(TAs), [=](IResolver & r) { return create(r); });
		}


		template<class T>
		void Register(std::shared_ptr<T> instance)
		{
			std::stringstream message;
			message << "Registering instance " << Util::ClassName<T>();
			logger->Info(message.str());

			RegisterAs(typeid(T), std::make_shared<DiSingleton>(DiResult(instance)));
		}


	protected:
		virtual void RegisterAs(
			std::type_info const & sharedPtrType,
			std::shared_ptr<IDiItem> const & item
		) = 0;


	private:
		Common::Logging::LoggerCPtr logger;
	};

}