#pragma once


#include "Bootstrap\IResolver.h"


namespace Bootstrap {

	class IContextResolver : public IResolver
	{
	public:
		virtual DiResultPtr GetSinglePerGraph(std::type_info const & sharedPtrType) const = 0;
		virtual void AddSinglePerGraph(std::type_info const & sharedPtrType, DiResult const & result) = 0;
	};

}