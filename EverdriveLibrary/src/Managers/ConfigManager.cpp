#include "ConfigManager.h"
#include "Constants.h"
#include "Engine.h"
#include <fstream>

namespace Everdrive
{
	void ConfigManager::Init()
	{
		memset( m_iConfig, 0, sizeof( m_iConfig ) );

		// Default values.

		// Config values.
		std::ifstream myfile;
		myfile.open( CONFIG_FILENAME, std::ifstream::in );

		if (myfile.fail())
		{
			myfile.clear( std::ios::failbit );
			LogConfiguration();
			return;
		}

		// Load configuration.
		char buffer[MAX_FILENAME];
		char cnt = 0;

		while ( !myfile.eof() )
		{
			myfile.getline( buffer, MAX_FILENAME );
			m_iConfig[cnt++] = atoi( buffer );
		}

		myfile.close();
	}

	void ConfigManager::Load()
	{
		// Config values.
		std::ifstream myfile;
		myfile.open( ROMFILE_FILENAME, std::ifstream::in );

		if ( myfile.fail() )
		{
			myfile.clear( std::ios::failbit );
			return;
		}

		// Load configuration.
		char buffer[MAX_FILENAME];
		while ( !myfile.eof() )
		{
			myfile.getline( buffer, MAX_FILENAME );
			memcpy( m_rom_file, buffer, MAX_FILENAME );
		}

		myfile.close();
	}

	void ConfigManager::LogConfiguration()
	{
		// Log all configuration!
	}

}