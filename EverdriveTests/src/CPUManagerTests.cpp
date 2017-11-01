#include "gtest/gtest.h"
#include "Managers/CPUManager.h"
#include "Chips/Z80.h"

using namespace testing;
using namespace Everdrive;

class CPUManagerTests : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		cpuManager.Init();
	}
	virtual void TearDown() {}

	CPUManager cpuManager;
};

TEST_F( CPUManagerTests, IncreaseRReg )
{
	CONTEXTZ80* context = cpuManager.GetContext();

	cpuManager.IncreaseRReg();
	ASSERT_EQ( 0x01, context->m_RegisterR );

	context->m_RegisterR = 127;
	cpuManager.IncreaseRReg();
	ASSERT_EQ( 0x00, context->m_RegisterR );
}

TEST_F( CPUManagerTests, ExecuteOpcode )
{
}

TEST_F( CPUManagerTests, Init )
{
	cpuManager.Init();

	CONTEXTZ80* context = cpuManager.GetContext();

	ASSERT_EQ( 0x0, context->m_RegisterAF.reg );
	ASSERT_EQ( 0x0, context->m_RegisterBC.reg );
	ASSERT_EQ( 0x0, context->m_RegisterDE.reg );
	ASSERT_EQ( 0x0, context->m_RegisterHL.reg );
	ASSERT_EQ( 0x0, context->m_RegisterAFPrime.reg );
	ASSERT_EQ( 0x0, context->m_RegisterBCPrime.reg );
	ASSERT_EQ( 0x0, context->m_RegisterDEPrime.reg );
	ASSERT_EQ( 0x0, context->m_RegisterHLPrime.reg );
	ASSERT_EQ( 0xDFF0, context->m_StackPointer.reg );
	ASSERT_EQ( 0, context->m_RegisterIX.reg );
	ASSERT_EQ( 0, context->m_RegisterIY.reg );
	ASSERT_EQ( 0, context->m_RegisterI );
	ASSERT_EQ( 0, context->m_RegisterR );
	ASSERT_EQ( 0, context->m_ProgramCounter );
	ASSERT_EQ( 0, context->m_ProgramCounterStart );
	ASSERT_EQ( 0, context->m_OpcodeCycle );
	ASSERT_EQ( false, context->m_Halted );
	ASSERT_EQ( false, context->m_IFF1 );
	ASSERT_EQ( false, context->m_IFF2 );
	ASSERT_EQ( false, context->m_EIPending );
	ASSERT_EQ( 1, context->m_InteruptMode );
	ASSERT_EQ( false, context->m_Halted );
	ASSERT_EQ( false, context->m_NMI );
	ASSERT_EQ( false, context->m_NMIServicing );
}