#pragma once


#include "Bootstrap\IResolver.h"
#include "Bootstrap\DiResult.h"


namespace Bootstrap {

	class IDiItem
	{
	public:
		virtual ~IDiItem() {};

		virtual DiResult Resolve(IResolver & resolver) = 0;

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