#pragma once


#include "Bootstrap\DiCreate.h"
#include "Bootstrap\DiItems\IDiItem.h"


namespace Bootstrap {

	class DiItemMany : public IDiItem
	{
	public:
		DiItemMany(const DiCreates::Constructor & create);
		DiItemMany(DiCreates::Constructor&& create);

		virtual ~DiItemMany() {};

		virtual DiResult Resolve(IResolver & resolver);

	protected:
		virtual void PrintConfig(std::ostream& os) const;

	private:
		const DiCreates::Constructor create;
	};


	using DiItemManyPtr = std::shared_ptr<DiItemMany>;
	using DiItemManyPtrPtr = std::shared_ptr<DiItemManyPtr>;
}