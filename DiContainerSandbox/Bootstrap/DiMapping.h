#pragma once


#include <memory>

#include "DiCreate.h"


namespace Bootstrap {

	class DiMapping
	{
	public:
		DiMapping(DiCreates::Create create);

		DiMapping& SetSingleton(bool val);
		
		std::shared_ptr<DiResult> Get(IResolver & resolver);

	private:
		const DiCreates::Create create;
		std::shared_ptr<DiResult> result;
		bool singleton;
	};
}