#pragma once


#include <memory>

#include "IDiItem.h"


namespace Bootstrap {

	template<class T>
	class DiSingletonInstance : public IDiItem<T>
	{
	public:
		DiSingletonInstance(std::shared_ptr<T> instance)
			: instance(instance)
		{};

		virtual std::shared_ptr<T> Resolve(IResolver & resolver)
		{
			return instance;
		};

	private:
		std::shared_ptr<T> instance;
	};

}