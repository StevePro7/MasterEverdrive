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

		BYTE ReadMemory( const WORD& address );
		BYTE ReadMemoryImpl( const WORD& address, const bool isCodeMasters, const BYTE* cartridgeMemory, const BYTE* internalMemory, const BYTE& ramBankByte, BYTE firstBankPage, BYTE secondBankPage, BYTE thirdBankPage );

		void WriteMemory( const WORD& address, const BYTE& data );
		void WriteMemoryImpl( const WORD& address, const BYTE& data, const BYTE& page, const bool isCodeMasters, int currentRam, bool oneMegCartridge, bool testC1, bool testC2, bool testF1 );
		BYTE ReadIOMemory( const WORD& address );
		void WriteIOMemory( const WORD& address, const BYTE& data );

		void Init();
		void Load( const BYTE* cartridgeMemory, const long& endPos );

		void DoMemPage( const WORD& address, const BYTE& data );
		void DoMemPageImpl( const WORD& address, const BYTE& data, const bool oneMegCartridge, bool testC1, bool testC2, bool testF1 );

		void DoMemPageCM( const WORD& address, const BYTE& data );
		void DoMemPageCMImpl( const WORD& address, const BYTE& page );

		// Properties.
		BYTE* GetCartridgeMemory() { return m_CartridgeMemory; }
		BYTE* GetInternalMemory() { return m_InternalMemory; }
		BYTE* GetRamBank( BYTE bank ) { return m_RamBank[ bank ]; }
		BYTE GetRamBank( BYTE bank, WORD address ) { return m_RamBank[bank][address]; }
		BYTE GetFirstBankPage() const { return m_FirstBankPage; }
		BYTE GetSecondBankPage() const { return m_SecondBankPage; }
		BYTE GetThirdBankPage() const { return m_ThirdBankPage; }
		int GetCurrentRam() const { return m_CurrentRam; }
		bool OneMegCartridge() const { return m_OneMegCartridge; }

	private:
		BYTE m_CartridgeMemory[ONE_MEGA_BYTE];
		BYTE m_InternalMemory[SIXTY_FOUR_KB] ;
		BYTE m_RamBank[0x2][SIXTEEN_KBYTE] ;
		BYTE m_FirstBankPage ;
		BYTE m_SecondBankPage ;
		BYTE m_ThirdBankPage ;
		bool m_OneMegCartridge ;
		int m_CurrentRam ;

		Z80ReadMemory		m_FuncPtrRead ;
		Z80WriteMemory		m_FuncPtrWrite ;
		Z80IOReadMemory		m_FuncPtrIORead ;
		Z80IOWriteMemory	m_FuncPtrIOWrite ;
	};
}

#endif//_MEMORY_MANAGER_H_