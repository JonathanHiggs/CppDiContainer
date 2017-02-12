#pragma once


#include "Bootstrap\DiResult.h"
#include "Bootstrap\IContextResolver.h"


namespace Bootstrap {
	namespace DiItems {

		class IDiItem
		{
		public:
			IDiItem(std::type_info const & type)
				: type(type)
			{};

			virtual ~IDiItem() {};

			virtual DiResult Resolve(IContextResolver & resolver) = 0;

			std::type_info const & GetType() const { return type; };
			
			friend std::ostream& operator<< (std::ostream& os, const IDiItem & item)
			{
				item.PrintConfig(os);
				return os;
			}

		protected:
			virtual void PrintConfig(std::ostream& os) const = 0;

		private:
			std::type_info const & type;
		};


		using DiItemPtr = std::shared_ptr<IDiItem>;
		using DiItemPtrPtr = std::shared_ptr<DiItemPtr>;

	}
}