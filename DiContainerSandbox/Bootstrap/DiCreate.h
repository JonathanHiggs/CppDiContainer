#pragma once


#include <functional>
#include <memory>

#include "Bootstrap\DiResult.h"
#include "Bootstrap\IResolver.h"


namespace Bootstrap {
	namespace DiCreates {

		typedef std::function<DiResult(IResolver & resolver)> Constructor;

		template<class T>
		using CreatedType = std::function<std::shared_ptr<T>(IResolver & resolver)>;

	}
}