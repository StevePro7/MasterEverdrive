#include "Engine.h"

namespace Everdrive
{
	void Engine::Init()
	{
		logManager.Init();
		configManager.Init();

		/*const char* path = "rom/MonacoGP.sms";
		RomCartridge* cartridge = new RomCartridge;
		memset(cartridge->m_CartridgeMemory, 0, 0x100000);
		fileManager.InsertCartridge(path, cartridge);*/

		const char* path = "rom/MonacoGP.sms";
		BYTE* cartridgeMemory = new BYTE[0x100000];
		memset(cartridgeMemory, 0, 0x100000);
		fileManager.InsertCartridge(path, cartridgeMemory);
		delete cartridgeMemory;
	}

	void Engine::Play()
	{
	}

	void Engine::Quit()
	{
		logManager.Quit();
	}
}