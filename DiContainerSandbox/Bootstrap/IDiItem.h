#pragma once


#include "IResolver.h"
#include "DiResult.h"


namespace Bootstrap {

	class IDiItem
	{
	public:
		virtual DiResult Resolve(IResolver & resolver) = 0;
	};

}