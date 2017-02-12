#include "Bootstrap\DiItems\DiItemSingleExisting.h"


namespace Bootstrap {
	namespace DiItems {

		DiItemSingleExisting::DiItemSingleExisting(DiResult result, std::type_info const & type)
			: IDiItem(type), result(result)
		{}


		DiResult DiItemSingleExisting::Resolve(IContextResolver & resolver)
		{
			return result;
		}


		void DiItemSingleExisting::PrintConfig(std::ostream& os) const
		{
			os << "Pre-created singleton";
		}

	}
}