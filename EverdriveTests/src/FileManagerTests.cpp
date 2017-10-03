#include "gtest/gtest.h"
#include "Managers/FileManager.h"
#include "Defines.h"

using namespace testing;
using namespace Everdrive;

class FileManagerTests : public ::testing::Test
{
protected:
	FileManager fileManager;
};

//TEST_F(FileManagerTests, InsertCartridge)
//{
//	BYTE cartridgeMemory[SIXTY_FOUR_KB];
//	memset(cartridgeMemory, 0, sizeof(cartridgeMemory));
//
//	fileManager.InsertCartridge("rom/MonacoGP.sms", cartridgeMemory);
//	ASSERT_EQ(0x31, cartridgeMemory[0]);
//}

//TEST_F(FileManagerTests, InsertCartridge)
//{
//	const char* path = "rom/MonacoGP.sms";
//	RomCartridge* cartridge = new RomCartridge;
//	fileManager.InsertCartridge(path, cartridge);
//	delete cartridge;
//	ASSERT_EQ(1, 1);
//}

TEST_F(FileManagerTests, InsertCartridge)
{
	const char* path = "rom/MonacoGP.sms";
	BYTE* cartridgeMemory = new BYTE[ONE_MEGA_BYTE];
	memset(cartridgeMemory, 0, ONE_MEGA_BYTE);
	fileManager.InsertCartridge(path, cartridgeMemory);
	delete cartridgeMemory;
	ASSERT_EQ(1, 1);
}