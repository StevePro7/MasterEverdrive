#include "FileManager.h"
#include "Defines.h"
#include <stdio.h>

namespace Everdrive
{
	void FileManager::InsertCartridge( const char* path, BYTE* cartridgeMemory, long endPos )
	{
		FILE *in = NULL;

		// get the file size
		in = fopen( path, "rb" );
		fseek( in, 0L, SEEK_END );
		endPos = ftell( in );
		fclose(in);

		in = fopen( path, "rb" );
		endPos = endPos % SIXTEEN_KBYTE ;

		if ( ( endPos == 512 ) || ( endPos == 64 ) )
		{
			// we need to strip off the old header in order for the rom to load
			// http://www.smspower.org/forums/viewtopic.php?t=7999&highlight=header+512
			char header[1000] ;
			if ( endPos == 512 )
				fread( header, 1, 512,in ) ;
			else
			{
				fread ( header, 1, 64, in ) ;
			}
		}

		fread( cartridgeMemory, 1, ONE_MEGA_BYTE, in );
		fclose(in);
	}

}