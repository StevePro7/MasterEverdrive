#include "gtest/gtest.h"
#include "Managers/MemoryManager.h"

using namespace testing;
using namespace Everdrive;

class MemoryManagerTests : public ::testing::Test
{
protected:
	MemoryManager memoryManager;
};

TEST_F( MemoryManagerTests, ReadMemoryImpl )
{
	BYTE data;

	// Setup general variables.
	const bool isCodeMasters = false;

	BYTE* cartridgeMemory = new BYTE[ONE_MEGA_BYTE];
	BYTE* internalMemory = new BYTE[SIXTY_FOUR_KB];
	BYTE ramBankByte = 0xFF;
	BYTE firstBankPage = 0, secondBankPage = 1, thirdBankPage = 2;
	int currentRam = -1;
	memset( cartridgeMemory, 0, ONE_MEGA_BYTE );
	memset( internalMemory, 0, SIXTY_FOUR_KB );


	// the fixed memory address
	internalMemory[0x0000] = 0xF3;
	data = memoryManager.ReadMemoryImpl( 0x0000, isCodeMasters, cartridgeMemory, internalMemory, ramBankByte, firstBankPage, secondBankPage, thirdBankPage, currentRam  );
	ASSERT_EQ( 0xF3, data );

	// bank 0
	cartridgeMemory[0x2AA4] = 0x21;
	firstBankPage = 0;
	data = memoryManager.ReadMemoryImpl( 0x2AA4, isCodeMasters, cartridgeMemory, internalMemory, ramBankByte, firstBankPage, secondBankPage, thirdBankPage, currentRam  );
	ASSERT_EQ( 0x21, data );

	// bank 1
	cartridgeMemory[0x721F] = 0x58;
	secondBankPage = 1;
	data = memoryManager.ReadMemoryImpl( 0x721F, isCodeMasters, cartridgeMemory, internalMemory, ramBankByte, firstBankPage, secondBankPage, thirdBankPage, currentRam  );
	ASSERT_EQ( 0x58, data );

	// bank 2 RAM
	currentRam = 0;
	ramBankByte = 0x02;
	data = memoryManager.ReadMemoryImpl( 0x982B, isCodeMasters, cartridgeMemory, internalMemory, ramBankByte, firstBankPage, secondBankPage, thirdBankPage, currentRam  );
	ASSERT_EQ( 0x02, data );

	// bank 2 ROM
	currentRam = -1;
	cartridgeMemory[0x1AED3] = 0xF8;
	thirdBankPage = 6;
	data = memoryManager.ReadMemoryImpl( 0xAED3, isCodeMasters, cartridgeMemory, internalMemory, ramBankByte, firstBankPage, secondBankPage, thirdBankPage, currentRam  );
	ASSERT_EQ( 0xF8, data );

	// catch all
	internalMemory[0xDFFF] = 0x07;
	data = memoryManager.ReadMemoryImpl( 0xFFFF, isCodeMasters, cartridgeMemory, internalMemory, ramBankByte, firstBankPage, secondBankPage, thirdBankPage, currentRam  );
	ASSERT_EQ( 0x07, data );


	delete internalMemory;
	delete cartridgeMemory;
}

