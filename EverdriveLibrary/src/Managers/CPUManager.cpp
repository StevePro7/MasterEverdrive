#include "CPUManager.h"

namespace Everdrive
{
	void CPUManager::Init()
	{
		CONTEXTZ80* context = &m_ContextZ80;

		context->m_RegisterAF.reg = 0x0 ; // unofficial z80
		context->m_RegisterBC.reg = 0x0  ;// unofficial z80
		context->m_RegisterDE.reg = 0x0  ;// unofficial z80
		context->m_RegisterHL.reg = 0x0  ;// unofficial z80
		context->m_RegisterAFPrime.reg = 0x0  ;// unofficial z80
		context->m_RegisterBCPrime.reg = 0x0  ;// unofficial z80
		context->m_RegisterDEPrime.reg = 0x0  ;// unofficial z80
		context->m_RegisterHLPrime.reg = 0x0  ;// unofficial z80
		context->m_StackPointer.reg = 0xDFF0 ;
		context->m_RegisterIX.reg = 0  ;
		context->m_RegisterIY.reg = 0  ;
		context->m_RegisterI = 0 ;
		context->m_RegisterR = 0 ;
		context->m_ProgramCounter = 0 ;
		context->m_ProgramCounterStart = 0 ;
		context->m_OpcodeCycle = 0;
		context->m_IFF1 = false ;
		context->m_IFF2 = false ;
		context->m_Halted = false ;
		context->m_InteruptMode = 1 ;
		context->m_NMI = false ;
		context->m_NMIServicing = false ;
		context->m_EIPending = false;
	}

	void CPUManager::Execute()
	{
		

		BYTE opcode = 0xF3;
		ExecuteOpcode( opcode );
	}

	void CPUManager::ExecuteOpcode( BYTE opcode )
	{
		IncreaseRReg();
		m_ContextZ80.m_ProgramCounter++ ;

		switch( opcode )
		{
		case 0xF3:
			m_ContextZ80.m_IFF1 = false;
			m_ContextZ80.m_IFF2 = false;
			m_ContextZ80.m_OpcodeCycle = 4;
			break;
		}
	}

	void CPUManager::ExecuteEDOpcode( BYTE opcode1, BYTE opcode2 )
	{
		IncreaseRReg();
		m_ContextZ80.m_ProgramCounter += 2;

		switch( opcode2 )
		{
		case 0x56:
			m_ContextZ80.m_InteruptMode = 1;
			m_ContextZ80.m_OpcodeCycle = 8;
			break;
		}
	}

	void CPUManager::IncreaseRReg()
	{
		if( ( m_ContextZ80.m_RegisterR & 127 ) == 127 )
		{
			m_ContextZ80.m_RegisterR = m_ContextZ80.m_RegisterR & 128;
		}
		else
		{
			m_ContextZ80.m_RegisterR++ ;
		}
	}

}