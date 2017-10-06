#ifndef _FILE_MANAGER_H_
#define _FILE_MANAGER_H_

#include "Defines.h"

namespace Everdrive
{
	class FileManager
	{
	public:
		FileManager()     {}
		~FileManager()    {}

		void InsertCartridge( const char* path, BYTE* cartridgeMemory, long endPos );
	};
}

#endif//_FILE_MANAGER_H_