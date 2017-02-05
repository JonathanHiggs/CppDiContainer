#include "FileHandler.h"


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


		void FileHandler::Write(LogLevel level, string name, string message)
		{
			fileStream << formatter->Format(level, name, message);
		}
	}
}