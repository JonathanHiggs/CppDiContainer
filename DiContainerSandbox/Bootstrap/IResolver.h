#pragma once


#include <typeinfo>

#include "DiMapping.h"
#include "DiResult.h"


namespace Bootstrap {

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
		virtual DiResult ResolveAs(std::type_info const & sharedPtrType) = 0;
	};
}