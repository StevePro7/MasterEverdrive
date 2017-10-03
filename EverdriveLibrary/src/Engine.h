#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "Managers/ConfigManager.h"
#include "Managers/CPUManager.h"
#include "Managers/FileManager.h"
#include "Managers/InputManager.h"
#include "Managers/LogManager.h"
#include "Managers/MemoryManager.h"
#include "Managers/PSGManager.h"
#include "Managers/SoundManager.h"
#include "Managers/UtilManager.h"
#include "Managers/VDPManager.h"
#include "Managers/VideoManager.h"

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
		InputManager& InputManager() { return inputManager; }
		LogManager& LogManager() { return logManager; }
		MemoryManager& MemoryManager() { return memoryManager; }
		PSGManager& PSGManager() { return psgManager; }
		SoundManager& SoundManager() { return soundManager; }
		UtilManager& UtilManager() { return utilManager; }
		VDPManager& VDPManager() { return vdpManager; }
		VideoManager& VideoManager() { return videoManager; }

	private:
		Everdrive::ConfigManager configManager;
		Everdrive::CPUManager cpuManager;
		Everdrive::FileManager fileManager;
		Everdrive::InputManager inputManager ;
		Everdrive::LogManager logManager;
		Everdrive::MemoryManager memoryManager;
		Everdrive::PSGManager psgManager;
		Everdrive::SoundManager soundManager;
		Everdrive::UtilManager utilManager;
		Everdrive::VDPManager vdpManager;
		Everdrive::VideoManager videoManager;
	};
}

#endif//_ENGINE_H_