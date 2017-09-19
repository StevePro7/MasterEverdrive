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

// Bit get value
TEST_F( UtilManagerTests, BitGetValZero )
{
	int data = utilManager.BitGetVal( 3, 2 );
	ASSERT_EQ( 0, data );
}
TEST_F( UtilManagerTests, BitGetValOne )
{
	int data = utilManager.BitGetVal( 4, 2 );
	ASSERT_EQ( 1, data );
}

// Bit get
TEST_F( UtilManagerTests, BitGet )
{
	int data = utilManager.BitGetVal( 14, 3 );
	ASSERT_EQ( 1, data );
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

// Bit count
TEST_F( UtilManagerTests, BitCount )
{
	int data = utilManager.BitCount( 7, 3 );
	ASSERT_EQ( 3, data );
}