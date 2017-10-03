#include "ConfigManager.h"
#include "Constants.h"
#include "Engine.h"
#include <fstream>

using namespace std;

namespace Everdrive
{
	void LogConfiguration();

	void ConfigManager::Init()
	{
		memset(m_iConfig, 0, sizeof(m_iConfig));

		// Default values.

		// Config values.
		std::ifstream myfile;
		myfile.open(CONFIG_FILENAME, std::ifstream::in);

		if (myfile.fail())
		{
			myfile.clear(std::ios::failbit);
			LogConfiguration();
			return;
		}

		// Load configuration.
		char buffer[256];
		char cnt = 0;

		while (!myfile.eof())
		{
			myfile.getline (buffer,100);
			m_iConfig[cnt++] = atoi(buffer);
		}

		myfile.close();
	}

	void ConfigManager::Load()
	{
		m_rom_file = "3Ddity.sms";

		// Config values.
		std::ifstream myfile;
		myfile.open(ROMFILE_FILENAME, std::ifstream::in);

		if (myfile.fail())
		{
			myfile.clear(std::ios::failbit);
			return;
		}

		// Load configuration.
		char buffer[256];
		while (!myfile.eof())
		{
			myfile.getline (buffer,100);
			m_rom_file = buffer;
		}

		myfile.close();
	}

	void ConfigManager::LogConfiguration()
	{
		// Log all configuration!
	}

}