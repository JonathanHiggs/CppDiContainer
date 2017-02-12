#pragma once


#include "Bootstrap\DiCreate.h"
#include "Bootstrap\DiItems\IDiItem.h"


namespace Bootstrap {

	class DiItemSingle : public IDiItem
	{
	public:
		DiItemSingle(DiCreates::Constructor create);
		DiItemSingle(DiResult instance);

		virtual ~DiItemSingle() {};
				
		virtual DiResult Resolve(IResolver & resolver);

		const DiCreates::Constructor & GetCreate() const;

	protected:
		virtual void PrintConfig(std::ostream& os) const;

	private:
		const DiCreates::Constructor create;
		bool created;
		DiResult instance;
	};

	using DiItemSinglePtr = std::shared_ptr<DiItemSingle>;
	using DiItemSinglePtrPtr = std::shared_ptr<DiItemSinglePtr>;
}