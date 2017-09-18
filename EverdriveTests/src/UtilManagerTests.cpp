#include "gtest/gtest.h"
#include "Managers/UtilManager.h"

using namespace testing;
using namespace Everdrive;

class UtilManagerTests : public ::testing::Test
{
protected:
	UtilManager utilManager;
};

// Test bit
TEST_F( UtilManagerTests, TestBitFalse )
{
	bool condition = utilManager.TestBit( 3, 2 );
	ASSERT_FALSE( condition );
}
TEST_F( UtilManagerTests, TestBitTrue )
{
	bool condition = utilManager.TestBit( 4, 2 );
	ASSERT_TRUE( condition );
}

// Bit set
TEST_F( UtilManagerTests, BitSet )
{
	int data = utilManager.BitSet( 8, 2 );
	ASSERT_EQ( 12, data );
}

// Bit reset
TEST_F( UtilManagerTests, BitReset )
{
	int data = utilManager.BitReset( 2, 1 );
	ASSERT_EQ( 0, data );
}
