#pragma once


#include "Bootstrap\DiResult.h"
#include "Bootstrap\IContextResolver.h"


namespace Bootstrap {
	namespace DiItems {

		class IDiItem
		{
		public:
			virtual ~IDiItem() {};

			virtual DiResult Resolve(IContextResolver & resolver) = 0;

			friend std::ostream& operator<< (std::ostream& os, const IDiItem & item)
			{
				item.PrintConfig(os);
				return os;
			}

		protected:
			virtual void PrintConfig(std::ostream& os) const = 0;
		};


		using DiItemPtr = std::shared_ptr<IDiItem>;
		using DiItemPtrPtr = std::shared_ptr<DiItemPtr>;

	}
}