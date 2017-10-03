#include "Engine.h"
#include "Defines.h"

namespace Everdrive
{
	void Engine::Init()
	{
		logManager.Init();
		configManager.Init();

		videoManager.Init();

		/*const char* path = "rom/MonacoGP.sms";
		RomCartridge* cartridge = new RomCartridge;
		memset(cartridge->m_CartridgeMemory, 0, ONE_MEGA_BYTE);
		fileManager.InsertCartridge(path, cartridge);*/

		const char* path = "rom/MonacoGP.sms";
		BYTE* cartridgeMemory = new BYTE[ONE_MEGA_BYTE];
		memset(cartridgeMemory, 0, ONE_MEGA_BYTE);
		fileManager.InsertCartridge(path, cartridgeMemory);
		delete cartridgeMemory;
	}

	void Engine::Play()
	{
		while( true )
		{
		}
	}

	void Engine::Quit()
	{
		logManager.Quit();
	}
}