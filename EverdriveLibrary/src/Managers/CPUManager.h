#ifndef _CPU_MANAGER_H_
#define _CPU_MANAGER_H_

namespace Everdrive
{
	class CPUManager
	{
	public:
		CPUManager()     {}
		~CPUManager()    {}

		void Reset();

		int GetData() { return data; }
	private:
		int data;
	};
}

#endif//_CPU_MANAGER_H_