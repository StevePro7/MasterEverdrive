#include "gtest/gtest.h"
#include "Managers/InputManager.h"

using namespace testing;
using namespace Everdrive;

class InputManagerTests : public ::testing::Test
{
protected:
	InputManager inputManager;
};

TEST_F( InputManagerTests, Init )
{
	inputManager.Init();

	ASSERT_EQ( 1, 2 );
}