#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <err.h>
#include <uchar.h>
#include <stdbool.h>

/// @brief State if the turn or if checkmate was given.
enum State {
    BLACK,
    WHITE,
    MATE
};

/// @brief Ease for code on a chessboard.
enum Colums {
    a, b, c, d, e, f, g, h
};

/// @brief Define each piece with a number.
enum Square {
    EMPTY,
    W_POND,
    W_KNIGHT,
    W_BISHOP,
    W_ROOK,
    W_QUEEN,
    W_KING,
    B_POND,
    B_KNIGHT,
    B_BISHOP,
    B_ROOK,
    B_QUEEN,
    B_KING
};

/// @brief Structure for a chessboard.
typedef struct board Board;
struct board {
    unsigned array[8][8];       /// bi-dimentional board
    unsigned state;             /// play on or checkmate
    int last_move[4];           /// [row1,col1,row2,col2]
};

/****************************functions****************************/

//********The Board********//

/// @brief Create a new board to play on.
struct board* newBoard();

/// @brief Set the board to starting position.
/// @param Board The chessboard
void setBoard(struct board* Board);

/// @brief Clear the board of any piece.
/// @param Board The board
void clearBoard(struct board* Board);

/// @brief Display the board (black POV) on the console output.
/// @param Board The chessboard
void displayBoardBlack(struct board* Board);

/// @brief Display the board (white POV) on the console output.
/// @param Board The chessboard
void displayBoardWhite(struct board* Board);

/// @brief Delete the board.
/// @param Board The chessboard.
void deleteBoard(struct board* Board);

//********The Pieces********//

/// @brief Move a piece over the board, changing the last-move.
/// @param Board The chessboard
/// @param move The move asked
void move(struct board* Board, unsigned move[4]);

/// @brief Check if a piece is white.
/// @param P The piece
/// @return bool
bool isWhite(unsigned P);

/// @brief Check if a square is empty.
/// @param S The square
/// @return bool
bool isEmpty(unsigned S);

/// @brief Check if two pieces are of the same color.
/// @param P1 The first piece
/// @param P2 The second piece
/// @return bool
bool sameColor(unsigned P1, unsigned P2);

/// @brief Transform a chess position to coordinates on the board.
/// @param array The positions
void PosToCoord(unsigned array[4]);

#endif