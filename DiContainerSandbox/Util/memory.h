#pragma once


#include <memory>


#define DECLARE_POINTERS(x)\
	using x##Ptr = std::shared_ptr<x>;\
	using x##CPtr = std::shared_ptr<x const>;\
	/**/
