#pragma once


#include "Bootstrap\DiItems\DiItemSingle.h"
#include "Bootstrap\DiItems\DiItemMany.h"
#include "Bootstrap\DiItems\IDiItemConfig.h"


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
