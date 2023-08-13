#ifndef CHESSGAME_GAMEBOARD_H
#define CHESSGAME_GAMEBOARD_H


#include "BoardTile.h"
#include "ChessTypes.h"
#include <Windows.h>

#define WHITE_BACKGROUND 127
#define BLACK_BACKGROUND 128

#define WHITE_TEXT 12
#define BLACK_TEXT 10

class GameBoard {
public:
    GameBoard();
    ~GameBoard();
    void CleanBoard();
    void ResetBoard();
    void GenerateFigures(int line, bool isBlack);
    BoardTile* getDiagonalLine(const BoardTile& first, const BoardTile& last);
    BoardTile* getCardinalLine(const BoardTile& first, const BoardTile& last);
    void PrintBoard(HANDLE &console);
private:
    const static int BoardSize = 8;
    BoardTile board[BoardSize][BoardSize];
    King* whiteKing;
    King* blackKing;
};


#endif //CHESSGAME_GAMEBOARD_H
