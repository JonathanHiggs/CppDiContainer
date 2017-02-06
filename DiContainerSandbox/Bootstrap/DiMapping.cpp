#include "DiSingleton.h"


using namespace std;


namespace Bootstrap {

	DiSingleton::DiSingleton(DiCreates::Create create)
		: create(create), created(false)
	{}


	DiResult DiSingleton::Resolve(IResolver & resolver)
	{
		if (!created)
		{
			result = create(resolver);
			created = true;
		}

		return result;
	}
}