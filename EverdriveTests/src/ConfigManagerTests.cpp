#include "gtest/gtest.h"
#include "Managers/ConfigManager.h"
#include "Engine.h"

using namespace std;
using namespace testing;
using namespace Everdrive;

class ConfigManagerTests : public ::testing::Test
{
protected:
	ConfigManager configManager;
};

//TEST_F( ConfigManagerTests, Load )
//{
//	// Arrange.
//	char[MAX_FILENAME];
//	configManager.Load();
//	char romFile = configManager.GetRomFile();
//
//	Engine::Instance().LogManager().Init();
//	Engine::Instance().LogManager().Write(romFile.c_str());
//	Engine::Instance().LogManager().Quit();
//}