#include "Common\Logging\FileHandler.h"


using namespace std;


namespace Common {
	namespace Logging {

		FileHandler::FileHandler(string name, ILogFormatterPtr formatter)
			: fileStream(name), formatter(formatter)
		{}


		FileHandler::~FileHandler()
		{
			fileStream.close();
		}


		void FileHandler::Write(const LogLevel& level, const string& name, const string& message)
		{
			fileStream << formatter->Format(level, name, message);
		}
	}
}