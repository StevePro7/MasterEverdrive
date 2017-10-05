#include "gtest/gtest.h"
#include "Managers/MemoryManager.h"

using namespace testing;
using namespace Everdrive;

class MemoryManagerTests : public ::testing::Test
{
protected:
	MemoryManager memoryManager;
};

TEST_F( MemoryManagerTests, Init )
{
	memoryManager.Init();

	BYTE* cartridgeMemory = memoryManager.GetCartridgeMemory();
	BYTE* internalMemory = memoryManager.GetInternalMemory();
	BYTE* ramBank0 = memoryManager.GetRamBank( 0 );
	BYTE* ramBank1 = memoryManager.GetRamBank( 1 );
	BYTE data = memoryManager.GetRamBank( 0, 0x0020 );

	ASSERT_EQ( 0, cartridgeMemory[0] );
	ASSERT_EQ( 2, internalMemory[0xFFFF] );
	ASSERT_EQ( 1, internalMemory[0xFFFE] );
	ASSERT_EQ( 0, ramBank0[0] );
	ASSERT_EQ( 0, data );
}