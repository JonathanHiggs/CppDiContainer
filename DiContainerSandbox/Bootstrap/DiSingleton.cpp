#include "DiSingleton.h"


namespace Bootstrap {

	DiSingleton::DiSingleton(DiCreates::Constructor create)
		: create(create), created(false)
	{}


	DiSingleton::DiSingleton(DiResult instance)
		: instance(instance), created(true)
	{}


	DiResult DiSingleton::Resolve(IResolver & resolver)
	{
		if (!created)
		{
			instance = create(resolver);
			created = true;
		}

		return instance;
	}

	void DiSingleton::PrintConfig(std::ostream& os) const
	{
		os << "Singleton";
	}
}