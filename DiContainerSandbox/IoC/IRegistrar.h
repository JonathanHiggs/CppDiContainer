#pragma once


#include "DiCreates.h"
#include <typeinfo>


namespace IoC {

	class IRegistrar
	{
	public:
		virtual ~IRegistrar() {};

		template<class T>
		void Register(
			DiCreates::Create const & create,
			bool isSingleton = true
		)
		{
			RegisterAs(typeid(T), create, isSingleton);
		}

		template<class TAs, class TOriginal>
		void Register(
			DiCreates::CreatedType<TOriginal> const & create,
			bool isSingleton = true
		)
		{
			static_assert(std::is_base_of<TAs, TOriginal>::value, "TAs must be a parent of TOriginal");
			RegisterAs(typeid(TAs), [=](IResolver & r) { return create(r); }, isSingleton);
		}

	protected:
		virtual void RegisterAs(
			std::type_info const & sharedPtrType,
			DiCreates::Create const & create,
			bool isSingleton = true
		) = 0;
	};
}