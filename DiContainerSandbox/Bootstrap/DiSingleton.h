#pragma once


#include <memory>

#include "DiCreate.h"
#include "IDiItem.h"


namespace Bootstrap {

	class DiSingleton : public IDiItem
	{
	public:
		DiSingleton(DiCreates::Constructor create);
		DiSingleton(DiResult instance);
				
		virtual DiResult Resolve(IResolver & resolver);

	private:
		const DiCreates::Constructor create;
		bool created;
		DiResult instance;
	};
}