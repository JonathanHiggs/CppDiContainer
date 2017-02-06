#pragma once


#include <typeinfo>
#include <sstream>

#include "Common\logging.h"

#include "DiMapping.h"


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

			DiMapping mapping(create);

			RegisterAs(typeid(T), mapping);
		};

		virtual ~IRegistrar() {};

	protected:
		virtual void RegisterAs(
			std::type_info const & sharedPtrType,
			DiMapping const & item
		) = 0;

	private:
		Common::Logging::LoggerCPtr logger;
	};

}