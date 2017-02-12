#include "Bootstrap\DiItems\DiItemMany.h"


namespace Bootstrap {
	namespace DiItems {

		DiItemMany::DiItemMany(const DiCreates::Constructor & create)
			: create(create)
		{}


		DiItemMany::DiItemMany(DiCreates::Constructor && create)
			: create(std::move(create))
		{}


		DiResult DiItemMany::Resolve(IContextResolver & resolver)
		{
			return create(resolver);
		}


		const DiCreates::Constructor & DiItemMany::GetCreate() const
		{
			return create;
		}


		void DiItemMany::PrintConfig(std::ostream& os) const
		{
			os << "Many instances mapping";
		}

	}
}