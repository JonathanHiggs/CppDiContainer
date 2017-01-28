#pragma once


#include <typeinfo>
#include <vector>
#include "DiItem.h"


namespace IoC {

	class IResolver
	{
	public:
		virtual ~IResolver() {};

		template<class T>
		std::shared_ptr<T> Resolve()
		{
			return ResolveAs(typeid(T)).Get<T>();
		}

	protected:
		virtual DiItem ResolveAs(std::type_info const & sharedPtrType) = 0;
	};
}