#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

namespace Everdrive
{
	class GameManager
	{
	public:
		GameManager()     {}
		~GameManager()    {}

		void Init();

		unsigned long int GetCyclesThisUpdate() const { return m_CyclesThisUpdate; }
		unsigned long int GetClockInfo() const { return m_ClockInfo; }
		int GetFPS() const { return m_FPS; }
		bool IsPAL() const { return m_IsPAL; }
		bool IsCodeMasters() const { return m_IsCodeMasters; }
		//bool OneMegCartridge() const { return m_OneMegCartridge; }

	private:
		unsigned long int m_CyclesThisUpdate ;
		unsigned long int m_ClockInfo ;
		int m_FPS ;
		bool m_IsPAL ;
		bool m_IsCodeMasters ;
		//bool m_OneMegCartridge ;
	};
}

#endif//_GAME_MANAGER_H_