#include "Common\Logging\StreamHandler.h"


using namespace std;


namespace Common {
	namespace Logging {

		StreamHandler::StreamHandler(ostream& os, ILogFormatterPtr formatter)
			: os(os), formatter(formatter)
		{}


		void StreamHandler::Write(const LogLevel& level, const string& name, const string& message)
		{
			os << formatter->Format(level, name, message);
		}
	}
}