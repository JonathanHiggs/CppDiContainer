#include "DiMapping.h"


using namespace std;


namespace Bootstrap {

	DiMapping::DiMapping(DiCreates::Create create)
		: create(create), singleton(true), result(nullptr)
	{}


	DiMapping& DiMapping::SetSingleton(bool val)
	{
		singleton = val;
		return *this;
	}


	shared_ptr<DiResult> DiMapping::Get(IResolver & resolver)
	{
		if (singleton && result == nullptr)
		{
			result = make_shared<DiResult>(create(resolver));
			return result;
		}
		else if (singleton && result != nullptr)
		{
			return result;
		}
		else
		{
			return make_shared<DiResult>(create(resolver));
		}
	}
}