#include "Bootstrap\DiItems\IDiItemConfig.h"


namespace Bootstrap{
	namespace DiItems {

		void IDiItemConfig::Swap(DiItemPtr newItem)
		{
			(*item.get()).swap(newItem);
		}

	}
}