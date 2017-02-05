#pragma once


#include <memory>


#define DECLARE_POINTERS(x)\
	using x##Ptr = std::shared_ptr<x>;\
	using x##CPtr = std::shared_ptr<x const>;\
	using x##UPtr = std::unique_ptr<x>;\
	using x##UCPtr = std::unique_ptr<x const>;\
	using x##WPtr = std::weak_ptr<x>;\
	using x##WCPtr = std::weak_ptr<x const>;\
	/**/
