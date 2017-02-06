#pragma once


#include <memory>

#include "DiCreate.h"
#include "IDiItem.h"


namespace Bootstrap {

	class DiSingleton : public IDiItem
	{
	public:
		DiSingleton(DiCreates::Create create);
				
		virtual DiResult Resolve(IResolver & resolver);

	private:
		const DiCreates::Create create;
		bool created;
		DiResult result;
	};
}