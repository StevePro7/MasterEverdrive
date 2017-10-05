#include "CPUManager.h"

namespace Everdrive
{
	void CPUManager::Reset()
	{
		m_ContextZ80.m_RegisterAF.reg = 0x0;
		m_ContextZ80.m_RegisterBC.reg = 0x0;
		m_ContextZ80.m_RegisterDE.reg = 0x0;
		m_ContextZ80.m_RegisterHL.reg = 0x0;
	}
}