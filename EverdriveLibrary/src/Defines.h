#ifndef _DEFINES_H_
#define _DEFINES_H_

#define ONE_MEGA_BYTE	0x100000
#define SIXTY_FOUR_KB	0x10000
#define SIXTEEN_KBYTE	0x4000

namespace Everdrive
{
	// Config
	typedef unsigned char BYTE;
	typedef signed char SIGNED_BYTE;
	typedef unsigned short int WORD;
	typedef signed short int SIGNED_WORD;

	// Master System
	static const int WINDOWWIDTH = 256;
	static const int WINDOWHEIGHT = 192;
	static const int SCREENSCALE = 1;

	// Emulator
	static const	long long	MACHINE_CLICKS = 10738635;
	static const	int			CPU_CYCLES_TO_MACHINE_CLICKS = 3;
}

#endif//_DEFINES_H_