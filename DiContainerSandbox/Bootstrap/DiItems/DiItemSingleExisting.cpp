#include "Bootstrap\DiItems\DiItemSingleExisting.h"


namespace Bootstrap {
	namespace DiItems {

		DiItemSingleExisting::DiItemSingleExisting(DiResult result)
			: result(result)
		{}


		DiResult DiItemSingleExisting::Resolve(IContextResolver & resolver)
		{
			return result;
		}


		void DiItemSingleExisting::PrintConfig(std::ostream& os) const
		{
			os << "Single existing";
		}

	}
}