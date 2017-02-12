#pragma once


#include <typeindex>
#include <unordered_map>

#include "Bootstrap\IResolver.h"
#include "Bootstrap\IRegistrar.h"
#include "Bootstrap\DiItemRegister.h"
#include "Bootstrap\DiItems\DiItemSingle.h"
#include "Bootstrap\DiItems\DiItemSingleConfig.h"
#include "Bootstrap\DiItems\DiItemSingleExisting.h"


namespace Bootstrap {

	class DiContainer : public IResolver
	{
	public:
		DiContainer(Common::Logging::LoggerCPtr logger);

		~DiContainer() {};

		virtual void LogMappings() const;


		template<class T>
		DiItems::DiItemSingleConfig Register(DiCreates::Constructor const & create)
		{
			std::stringstream message;
			message << "Registering " << Util::ClassName<T>();
			logger->Info(message.str());

			auto item = std::make_shared<DiItems::DiItemSingle>(create, typeid(T));
			auto itemPtr = RegisterAs(typeid(T), item);

			return DiItems::DiItemSingleConfig(item, itemPtr);
		};


		template<class TAs, class TOriginal>
		DiItems::DiItemSingleConfig Register(DiCreates::Constructor const & create)
		{
			static_assert(std::is_base_of<TAs, TOriginal>::value, "Types do not derive");

			std::stringstream message;
			message << "Registering " << Util::ClassName<TOriginal>();
			message << " as " << Util::ClassName<TAs>();
			logger->Info(message.str());

			auto item = std::make_shared<DiItems::DiItemSingle>([=](IResolver & r) { return create(r); }, typeid(TAs));
			auto itemPtr = RegisterAs(typeid(TAs), item);

			return DiItems::DiItemSingleConfig(item, itemPtr);
		}


		template<class T>
		void Register(std::shared_ptr<T> instance)
		{
			std::stringstream message;
			message << "Registering instance " << Util::ClassName<T>();
			logger->Info(message.str());

			auto item = std::make_shared<DiItems::DiItemSingleExisting>(DiResult(instance), typeid(T));
			auto itemPtr = RegisterAs(typeid(T), item);
		}


	private:
		// IResolver
		virtual DiResult ResolveAs(std::type_info const & sharedPtrType);

		virtual DiItems::DiItemPtrPtr RegisterAs(
			std::type_info const & sharedPtrType,
			DiItems::DiItemPtr const & item
		);
		
		DiItemRegisterPtr itemRegister;

		const Common::Logging::LoggerCPtr logger;

	};


	DECLARE_POINTERS(DiContainer);

}