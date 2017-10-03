#ifndef _ROM_CARTRIDGE_H_
#define _ROM_CARTRIDGE_H_

#include "Constants.h"
#include "Defines.h"

namespace Everdrive
{
	class RomCartridge
	{
	public:
		RomCartridge() {}
		~RomCartridge()	{}

	public:
		BYTE m_CartridgeMemory[ONE_MEGA_BYTE];
		BYTE m_InternalMemory[SIXTY_FOUR_KB];
	};
}

#endif//_ROM_CARTRIDGE_H_