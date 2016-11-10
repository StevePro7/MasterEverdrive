#ifndef _FILE_MANAGER_H_
#define _FILE_MANAGER_H_

#include "../Objects/RomCartridge.h"
//using namespace std;

namespace Everdrive
{
	class FileManager
	{
	public:
		FileManager()     {}
		~FileManager()    {}

		RomCartridge InsertCartridge();

	private:
		int memory;
	};
}

#endif//_FILE_MANAGER_H_