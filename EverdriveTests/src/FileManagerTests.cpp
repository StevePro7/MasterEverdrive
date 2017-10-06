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

TEST_F( FileManagerTests, InsertCartridge )
{
	// Arrange.
	const char* path = "rom/MonacoGP.sms";
	BYTE* cartridgeMemory = new BYTE[ONE_MEGA_BYTE];
	memset( cartridgeMemory, 0, ONE_MEGA_BYTE );
	long endPos = 0;

	// Act.
	fileManager.InsertCartridge( path, cartridgeMemory, endPos );
	delete cartridgeMemory;

	// Assert.
	ASSERT_EQ( 0, endPos );
}