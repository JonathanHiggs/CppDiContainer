#pragma once


#include "IResolver.h"
#include "DiItem.h"
#include <functional>
#include <memory>


namespace IoC {
	namespace DiCreates {

		typedef std::function<DiItem(IResolver & resolver)> Create;

		template<class T>
		using CreatedType = std::function<std::shared_ptr<T>(IResolver & resolver)>;

	}
}