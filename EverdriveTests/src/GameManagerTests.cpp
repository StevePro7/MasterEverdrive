#include "gtest/gtest.h"
#include "Managers/GameManager.h"

using namespace testing;
using namespace Everdrive;

class GameManagerTests : public ::testing::Test
{
protected:
	GameManager gameManager;
};

TEST_F( GameManagerTests, Init )
{
	gameManager.Init();

	ASSERT_EQ( 0, gameManager.GetCyclesThisUpdate() );
	ASSERT_EQ( 0, gameManager.GetClockInfo() );
	ASSERT_EQ( 60, gameManager.GetFPS() );
	ASSERT_EQ( true, gameManager.IsPAL() );
	ASSERT_EQ( false, gameManager.IsCodeMasters() );
	//ASSERT_EQ( false, gameManager.OneMegCartridge() );
}