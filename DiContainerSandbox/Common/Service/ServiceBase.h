#pragma once


#include <memory>
#include <string>

#include "Common\logging.h"
#include "Bootstrap\IResolver.h"


namespace Common {
	namespace Service {

		class ServiceBase
		{
		public:
			ServiceBase(Common::Logging::LoggerCPtr logger)
				: logger(logger), initted(false)
			{ };

			virtual ~ServiceBase() {};

			void Init()
			{
				if (!initted)
				{
					OnInit();
					initted = true;
				}
				else
				{
					logger->Info("Already initted");
				}
			}

		protected:
			virtual void OnInit() = 0;

			Common::Logging::LoggerCPtr logger;

		private:
			bool initted;
		};

	}
}