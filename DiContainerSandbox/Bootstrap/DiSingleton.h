#pragma once


#include <memory>

#include "Bootstrap\DiCreate.h"
#include "Bootstrap\IDiItem.h"


namespace Bootstrap {

	class DiSingleton : public IDiItem
	{
	public:
		DiSingleton(DiCreates::Constructor create);
		DiSingleton(DiResult instance);

		virtual ~DiSingleton() {};
				
		virtual DiResult Resolve(IResolver & resolver);

	protected:
		virtual void PrintConfig(std::ostream& os) const;

	private:
		const DiCreates::Constructor create;
		bool created;
		DiResult instance;
	};
}