#include "Bootstrap\DiItems\DiItemSinglePerGraph.h"


namespace Bootstrap {
	namespace DiItems {

		DiItemSinglePerGraph::DiItemSinglePerGraph(DiCreates::Constructor const create, std::type_info const & type)
			: IDiItem(type), create(create)
		{}


		DiResult DiItemSinglePerGraph::Resolve(IContextResolver & resolver)
		{
			auto existing = resolver.GetSinglePerGraph(GetType());
			if (existing == nullptr)
			{
				auto result = create(resolver);
				resolver.AddSinglePerGraph(GetType(), result);
				return result;
			}
			else
			{
				return *existing;
			}
		}


		const DiCreates::Constructor & DiItemSinglePerGraph::GetCreate() const
		{
			return create;
		}


		void DiItemSinglePerGraph::PrintConfig(std::ostream& os) const
		{
			os << "Single per graph";
		}
	}
}