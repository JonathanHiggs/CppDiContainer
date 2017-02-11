#include "Util\types.h"


namespace Util {
	
	std::string ClassName(const std::type_index & type)
	{
		std::string name(type.name());
		return name.substr(6, name.size() - 6);
	}


	std::string ClassName(std::type_index&& type)
	{
		std::string name(type.name());
		return name.substr(6, name.size() - 6);
	}

}