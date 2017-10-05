#ifndef _MEMORY_MANAGER_H_
#define _MEMORY_MANAGER_H_

#include "Defines.h"

namespace Everdrive
{
	typedef BYTE ( *Z80ReadMemory )( WORD );
	typedef void ( *Z80WriteMemory )( WORD, BYTE );
	typedef BYTE ( *Z80IOReadMemory )( BYTE );
	typedef void ( *Z80IOWriteMemory ) (BYTE, BYTE );


	class MemoryManager
	{
	public:
		static MemoryManager& Instance()
		{
			static MemoryManager instance;
			return instance;
		}

		MemoryManager()     {}
		~MemoryManager()    {}

		void Init();

		BYTE ReadMemory( const WORD& address );
		void WriteMemory( const WORD& address, const BYTE& data );
		BYTE ReadIOMemory( const WORD& address );
		void WriteIOMemory( const WORD& address, const BYTE& data );

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