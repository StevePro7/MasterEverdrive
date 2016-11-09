#ifndef _LOG_MANAGER_H_
#define _LOG_MANAGER_H_

#include <fstream>
using namespace std;

namespace Everdrive
{
	class LogManager
	{
	public:
		LogManager()    {}
		~LogManager()   {}

		void Init();
		void Quit();

		void Write(const char* format, ...);

	private:
		ofstream log;
	};
}

#endif//_LOG_MANAGER_H_