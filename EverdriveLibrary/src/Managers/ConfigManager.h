#ifndef _CONFIG_MANAGER_H_
#define _CONFIG_MANAGER_H_

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

	private:
		void LogConfiguration();
		short m_iConfig[10];
	};
}

#endif//_CONFIG_MANAGER_H_