TEST_F( MemoryManagerTests, WriteMemoryImpl )
{
	BYTE data, page;

	int currentRam = -1;
	bool isCodeMasters;
	const bool oneMegCartridge = false;
	bool testC1 = false, testC2 = false, testF1 = false;

	// Address = 0x0000		 0KB	Page #01.
	data = 0x00, page = 0x00;
	isCodeMasters = true;
	memoryManager.WriteMemoryImpl( 0x0000, 0x00, 0x00, isCodeMasters, currentRam, oneMegCartridge, testC1, testC2, testF1 );
	ASSERT_EQ( 0x00, memoryManager.GetFirstBankPage() );

	// Address = 0x4000		16KB	Page #02.
	data = 0x01, page = 0x01;
	memoryManager.WriteMemoryImpl( 0x4000, 0x01, 0x01, isCodeMasters, currentRam, oneMegCartridge, testC1, testC2, testF1 );
	ASSERT_EQ( 0x01, memoryManager.GetSecondBankPage() );

	// Address = 0x8000		32KB	Page #03.
	data = 0x02, page = 0x02;
	memoryManager.WriteMemoryImpl( 0x8000, 0x02, 0x02, isCodeMasters, currentRam, oneMegCartridge, testC1, testC2, testF1 );
	ASSERT_EQ( 0x02, memoryManager.GetThirdBankPage() );


	// Address > 0x8000 && < 0xC000 Slot 02	48KB.	RAM takes precedence!
	currentRam = 0;
	isCodeMasters = false;
	memoryManager.WriteMemoryImpl( 0x9000, 0x0A, 0x0A, isCodeMasters, currentRam, oneMegCartridge, testC1, testC2, testF1 );
	ASSERT_EQ( 0x0A, memoryManager.GetRamBank( 0 )[ 0x1000 ] );

	// Address >=0x8000 && < 0xC000 Slot 02	48KB.	RAM takes precedence!
	currentRam = 1;
	memoryManager.WriteMemoryImpl( 0x9001, 0x0B, 0x0B, isCodeMasters, currentRam, oneMegCartridge, testC1, testC2, testF1 );
	ASSERT_EQ( 0x0B, memoryManager.GetRamBank( 1 )[ 0x1001 ] );

	// Address > 0x8000 && < 0xC000 Slot 02	48KB.	ROM do nothing!
	currentRam = -1;
	memoryManager.WriteMemoryImpl( 0x9001, 0x0C, 0x0C, isCodeMasters, currentRam, oneMegCartridge, testC1, testC2, testF1 );


	// Address >=0xC000 && < 0xFFFC Slot 04		> 48KB
	memoryManager.WriteMemoryImpl( 0xC001, 0x00, 0x00, isCodeMasters, currentRam, oneMegCartridge, testC1, testC2, testF1 );
	ASSERT_EQ( 0x00, memoryManager.GetInternalMemory()[0xC001] );
	ASSERT_EQ( 0x00, memoryManager.GetInternalMemory()[0xE001] );


	// Address >=0xFFFC				Slot 04		> 48KB
	testC1 = false;
	memoryManager.WriteMemoryImpl( 0xFFFC, 0x80, 0x00, isCodeMasters, currentRam, oneMegCartridge, testC1, testC2, testF1 );
	ASSERT_EQ( 0x80, memoryManager.GetInternalMemory()[0xDFFC] );
	ASSERT_EQ( 0x80, memoryManager.GetInternalMemory()[0xFFFC] );
	ASSERT_EQ( -1, memoryManager.GetCurrentRam() );

	// See DoMemPageImpl for more detailed tests here where
	// WriteMemory >= 0xFFFC && <= 0xFFFF when !codeMasters
 }

TEST_F( MemoryManagerTests, Init )
{
	memoryManager.Init();

	BYTE* cartridgeMemory = memoryManager.GetCartridgeMemory();
	BYTE* internalMemory = memoryManager.GetInternalMemory();
	BYTE* ramBank0 = memoryManager.GetRamBank( 0 );
	BYTE* ramBank1 = memoryManager.GetRamBank( 1 );
	BYTE data = memoryManager.GetRamBank( 0, 0x0020 );

	ASSERT_EQ( 0, cartridgeMemory[0] );
	ASSERT_EQ( 2, internalMemory[0xFFFF] );
	ASSERT_EQ( 1, internalMemory[0xFFFE] );
	ASSERT_EQ( 0, ramBank0[0] );
	ASSERT_EQ( 0, data );

	ASSERT_EQ( 0, memoryManager.GetFirstBankPage() );
	ASSERT_EQ( 1, memoryManager.GetSecondBankPage() );
	ASSERT_EQ( 2, memoryManager.GetThirdBankPage() );

	ASSERT_EQ( false, memoryManager.OneMegCartridge() );
	ASSERT_EQ( -1, memoryManager.GetCurrentRam() );
}

