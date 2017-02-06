#pragma once


#include <functional>
#include <memory>

#include "DiResult.h"
#include "IResolver.h"


namespace Bootstrap {
	namespace DiCreates {

		typedef std::function<DiResult(IResolver & resolver)> Create;

		template<class T>
		using CreatedType = std::function<std::shared_ptr<T>(IResolver & resolver)>;
	}
}