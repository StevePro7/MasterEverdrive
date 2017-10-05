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
	// reg  0x1234
	// hi   0x12
	// lo     0x34
	union REGISTERZ80
	{
		WORD reg ;
		struct
		{
			BYTE lo ;
			BYTE hi ;
		};
	};


	struct CONTEXTZ80
	{
		REGISTERZ80 		m_RegisterAF ;
		REGISTERZ80 		m_RegisterBC ;
		REGISTERZ80 		m_RegisterDE ;
		REGISTERZ80 		m_RegisterHL ;
		REGISTERZ80 		m_RegisterAFPrime ;
		REGISTERZ80 		m_RegisterBCPrime ;
		REGISTERZ80 		m_RegisterDEPrime ;
		REGISTERZ80 		m_RegisterHLPrime ;
		REGISTERZ80 		m_StackPointer ;
		REGISTERZ80			m_RegisterIX ;
		REGISTERZ80			m_RegisterIY ;
		BYTE				m_RegisterI ;
		BYTE				m_RegisterR ;
		WORD				m_ProgramCounter ;
		WORD				m_ProgramCounterStart ;
		BYTE				m_OpcodeCycle ;
		bool				m_Halted ;
		bool				m_IFF1 ;
		bool				m_IFF2 ;
		bool				m_EIPending ;
		int					m_InteruptMode ;
		bool				m_NMI ;
		bool				m_NMIServicing ;
	};
}

#endif//_Z80_H_