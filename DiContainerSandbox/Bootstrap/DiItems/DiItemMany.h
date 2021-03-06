#pragma once


#include "Bootstrap\DiCreate.h"
#include "Bootstrap\DiItems\IDiItem.h"


namespace Bootstrap {
	namespace DiItems {

		class DiItemMany : public IDiItem
		{
		public:
			DiItemMany(const DiCreates::Constructor & create, std::type_info const & type);
			DiItemMany(DiCreates::Constructor&& create, std::type_info const & type);

			virtual ~DiItemMany() {};

			virtual DiResult Resolve(IContextResolver & resolver);

			const DiCreates::Constructor & GetCreate() const;

		protected:
			virtual void PrintConfig(std::ostream& os) const;

		private:
			const DiCreates::Constructor create;
		};

		using DiItemManyPtr = std::shared_ptr<DiItemMany>;

	}
}