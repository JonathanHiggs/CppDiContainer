#include "StreamHandler.h"


using namespace std;


namespace Common {
	namespace Logging {

		StreamHandler::StreamHandler(ostream& os, LogFormatterPtr formatter)
			: os(os), formatter(formatter)
		{}


		void StreamHandler::Write(LogLevel level, string name, string message)
		{
			os << formatter->Format(level, name, message);
		}
	}
}