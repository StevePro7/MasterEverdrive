#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "Managers/LogManager.h"

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

		LogManager& LogManager() { return logManager; }

	private:
		Everdrive::LogManager logManager;
	};
}

#endif//_ENGINE_H_