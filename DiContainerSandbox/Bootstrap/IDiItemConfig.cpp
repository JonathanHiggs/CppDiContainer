#include "Bootstrap\IDiItemConfig.h"


namespace Bootstrap{

	void IDiItemConfig::Swap(DiItemPtr newItem)
	{
		(*item.get()).swap(newItem);
	}


	const IDiItem & IDiItemConfig::Current() const
	{
		return (*item.get()->get());
	}
}