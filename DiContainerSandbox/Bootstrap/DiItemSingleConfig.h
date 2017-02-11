#pragma once


#include "Bootstrap\DiItemSingle.h"
#include "Bootstrap\DiItemMany.h"
#include "Bootstrap\IDiItemConfig.h"


namespace Bootstrap {

	class DiItemSingleConfig : public IDiItemConfig
	{
	public:
		DiItemSingleConfig(DiItemSinglePtr singleItem, DiItemPtrPtr item)
			: IDiItemConfig(item), singleItem(singleItem)
		{};

		void AsMany()
		{
			DiItemMany newItem(singleItem->GetCreate());
			DiItemPtr newItemPtr = std::make_shared<DiItemMany>(newItem);
			Swap(newItemPtr);
		}

	private:
		DiItemSinglePtr singleItem;
	};

}
