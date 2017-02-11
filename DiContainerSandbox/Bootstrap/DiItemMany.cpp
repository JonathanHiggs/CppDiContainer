#include "Bootstrap\DiItemMany.h"


namespace Bootstrap {

	DiItemMany::DiItemMany(DiCreates::Constructor create)
		: create(create)
	{}


	DiResult DiItemMany::Resolve(IResolver & resolver)
	{
		return create(resolver);
	}


	void DiItemMany::PrintConfig(std::ostream& os) const
	{
		os << "Many";
	}

}