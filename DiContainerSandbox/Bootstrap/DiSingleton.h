#pragma once


#include <functional>
#include <memory>

#include "IDiItem.h"
#include "DiCreate.h"


namespace Bootstrap {

	template<class T>
	class DiSingleton : public IDiItem<T>
	{
	public:
		DiSingleton(DiCreates::CreatedType<T> create)
			: create(create)
		{};
				
		virtual std::shared_ptr<T> Resolve(IResolver & resolver)
		{
			if (instance == nullptr)
				instance = create(*this);

			return instance;
		};

	private:
		const DiCreates::CreatedType<T> create;
		std::shared_ptr<T> instance;
	};
}