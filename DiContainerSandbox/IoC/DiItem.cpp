#include "DiItem.h"


namespace IoC {

	DiItem::DiItem()
		: type(&typeid(nullptr))
	{}


	DiItem::DiItem(nullptr_t)
		: DiItem()
	{}

}