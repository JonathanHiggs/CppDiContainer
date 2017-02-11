#pragma once


#include "IResolver.h"
#include "DiResult.h"


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

}