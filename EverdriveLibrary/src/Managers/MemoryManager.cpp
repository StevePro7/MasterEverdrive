#include "MemoryManager.h"
#include "Engine.h"
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
		const BYTE page = Engine::Instance().UtilManager().BitResetPages( data );
		bool isCodeMasters = Engine::Instance().GameManager().IsCodeMasters();

		bool testC1 = Engine::Instance().UtilManager().TestBit( data, 3 );
		bool testC2 = Engine::Instance().UtilManager().TestBit( data, 2 );
		bool testF1 = Engine::Instance().UtilManager().TestBit( m_InternalMemory[0xFFFC], 3 );

		WriteMemoryImpl( address, data, page, isCodeMasters, m_CurrentRam, m_OneMegCartridge, testC1, testC2, testF1 );
	}
	void MemoryManager::WriteMemoryImpl( const WORD& address, const BYTE& data, const BYTE& page, const bool isCodeMasters, int currentRam, bool oneMegCartridge, bool testC1, bool testC2, bool testF1 )
	{
		if( isCodeMasters )
		{
			if( address == 0x0000 || address == 0x4000 || address == 0x8000 )
			{
				DoMemPageCMImpl( address, page );
			}
		}

		// cant write to rom
 		if ( address < 0x8000 )
 		{
 			return ;
 		}

		// only allow writing to here if a ram bank is mapped into this slot
 		else if ( address < 0xC000 )
 		{
			if ( currentRam > -1 )
 			{
				WORD mirrorAddress = address - 0x8000;			// subtract 32KB
				m_RamBank[ currentRam ][ mirrorAddress ] = data ;
 				return ;
 			}
 			else
 			{
 				// this is rom so lets return
 				return ;
 			}
		}

		m_InternalMemory[address] = data ;
		if ( address >= 0xFFFC )
		{
			if ( !isCodeMasters )
			{
				DoMemPageImpl( address, data, oneMegCartridge, testC1, testC2, testF1 );
			}
		}

		// if you uncomment the following crap, you need to find out what happens to the rom/ram banking with mirroring
		// for example if address == 0xDFFF then mirroring with overwrite 0xFFFF which is a ram bank. Should I allow this?
		if ( address >= 0xC000 && address < 0xDFFC )
		{
			WORD mirrorAddress = address + 0x2000;			// add 8KB
			m_InternalMemory[ mirrorAddress ] = data ;
		}
		if ( address >= 0xE000 )
		{
			WORD mirrorAddress = address - 0x2000;			// subtract 8KB
			m_InternalMemory[ mirrorAddress ] = data ;
		}
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

		m_OneMegCartridge = false ;
		m_CurrentRam = -1 ;

		m_FuncPtrRead = &ReadByte ;
		m_FuncPtrWrite = &WriteByte ;
		m_FuncPtrIORead = &ReadIOByte ;
		m_FuncPtrIOWrite = &WriteIOByte ;
	}

	void MemoryManager::Load( const BYTE* cartridgeMemory, const long& endPos )
	{
		m_OneMegCartridge = ( endPos > HALF_MEGA_BYTE ) ? true : false ;
		memcpy( &m_InternalMemory[0x0], &cartridgeMemory[0x0], FORTYEIGHT_KB ) ;

		m_InternalMemory[0xFFFE] = 0x01 ;
		m_InternalMemory[0xFFFF] = 0x02 ;
	}

	void MemoryManager::DoMemPage( const WORD& address, const BYTE& data )
	{
		bool testC1 = Engine::Instance().UtilManager().TestBit( data, 3 );
		bool testC2 = Engine::Instance().UtilManager().TestBit( data, 2 );
		bool testF1 = Engine::Instance().UtilManager().TestBit( m_InternalMemory[0xFFFC], 3 );

		DoMemPageImpl( address, data, m_OneMegCartridge, testC1, testC2, testF1 );
	}

	void MemoryManager::DoMemPageImpl( const WORD& address, const BYTE& data, const bool oneMegCartridge, bool testC1, bool testC2, bool testF1 )
	{
		if( address < 0xFFFC )
		{
			return;
		}

		BYTE page = oneMegCartridge ? data & 0x3F : data & 0x1F ;

		// Update RAM mirror 
		WORD mirrorAddress = address - 0x2000;			// 8KB
		m_InternalMemory[ mirrorAddress ] = data;

		// Process address.
		switch( address )
		{
		case 0xFFFC: 
			{
				// check for slot 2 ram banking
				// if( TestBit( data, 3 ) )
				if( testC1 )
				{
					// which of the two ram banks are we swapping in?
					// if( TestBit( data, 2 ) )
					if ( testC2 )
						m_CurrentRam = 1 ;
					else
						m_CurrentRam = 0 ;
				}
				else
				{
					m_CurrentRam = -1;
				}
				
			}
			break ;

		case 0xFFFD: 
			m_FirstBankPage = page ; 
			break ;

		case 0xFFFE:
			m_SecondBankPage = page ; 
			break ;

		case 0xFFFF:
			{
				// only allow rom banking in slot 2 if ram is not mapped there!
				// if( !TestBit( context->m_InternalMemory[0xFFFC], 3 ) )
				if( !testF1 )
				{
					m_ThirdBankPage = page;
				}
				break ;
			}
		}
	}

	void MemoryManager::DoMemPageCM( const WORD& address, const BYTE& data )
	{
		BYTE page = Engine::Instance().UtilManager().BitResetPages( data );
		DoMemPageCMImpl( address, page );
	}
	void MemoryManager::DoMemPageCMImpl( const WORD& address, const BYTE& page )
	{
		switch(address)
		{
		case 0x0:
			m_FirstBankPage = page ; 
			break ;

		case 0x4000: 
			m_SecondBankPage = page ; 
			break ;

		case 0x8000: 
			m_ThirdBankPage = page ; 
			break ;
		}
	}
}