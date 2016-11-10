#include "gtest/gtest.h"
#include "Managers/LogManager.h"

using namespace testing;
using namespace Everdrive;

class LogManagerTests : public ::testing::Test
{
protected:
	LogManager logManager;
};

//TEST_F(LogManagerTests, Write)
//{
//	logManager.Init();
//	logManager.Write("logging test\n");
//	logManager.Quit();
//}