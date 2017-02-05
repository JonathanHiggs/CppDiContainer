#pragma once


#include "DiCreates.h"
#include "..\Common\logging.h"
#include <sstream>
#include <typeinfo>


namespace IoC {

	class IRegistrar
	{
	public:
		IRegistrar(std::shared_ptr<Common::Logging::Logger> logger)
			: logger(logger)
		{};

		virtual ~IRegistrar() {};

		template<class T>
		void Register(
			DiCreates::Create const & create,
			bool isSingleton = true
		)
		{
			std::stringstream message;
			message << "Registering " << typeid(T).name();
			logger->Info(message.str());

			RegisterAs(typeid(T), create, isSingleton);
		}

		template<class TAs, class TOriginal>
		void Register(
			DiCreates::CreatedType<TOriginal> const & create,
			bool isSingleton = true
		)
		{
			static_assert(std::is_base_of<TAs, TOriginal>::value, "TAs must be a parent of TOriginal");
			
			std::stringstream message;
			message << "Registering " << typeid(TOriginal).name() << " as " << typeid(TAs).name();
			logger->Info(message.str());

			RegisterAs(typeid(TAs), [=](IResolver & r) { return create(r); }, isSingleton);
		}

	protected:
		virtual void RegisterAs(
			std::type_info const & sharedPtrType,
			DiCreates::Create const & create,
			bool isSingleton = true
		) = 0;

	private:
		std::shared_ptr<Common::Logging::Logger> logger;
	};
}