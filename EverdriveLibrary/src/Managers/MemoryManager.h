#ifndef _MEMORY_MANAGER_H_
#define _MEMORY_MANAGER_H_

#include "Defines.h"

namespace Everdrive
{
	typedef BYTE ( *Z80ReadMemory )( WORD );
	typedef BYTE ( *Z80WriteMemory )( WORD );
	typedef BYTE ( *Z80IOReadMemory )( BYTE );
	typedef void ( *Z80IOWriteMemory ) (BYTE, BYTE );


	class MemoryManager
	{
	public:
		MemoryManager()     {}
		~MemoryManager()    {}

		void Init();
		BYTE* GetCartridgeMemory() { return m_CartridgeMemory; }
		BYTE* GetInternalMemory() { return m_InternalMemory; }

	private:
		BYTE m_CartridgeMemory[ONE_MEGA_BYTE];
		BYTE m_InternalMemory[SIXTY_FOUR_KB] ;

		Z80ReadMemory		m_FuncPtrRead ;
		Z80WriteMemory		m_FuncPtrWrite ;
		Z80IOReadMemory		m_FuncPtrIORead ;
		Z80IOWriteMemory	m_FuncPtrIOWrite ;
	};
}

#endif//_MEMORY_MANAGER_H_