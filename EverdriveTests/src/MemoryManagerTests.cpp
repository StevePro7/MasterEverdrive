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

	ASSERT_EQ( 0, memoryManager.GetFirstBankPage() );
	ASSERT_EQ( 1, memoryManager.GetSecondBankPage() );
	ASSERT_EQ( 2, memoryManager.GetThirdBankPage() );

	ASSERT_EQ( -1, memoryManager.GetCurrentRam() );
	ASSERT_EQ( false, memoryManager.OneMegCartridge() );
}

TEST_F( MemoryManagerTests, Load )
{
	// Arrange.
	const BYTE data = 0x04;

	BYTE* cartridgeMemory = new BYTE[ONE_MEGA_BYTE];
	memset( cartridgeMemory, data, ONE_MEGA_BYTE );
	long endPos = 0;

	// Act.
	memoryManager.Load( cartridgeMemory, endPos );
	delete cartridgeMemory;

	// Assert.
	ASSERT_EQ( false, memoryManager.OneMegCartridge() );

	BYTE* internalMemory = memoryManager.GetInternalMemory();
	ASSERT_EQ( data, internalMemory[0x0000] );
	ASSERT_EQ( data, internalMemory[0xBFFF] );
	ASSERT_EQ( 2, internalMemory[0xFFFF] );
	ASSERT_EQ( 1, internalMemory[0xFFFE] );
}