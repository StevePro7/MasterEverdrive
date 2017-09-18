#include "gtest/gtest.h"
#include "Managers/FileManager.h"

using namespace testing;
using namespace Everdrive;

class FileManagerTests : public ::testing::Test
{
protected:
	FileManager fileManager;
};

//TEST_F(FileManagerTests, InsertCartridge)
//{
//	BYTE cartridgeMemory[0x10000];
//	memset(cartridgeMemory, 0, sizeof(cartridgeMemory));
//
//	fileManager.InsertCartridge("rom/MonacoGP.sms", cartridgeMemory);
//	ASSERT_EQ(0x31, cartridgeMemory[0]);
//}