#pragma once


#include <memory>

#include "IResolver.h"
#include "DiResult.h"


namespace Bootstrap {

	template<class T>
	class IDiItem
	{
	public:
		virtual std::shared_ptr<T> Resolve(IResolver & resolver) = 0;
	};

}