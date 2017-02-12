#pragma once


#include "Bootstrap\DiItems\DiItemMany.h"
#include "Bootstrap\DiItems\DiItemSingle.h"
#include "Bootstrap\DiItems\IDiItemConfig.h"


namespace Bootstrap {
	namespace DiItems {

		class DiItemManyConfig : public IDiItemConfig
		{
		public:
			DiItemManyConfig(DiItemManyPtr manyItemPtr, DiItemPtrPtr itemPtr)
				: IDiItemConfig(itemPtr), manyItemPtr(manyItemPtr)
			{};

			void AsSingle()
			{
				DiItemSingle singleItem(manyItemPtr->GetCreate());
				DiItemPtr newItemPtr = std::make_shared<DiItemSingle>(singleItem);
				Swap(newItemPtr);
			}

		private:
			DiItemManyPtr manyItemPtr;
		};

	}
}