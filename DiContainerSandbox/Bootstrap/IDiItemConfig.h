#pragma once


#include "Bootstrap\IDiItem.h"


namespace Bootstrap {

	class IDiItemConfig
	{
	public:
		IDiItemConfig(DiItemPtrPtr item)
			: item(item)
		{};

	protected:
		void Swap(DiItemPtr newItem);
		const IDiItem & Current() const;
		
	private:
		DiItemPtrPtr item;
	};

}