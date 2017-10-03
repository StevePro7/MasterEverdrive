#ifndef _FILE_MANAGER_H_
#define _FILE_MANAGER_H_

#include "Constants.h"
//#include "../Objects/RomCartridge.h"

namespace Everdrive
{
	class FileManager
	{
	public:
		FileManager()     {}
		~FileManager()    {}

		void InsertCartridge(const char* path, BYTE* cartridgeMemory);
		//void InsertCartridge(const char* path, RomCartridge* cartridge);

	private:
		int memory;
	};
}

#endif//_FILE_MANAGER_H_