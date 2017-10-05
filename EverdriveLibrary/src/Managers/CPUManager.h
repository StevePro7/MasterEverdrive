#ifndef _CPU_MANAGER_H_
#define _CPU_MANAGER_H_

#include "Chips/Z80.h"

namespace Everdrive
{
	class CPUManager
	{
	public:
		CPUManager()     {}
		~CPUManager()    {}

		void Reset();

		CONTEXTZ80* GetContext() { return &m_ContextZ80; }
		//CONTEXTZ80 GetContext() const { return m_ContextZ80; }

	private:
		CONTEXTZ80 m_ContextZ80;
	};
}

#endif//_CPU_MANAGER_H_