#pragma once


#include "Bootstrap\DiItems\DiItemMany.h"
#include "Bootstrap\DiItems\DiItemSingle.h"
#include "Bootstrap\DiItems\DiItemSinglePerGraph.h"
#include "Bootstrap\DiItems\IDiItemConfig.h"


namespace Bootstrap {
	namespace DiItems {

		class DiItemSingleConfig : public IDiItemConfig
		{
		public:
			DiItemSingleConfig(DiItemSinglePtr singleItemPtr, DiItemPtrPtr itemPtr)
				: IDiItemConfig(itemPtr), singleItemPtr(singleItemPtr)
			{};

			void AsMany()
			{
				DiItemMany newItem(singleItemPtr->GetCreate(), singleItemPtr->GetType());
				DiItemPtr newItemPtr = std::make_shared<DiItemMany>(newItem);
				Swap(newItemPtr);
			};

			void AsSinglePerGraph()
			{
				DiItemSinglePerGraph newItem(singleItemPtr->GetCreate(), singleItemPtr->GetType());
				DiItemPtr newItemPtr = std::make_shared<DiItemSinglePerGraph>(newItem);
				Swap(newItemPtr);
			}

		private:
			DiItemSinglePtr singleItemPtr;
		};

	}
}
