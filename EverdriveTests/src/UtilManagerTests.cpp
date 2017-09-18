#include "gtest/gtest.h"
#include "Managers/UtilManager.h"

using namespace testing;
using namespace Everdrive;

class UtilManagerTests : public ::testing::Test
{
protected:
	UtilManager utilManager;
};

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