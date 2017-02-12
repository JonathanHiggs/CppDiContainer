#pragma once


#include "Bootstrap\DiCreate.h"
#include "Bootstrap\DiItems\IDiItem.h"


namespace Bootstrap {
	namespace DiItems {

		class DiItemSingleExisting : public IDiItem
		{
		public:
			DiItemSingleExisting(DiResult result);

			virtual ~DiItemSingleExisting() {};

			virtual DiResult Resolve(IContextResolver & resolver);

		protected:
			virtual void PrintConfig(std::ostream& os) const;
			
		private:
			DiResult result;
		};

		using DiItemSingleExistingPtr = std::shared_ptr<DiItemSingleExisting>;

	}
}