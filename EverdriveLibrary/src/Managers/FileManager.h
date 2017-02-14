#ifndef _FILE_MANAGER_H_
#define _FILE_MANAGER_H_

#include "../Constants.h"
#include "../Objects/RomCartridge.h"

namespace Everdrive
{
	class FileManager
	{
	public:
		FileManager()     {}
		~FileManager()    {}

		RomCartridge InsertCartridge();
		void InsertCartridge(const char* path, BYTE* cartridgeMemory);

	private:
		int memory;
	};
}

#endif//_FILE_MANAGER_H_