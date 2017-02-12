#include "Bootstrap\DiItems\DiItemSingle.h"


namespace Bootstrap {
	namespace DiItems {

		DiItemSingle::DiItemSingle(DiCreates::Constructor create)
			: create(create), created(false)
		{}


		DiResult DiItemSingle::Resolve(IResolver & resolver)
		{
			if (!created)
			{
				result = create(resolver);
				created = true;
			}

			return result;
		}


		bool DiItemSingle::IsCreated() const
		{
			return created;
		}


		const DiCreates::Constructor & DiItemSingle::GetCreate() const
		{
			return create;
		}


		void DiItemSingle::PrintConfig(std::ostream& os) const
		{
			os << "Single result mapping";
			if (created)
				os << " (created)";
		}

	}
}