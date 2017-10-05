#include "MemoryManager.h"
#include <memory.h>

namespace Everdrive
{
	void MemoryManager::Init()
	{
		memset( m_CartridgeMemory, 0, ONE_MEGA_BYTE );
		memset( m_InternalMemory, 0, SIXTY_FOUR_KB );

		m_InternalMemory[0xFFFF] = 2 ; // official sega doc
		m_InternalMemory[0xFFFE] = 1 ; // official sega doc
	}
}