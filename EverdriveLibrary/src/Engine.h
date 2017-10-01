#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "Managers/ConfigManager.h"
#include "Managers/FileManager.h"
#include "Managers/LogManager.h"
#include "Managers/UtilManager.h"

namespace Everdrive
{
	class Engine
	{
	public:
		static Engine& Instance()
		{
			static Engine instance;
			return instance;
		}

		void Init();
		void Play();
		void Quit();

		ConfigManager& ConfigManager() { return configManager; }
		FileManager& FileManager() { return fileManager; }
		LogManager& LogManager() { return logManager; }
		UtilManager& UtilManager() { return utilManager; }

	private:
		Everdrive::ConfigManager configManager;
		Everdrive::FileManager fileManager;
		Everdrive::LogManager logManager;
		Everdrive::UtilManager utilManager;
	};
}

#endif//_ENGINE_H_