#include "gtest/gtest.h"
#include "Managers/CPUManager.h"
#include "Chips/Z80.h"

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

	CONTEXTZ80 context = cpuManager.GetContext();

	ASSERT_EQ( 0x0, context.m_RegisterAF.reg );
	ASSERT_EQ( 0x0, context.m_RegisterBC.reg );
	ASSERT_EQ( 0x0, context.m_RegisterDE.reg );
	ASSERT_EQ( 0x0, context.m_RegisterHL.reg );
}