#include "FileManager.h"
#include <stdio.h>

namespace Everdrive
{
	RomCartridge FileManager::InsertCartridge()
	{
		return RomCartridge(1);
	}

	void FileManager::InsertCartridge(const char* path, BYTE* cartridgeMemory)
	{
		FILE *in = NULL;

		// get the file size
		in = fopen( path, "rb" );
		fseek( in, 0L, SEEK_END );
		long endPos = ftell( in );
		fclose(in);

		in = fopen( path, "rb" );
		endPos = endPos % 16384 ;

		fread(cartridgeMemory, 1, 0x10000, in);
		fclose(in);
	}
}