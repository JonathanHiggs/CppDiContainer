#pragma once


#include "Bootstrap\DiCreate.h"
#include "Bootstrap\IDiItem.h"


namespace Bootstrap {

	class DiItemSingle : public IDiItem
	{
	public:
		DiItemSingle(DiCreates::Constructor create);
		DiItemSingle(DiResult instance);

		virtual ~DiItemSingle() {};
				
		virtual DiResult Resolve(IResolver & resolver);

	protected:
		virtual void PrintConfig(std::ostream& os) const;

	private:
		const DiCreates::Constructor create;
		bool created;
		DiResult instance;
	};

}