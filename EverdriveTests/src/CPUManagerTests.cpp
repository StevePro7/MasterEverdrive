#include "gtest/gtest.h"
#include "Managers/CPUManager.h"

using namespace testing;
using namespace Everdrive;

class CPUManagerTests : public ::testing::Test
{
protected:
	CPUManager cpuManager;
};

TEST_F(CPUManagerTests, Reset)
{
	cpuManager.Reset();
	ASSERT_EQ(2, cpuManager.GetData());
}