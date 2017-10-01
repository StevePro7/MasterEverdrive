#ifndef _ROM_CARTRIDGE_H_
#define _ROM_CARTRIDGE_H_

#include "../Constants.h"

namespace Everdrive
{
	class RomCartridge
	{
	public:
		RomCartridge() {}
		~RomCartridge()	{}

	public:
		BYTE m_CartridgeMemory[0x100000];
		BYTE m_InternalMemory[0x10000];
	};
}

#endif//_ROM_CARTRIDGE_H_