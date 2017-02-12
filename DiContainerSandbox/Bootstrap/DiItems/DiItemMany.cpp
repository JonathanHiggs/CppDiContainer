#include "Bootstrap\DiItems\DiItemMany.h"


namespace Bootstrap {

	DiItemMany::DiItemMany(const DiCreates::Constructor & create)
		: create(create)
	{}


	DiItemMany::DiItemMany(DiCreates::Constructor && create)
		: create(std::move(create))
	{}
	

	DiResult DiItemMany::Resolve(IResolver & resolver)
	{
		return create(resolver);
	}


	void DiItemMany::PrintConfig(std::ostream& os) const
	{
		os << "Many instances mapping";
	}

}