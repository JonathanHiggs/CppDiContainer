#pragma once


#include "Bootstrap\DiItems\IDiItem.h"


namespace Bootstrap {
	namespace DiItems {

		class IDiItemConfig
		{
		public:
			IDiItemConfig(DiItemPtrPtr item)
				: item(item)
			{};

		protected:
			void Swap(DiItemPtr newItem);

		private:
			DiItemPtrPtr item;
		};

	}
}