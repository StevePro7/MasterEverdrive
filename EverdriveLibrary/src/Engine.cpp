#include "Engine.h"
#include "Defines.h"

namespace Everdrive
{
	void Engine::Init()
	{
		logManager.Init();
		configManager.Init();

		cpuManager.Init();
		memoryManager.Init();
		videoManager.Init();

		videoManager.Load();

		// Load ROM into memory.
		const char* path = "rom/MonacoGP.sms";
		BYTE* cartridgeMemory = new BYTE[ONE_MEGA_BYTE];
		memset( cartridgeMemory, 0, ONE_MEGA_BYTE );
		long endPos = 0;

		fileManager.InsertCartridge( path, cartridgeMemory, endPos );
		memoryManager.Load( cartridgeMemory, endPos );
		delete cartridgeMemory;
	}

	void Engine::Play()
	{
		/*while( true )
		{
		}*/
	}

	void Engine::Quit()
	{
		logManager.Quit();
	}
}