#pragma once


#include "Bootstrap\DiCreate.h"
#include "Bootstrap\IDiItem.h"


namespace Bootstrap {

	class DiItemMany : public IDiItem
	{
	public:
		DiItemMany(DiCreates::Constructor create);

		virtual ~DiItemMany() {};

		virtual DiResult Resolve(IResolver & resolver);

	protected:
		virtual void PrintConfig(std::ostream& os) const;

	private:
		const DiCreates::Constructor create;
	};

}