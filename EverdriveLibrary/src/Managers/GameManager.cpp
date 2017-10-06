#include "GameManager.h"

namespace Everdrive
{
	void GameManager::Init()
	{
		m_CyclesThisUpdate = 0 ;
		m_ClockInfo = 0 ;
		m_FPS = 60;
		m_IsPAL = true;
		m_IsCodeMasters = false;
		//m_OneMegCartridge = false ;
	}
}