#include "Bootstrap\DiItems\DiItemSingle.h"


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


	const DiCreates::Constructor & DiItemSingle::GetCreate() const
	{
		return create;
	}


	void DiItemSingle::PrintConfig(std::ostream& os) const
	{
		os << "Single instance mapping";
		if (created)
			os << " (created)";
	}
}