TEST_F( MemoryManagerTests, Load )
{
	// Arrange.
	const BYTE data = 0x04;

	BYTE* cartridgeMemory = new BYTE[ONE_MEGA_BYTE];
	memset( cartridgeMemory, data, ONE_MEGA_BYTE );
	long endPos = 0;

	// Act.
	memoryManager.Load( cartridgeMemory, endPos );
	delete cartridgeMemory;

	// Assert.
	ASSERT_EQ( false, memoryManager.OneMegCartridge() );

	BYTE* internalMemory = memoryManager.GetInternalMemory();
	ASSERT_EQ( data, internalMemory[0x0000] );
	ASSERT_EQ( data, internalMemory[0xBFFF] );
	ASSERT_EQ( 2, internalMemory[0xFFFF] );
	ASSERT_EQ( 1, internalMemory[0xFFFE] );
}

TEST_F( MemoryManagerTests, DoMemPageImpl )
{
	BYTE data;
	const bool oneMegCartridge = false;
	bool testC1 = false, testC2 = false, testF1 = false;

	// Address = 0xFFFC		Control register	#01.
	data = 0x80;
	testC1 = false;			// TestBit( data, 3 )
	memoryManager.DoMemPageImpl( 0xFFFC, 0x80, oneMegCartridge, testC1, testC2, testF1 );
	ASSERT_EQ( 0x80, memoryManager.GetInternalMemory()[0xDFFC] );
	ASSERT_EQ( -1, memoryManager.GetCurrentRam() );

	// Address = 0xFFFC		Control register	#02.
	data = 0x0C;
	testC1 = true;			// TestBit( data, 3 )
	testC2 = true;			// TestBit( data, 2 )
	memoryManager.DoMemPageImpl( 0xFFFC, 0x0C, oneMegCartridge, testC1, testC2, testF1 );
	ASSERT_EQ( 0x0C, memoryManager.GetInternalMemory()[0xDFFC] );
	ASSERT_EQ( 1, memoryManager.GetCurrentRam() );

	// Address = 0xFFFC		Control register	#03.
	data = 0x08;
	testC1 = true;			// TestBit( data, 3 )
	testC2 = false;			// TestBit( data, 2 )
	memoryManager.DoMemPageImpl( 0xFFFC, 0x08, oneMegCartridge, testC1, testC2, testF1 );
	ASSERT_EQ( 0x08, memoryManager.GetInternalMemory()[0xDFFC] );
	ASSERT_EQ( 0, memoryManager.GetCurrentRam() );


	// Address = 0xFFFD		First bank.
	data = 0x00;
	memoryManager.DoMemPageImpl( 0xFFFD, 0x00, oneMegCartridge, testC1, testC2, testF1 );
	ASSERT_EQ( 0x00, memoryManager.GetInternalMemory()[0xDFFD] );
	ASSERT_EQ( 0x00, memoryManager.GetFirstBankPage() );


	// Address = 0xFFFE		Second bank.
	data = 0x01;
	memoryManager.DoMemPageImpl( 0xFFFE, 0x01, oneMegCartridge, testC1, testC2, testF1 );
	ASSERT_EQ( 0x01, memoryManager.GetInternalMemory()[0xDFFE] );
	ASSERT_EQ( 0x01, memoryManager.GetSecondBankPage() );


	// Address = 0xFFFF		Third bank.
	data = 0x02;
	testF1 = false;			// TestBit( context->m_InternalMemory[0xFFFC], 3 )
	memoryManager.DoMemPageImpl( 0xFFFF, 0x02, oneMegCartridge, testC1, testC2, testF1 );
	ASSERT_EQ( 0x02, memoryManager.GetInternalMemory()[0xDFFF] );
	ASSERT_EQ( 0x02, memoryManager.GetThirdBankPage() );
}

TEST_F( MemoryManagerTests, DoMemPageCMImpl )
{
	BYTE page;

	// Address = 0x0000		 0KB	Page #01.
	page = 0x00;
	memoryManager.DoMemPageCMImpl( 0x0000, 0x00 );
	ASSERT_EQ( 0x00, memoryManager.GetFirstBankPage() );

	// Address = 0x4000		16KB	Page #02.
	page = 0x01;
	memoryManager.DoMemPageCMImpl( 0x4000, 0x01 );
	ASSERT_EQ( 0x01, memoryManager.GetSecondBankPage() );

	// Address = 0x8000		32KB	Page #03.
	page = 0x09;
	memoryManager.DoMemPageCMImpl( 0x8000, 0x09 );
	ASSERT_EQ( 0x09, memoryManager.GetThirdBankPage() );
}