#pragma once


#include <string>
#include <typeindex>


namespace Util {

	template<class T>
	std::string ClassName()
	{
		std::string name(typeid(T).name());
		return name.substr(6, name.size() - 6);
	}
	

	std::string ClassName(const std::type_index & type);


	std::string ClassName(std::type_index&& type);
}