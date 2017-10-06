#include "gtest/gtest.h"
#include "Managers/VideoManager.h"

using namespace testing;
using namespace Everdrive;

class VideoManagerTests : public ::testing::Test
{
protected:
	VideoManager videoManager;
};

TEST_F( VideoManagerTests, Init )
{
	videoManager.Init();

	ASSERT_EQ( 256, videoManager.GetWidth() );
	ASSERT_EQ( 192, videoManager.GetHeight() );
	ASSERT_FALSE( videoManager.GetUseGFXOpt() );
}