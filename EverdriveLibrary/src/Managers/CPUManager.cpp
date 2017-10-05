#include "CPUManager.h"

namespace Everdrive
{
	void CPUManager::Reset()
	{
		m_ContextZ80.m_RegisterAF.reg = 0x0;
		m_ContextZ80.m_RegisterBC.reg = 0x0;
		m_ContextZ80.m_RegisterDE.reg = 0x0;
		m_ContextZ80.m_RegisterHL.reg = 0x0;
		m_ContextZ80.m_RegisterAFPrime.reg = 0x0;
		m_ContextZ80.m_RegisterBCPrime.reg = 0x0;
		m_ContextZ80.m_RegisterDEPrime.reg = 0x0;
		m_ContextZ80.m_RegisterHLPrime.reg = 0x0;
		m_ContextZ80.m_StackPointer.reg = 0xDFF0;
		m_ContextZ80.m_RegisterIX.reg = 0;
		m_ContextZ80.m_RegisterIY.reg = 0;
	}
}