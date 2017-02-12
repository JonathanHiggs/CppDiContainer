#pragma once

#include "Bootstrap\DiCreate.h"
#include "Bootstrap\DiItems\IDiItem.h"


namespace Bootstrap {
	namespace DiItems {

		class DiItemSinglePerGraph : public IDiItem
		{
		public:
			DiItemSinglePerGraph(DiCreates::Constructor const create, std::type_info const & type);

			virtual ~DiItemSinglePerGraph() {};

			virtual DiResult Resolve(IContextResolver & resolver);

			const DiCreates::Constructor & GetCreate() const;

		protected:
			virtual void PrintConfig(std::ostream& os) const;

		private:
			const DiCreates::Constructor create;
		};

		DECLARE_POINTERS(DiItemSinglePerGraph);

	}
}