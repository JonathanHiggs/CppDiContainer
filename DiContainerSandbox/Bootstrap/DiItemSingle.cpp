#include "Bootstrap\DiItemSingle.h"


namespace Bootstrap {

	DiItemSingle::DiItemSingle(DiCreates::Constructor create)
		: create(create), created(false)
	{}


	DiItemSingle::DiItemSingle(DiResult instance)
		: instance(instance), created(true)
	{}


	DiResult DiItemSingle::Resolve(IResolver & resolver)
	{
		if (!created)
		{
			instance = create(resolver);
			created = true;
		}

		return instance;
	}

	void DiItemSingle::PrintConfig(std::ostream& os) const
	{
		os << "Singleton";
	}
}