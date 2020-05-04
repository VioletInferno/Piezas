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
	ASSERT_EQ(b.pieceAt(0, 0), Blank);
}

TEST(PiezasTest, isBoardEmpty2)
{
	Piezas b;
	ASSERT_EQ(b.pieceAt(2, 3), Blank);
}

// Test reset()
TEST(PiezasTest, doesResetClearBoard)
{
	Piezas b;
	b.dropPiece(0);
	b.dropPiece(1);
	b.dropPiece(2);
	b.dropPiece(3);
	b.reset();
	ASSERT_EQ(b.pieceAt(0, 0), Blank);
}

TEST(PiezasTest, doesTogglingWorkAfterReset)
{
	Piezas b;
	b.dropPiece(0);
	b.reset();
	ASSERT_EQ(b.dropPiece(0), X);
}

// Test dropPiece()
TEST(PiezasTest, dropX)
{
	Piezas b;
	ASSERT_EQ(b.dropPiece(0), X);  // X should always go first
}

TEST(PiezasTest, dropO)
{
	Piezas b;
	b.dropPiece(0);
	ASSERT_EQ(b.dropPiece(0), O);  // O should always follow after X
}

TEST(PiezasTest, areTurnsToggling1)
{
	Piezas b;
	b.dropPiece(0);
	ASSERT_EQ(b.dropPiece(0), O);
}

TEST(PiezasTest, areTurnsToggling2)
{
	Piezas b;
	b.dropPiece(0);
	b.dropPiece(0);
	ASSERT_EQ(b.dropPiece(0), X);
}

TEST(PiezasTest, areFullColumnsHandledCorrectly)
{
	Piezas b;
	b.dropPiece(0);
	b.dropPiece(0);
	b.dropPiece(0);
	ASSERT_EQ(b.dropPiece(0), Blank);
}

TEST(PiezasTest, arePiecesDroppedOutOfBoundsHandledCorrectly)
{
	Piezas b;
	ASSERT_EQ(b.dropPiece(11), Invalid);
}

TEST(PiezasTest, arePiecesDroppedOutOfBoundsHandledCorrectly2)
{
	Piezas b;
	ASSERT_EQ(b.dropPiece(-1), Invalid);
}

TEST(PiezasTest, doesPlayerLoseTurnWhenDroppingOutOfBounds)
{
	Piezas b;
	b.dropPiece(11);
	ASSERT_EQ(b.dropPiece(0), O);
}

// Test pieceAt()
TEST(PiezasTest, isOutOfBounds)
{
	Piezas b;
	ASSERT_EQ(b.pieceAt(-1, -1), Invalid);
}

TEST(PiezasTest, isOutOfBounds2)
{
	Piezas b;
	ASSERT_EQ(b.pieceAt(5, 5), Invalid);
}

TEST(PiezasTest, isOutOfBounds3)
{
	Piezas b;
	ASSERT_EQ(b.pieceAt(0, -1), Invalid);
}

TEST(PiezasTest, isOutOfBounds4)
{
	Piezas b;
	ASSERT_EQ(b.pieceAt(-1, -2), Invalid);
}

TEST(PiezasTest, isOutOfBounds5)
{
	Piezas b;
	ASSERT_EQ(b.pieceAt(0, 5), Invalid);
}

TEST(PiezasTest, testAtX)
{
	Piezas b;
	b.dropPiece(0);
	ASSERT_EQ(b.pieceAt(0, 0), X);
}

TEST(PiezasTest, testAtO)
{
	Piezas b;
	b.dropPiece(0);
	b.dropPiece(0);
	ASSERT_EQ(b.pieceAt(1, 0), O);
}
