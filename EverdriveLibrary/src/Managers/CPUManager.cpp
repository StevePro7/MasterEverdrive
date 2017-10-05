#include "CPUManager.h"

namespace Everdrive
{
	void CPUManager::Reset()
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
	}
}