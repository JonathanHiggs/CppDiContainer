#pragma once


#include <typeindex>
#include <unordered_map>

#include "Bootstrap\IContextResolver.h"
#include "Bootstrap\DiItemRegister.h"


namespace Bootstrap {

	class DiContextResolver : public IContextResolver
	{
	public:
		DiContextResolver(DiItemRegisterPtr const & itemRegister);

		virtual ~DiContextResolver() {};

		virtual DiResult ResolveAs(std::type_info const & sharedPtrType);

		DiResultPtr GetSinglePerGraph(std::type_info const & sharedPtrType) const;
		void AddSinglePerGraph(std::type_info const & sharedPtrType, DiResult const & result);

	private:
		DiItemRegisterPtr itemRegister;

		typedef std::unordered_map<std::type_index, DiResultPtr> ResultMap;
		ResultMap resultMap;
	};

}