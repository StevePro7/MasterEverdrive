#include "FileManager.h"
#include "Defines.h"
#include <stdio.h>

namespace Everdrive
{
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

		fread(cartridgeMemory, 1, ONE_MEGA_BYTE, in);
		fclose(in);
	}

	//void FileManager::InsertCartridge(const char* path, RomCartridge* cartridge)
	//{
	//	FILE *in = NULL;

	//	// get the file size
	//	in = fopen( path, "rb" );
	//	fseek( in, 0L, SEEK_END );
	//	long endPos = ftell( in );
	//	fclose(in);

	//	in = fopen( path, "rb" );
	//	endPos = endPos % 16384 ;

	//	fread(cartridge->m_CartridgeMemory, 1, ONE_MEGA_BYTE, in);
	//	fclose(in);
	//}
}