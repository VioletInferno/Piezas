/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

// Test constructor
TEST(PiezasTest, isBoardEmpty)
{
	Piezas b;  // b for board. Creating a Piezas object initialzes the constructor.
	ASSERT_EQ(b.pieceAt(0,0), Blank);
}

// Test reset()
TEST(PiezasTest, resetTest)
{
	Piezas b;
	b.dropPiece(0);
	b.dropPiece(1);
	b.dropPiece(2);
	b.dropPiece(3);
	b.reset();
	ASSERT_EQ(Blank, b.pieceAt(0,0));
}