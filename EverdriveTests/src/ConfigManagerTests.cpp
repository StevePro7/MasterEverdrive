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

//TEST_F( ConfigManagerTests, Init )
//{
//}

TEST_F( ConfigManagerTests, Load )
{
	configManager.Load();
	configManager.GetRomFile();
	//char* romFile = configManager.GetRomFile();
	//printf( "%s", romFile );
}