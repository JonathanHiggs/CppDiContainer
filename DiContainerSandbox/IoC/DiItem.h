#pragma once


#include <memory>
#include <typeinfo>
#include <cstddef>


namespace IoC {
	
	class DiItem
	{
	public:
		DiItem();

		DiItem(std::nullptr_t);

		template<class T>
		DiItem(std::shared_ptr<T> item)
			: type(&typeid(T)), item(item)
		{}

		~DiItem() {};

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