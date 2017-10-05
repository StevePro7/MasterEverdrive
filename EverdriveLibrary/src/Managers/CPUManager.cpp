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
}