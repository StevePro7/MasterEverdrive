#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "Managers/ConfigManager.h"
#include "Managers/CPUManager.h"
#include "Managers/FileManager.h"
#include "Managers/LogManager.h"
#include "Managers/PSGManager.h"
#include "Managers/UtilManager.h"
#include "Managers/VDPManager.h"

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
		CPUManager& CPUManager() { return cpuManager; }
		FileManager& FileManager() { return fileManager; }
		LogManager& LogManager() { return logManager; }
		PSGManager& PSGManager() { return psgManager; }
		UtilManager& UtilManager() { return utilManager; }
		VDPManager& VDPManager() { return vdpManager; }

	private:
		Everdrive::ConfigManager configManager;
		Everdrive::CPUManager cpuManager;
		Everdrive::FileManager fileManager;
		Everdrive::LogManager logManager;
		Everdrive::PSGManager psgManager;
		Everdrive::UtilManager utilManager;
		Everdrive::VDPManager vdpManager;
	};
}

#endif//_ENGINE_H_