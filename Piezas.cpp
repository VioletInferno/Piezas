#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
    board.resize(BOARD_ROWS);  // resize rows
    for (int row = 0; row < (int) board.size(); row++)
    {
        board[row].resize(BOARD_COLS);  // resize cols
        for (int col = 0; col < (int) board[row].size(); col++)
            board[row][col] = Blank;  // set all board tiles to blank
    }
    turn = X;  // specify that X goes first
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
    for (int row = 0; row < (int) board.size(); row++)
        for (int col = 0; col < (int) board[row].size(); col++)
            board[row][col] = Blank;  // reset board tiles to blank
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
    // this is the piece that we will drop on the board
    Piece cur_turn = turn;

    // toggle the turn
    if (turn == O)
        turn = X;
    else
        turn = O;

    // check if we're out of bounds
    if (column > BOARD_COLS || column < 0)
        return Invalid;

    // drop the piece
    for (int row = 0; row < (int) board.size(); row++)
    {
        if (board[row][column] == Blank)
        {
            board[row][column] = cur_turn;
            return board[row][column];
        }
    }

    return Blank;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    // check if out of bounds
    if (row > BOARD_ROWS || row < 0 || column > BOARD_COLS || column < 0)
        return Invalid;

    return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
    // highest scores for X and O
    int max_x = 0, max_o = 0;

    // current scores for X and O
    int cur_x = 0, cur_o = 0;

    // check horizontally
    for (int row = 0; row < (int) board.size(); row++)
    {
        for (int col = 0; col < (int) board[row].size(); col++)
        {
            if (board[row][col] == Blank)  // if tile is blank, our game isn't over
                return Invalid;
            else if (board[row][col] == X) 
            {
                cur_x++;
                if (cur_x > max_x)
                    max_x = cur_x;
                cur_o = 0;
            }
            else if (board[row][col] == O)
            {
                cur_o++;
                if (cur_o > max_o)
                    max_o = cur_o;
                cur_x = 0;
            }
        }
    }

    // check vertically
    for (int col = 0; col < (int) board[0].size(); col++)
    {
        for (int row = 0; row < (int) board.size(); row++)
        {
            if (board[row][col] == Blank)  // if tile is blank, game isn't over.
                return Invalid;
            else if (board[row][col] == X)
            {
                cur_x++;
                if (cur_x > max_x)
                    max_x = cur_x;
                cur_o = 0;
            }
            else if (board[row][col] == O)
            {
                cur_o++;
                if (cur_o > max_o)
                    max_o = cur_o;
                cur_x = 0;
            }
        }
    }

    // highest scoring team wins the match
    if (max_x > max_o)
        return X;
    else if (max_o > max_x)
        return O;
    return Blank; // returns blank if tie.
}
