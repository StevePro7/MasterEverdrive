#ifndef _CONFIG_MANAGER_H_
#define _CONFIG_MANAGER_H_

#include "Defines.h"

namespace Everdrive
{
	class ConfigManager
	{
	public:
		ConfigManager()     {}
		~ConfigManager()    {}

		void Init();
		void Load();

		int GetConfig( const char index )
		{
			return m_iConfig[index];
		}

		char* GetRomFile() { return m_rom_file; }

	private:
		void LogConfiguration();
		short m_iConfig[10];
		char m_rom_file[MAX_FILENAME];
	};
}

#endif//_CONFIG_MANAGER_H_