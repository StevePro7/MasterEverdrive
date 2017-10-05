#ifndef _Z80_H_
#define _Z80_H_

#include "Defines.h"

#define FLAG_S 7
#define FLAG_Z 6
//#define FLAG_B5 5
#define FLAG_H 4
//#define FLAG_B3 3
#define FLAG_PV 2
#define FLAG_N 1
#define FLAG_C 0

namespace Everdrive
{
	typedef BYTE ( *Z80ReadMemory )( WORD );
	typedef BYTE ( *Z80WriteMemory )( WORD );
	typedef BYTE ( *Z80IOReadMemory )( BYTE );
	typedef void ( *Z80IOWriteMemory ) (BYTE, BYTE );


	// reg  0x1234
	// hi   0x12
	// lo     0x34
	union REGISTERZ80
	{
		WORD reg;
		struct
		{
			BYTE lo;
			BYTE hi;
		};
	};


	struct CONTEXTZ80
	{
		REGISTERZ80 m_RegisterAF;
		REGISTERZ80 m_RegisterBC;
		REGISTERZ80 m_RegisterDE;
		REGISTERZ80 m_RegisterHL;
	};
}

#endif//_Z80_H_