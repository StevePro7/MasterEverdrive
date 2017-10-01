#include "Engine.h"

namespace Everdrive
{
	void Engine::Init()
	{
		logManager.Init();
		configManager.Init();
	}

	void Engine::Play()
	{
	}

	void Engine::Quit()
	{
		logManager.Quit();
	}
}