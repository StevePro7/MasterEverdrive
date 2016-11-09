#ifndef _CONFIG_MANAGER_H_
#define _CONFIG_MANAGER_H_

#include <string>

using namespace std;

namespace Everdrive
{
	class ConfigManager
	{
	public:
		ConfigManager()     {}
		~ConfigManager()    {}

		void Init();
		void Load();

		int GetConfig(const char index)
		{
			return m_iConfig[index];
		}
		string GetRomFile()	{ return m_rom_file; }

	private:
		void LogConfiguration();
		short m_iConfig[10];
		string m_rom_file;
	};
}

#endif//_CONFIG_MANAGER_H_