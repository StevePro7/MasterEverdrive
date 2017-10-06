#include "MemoryManager.h"
#include <memory.h>

#define HALF_MEGA_BYTE	 0x80000			//   524,288	512KB

namespace Everdrive
{
	BYTE MemoryManager::ReadMemory( const WORD& address )
	{
		return 0x0;
	}

	void MemoryManager::WriteMemory( const WORD& address, const BYTE& data )
	{
	}

	BYTE MemoryManager::ReadIOMemory( const WORD& address )
	{
		return 0x0;
	}
	void MemoryManager::WriteIOMemory( const WORD& address, const BYTE& data )
	{
	}

	// Potential to remove!
	BYTE ReadByte( WORD address )
	{
		return MemoryManager::Instance().ReadMemory( address );
	}
	void WriteByte( WORD address, BYTE data )
	{
		MemoryManager::Instance().WriteMemory( address, data );
	}
	BYTE ReadIOByte( BYTE address )
	{
		return MemoryManager::Instance().ReadIOMemory( address );
	}
	void WriteIOByte( BYTE address, BYTE data )
	{
		MemoryManager::Instance().WriteIOMemory( address, data );
	}
	// Potential to remove!

	void MemoryManager::Init()
	{
		memset( m_CartridgeMemory, 0, sizeof( m_CartridgeMemory ) );
		memset( m_InternalMemory, 0, sizeof( m_InternalMemory ) );
		memset( m_RamBank, 0, sizeof( m_RamBank ) );

		m_InternalMemory[0xFFFF] = 2 ; // official Sega doc
		m_InternalMemory[0xFFFE] = 1 ; // official Sega doc

		m_FirstBankPage = 0 ;
		m_SecondBankPage = 1 ;
		m_ThirdBankPage = 2 ;

		m_CurrentRam = -1 ;
		m_OneMegCartridge = false ;

		m_FuncPtrRead = &ReadByte ;
		m_FuncPtrWrite = &WriteByte ;
		m_FuncPtrIORead = &ReadIOByte ;
		m_FuncPtrIOWrite = &WriteIOByte ;
	}

	void MemoryManager::Load( const BYTE* cartridgeMemory, long endPos )
	{
		m_OneMegCartridge = ( endPos > HALF_MEGA_BYTE ) ? true : false ;
		memcpy( &m_InternalMemory[0x0], &cartridgeMemory[0x0], FORTYEIGHT_KB ) ;

		m_InternalMemory[0xFFFE] = 0x01 ;
		m_InternalMemory[0xFFFF] = 0x02 ;
	}
}