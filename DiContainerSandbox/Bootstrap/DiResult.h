#pragma once


#include <iostream>
#include <memory>
#include <typeinfo>


namespace Bootstrap {

	class DiResult
	{
	public:
		DiResult()
			: type(&typeid(nullptr))
		{}

		DiResult(std::nullptr_t)
		{
			std::cout << "Made null ptr result" << std::endl;
		}

		template<class T>
		DiResult(std::shared_ptr<T> item)
			: type(&typeid(T)), item(item)
		{
			std::cout << "Made valid result" << std::endl;
		}

		~DiResult() {};

		template<class T>
		std::shared_ptr<T> Get() {
			std::shared_ptr<T> ret = typeid(T) == *type ? std::static_pointer_cast<T>(item) : nullptr;
			return ret;
		}

	private:
		std::type_info const * type;
		std::shared_ptr<void> item;
	};
}