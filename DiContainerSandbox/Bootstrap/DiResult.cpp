#include "DiResult.h"


namespace Bootstrap {

	DiResult::DiResult()
		: type(&typeid(nullptr))
	{}


	DiResult::DiResult(nullptr_t)
		: DiResult()
	{}
}