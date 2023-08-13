#ifndef CHESSGAME_GAMEBOARD_H
#define CHESSGAME_GAMEBOARD_H


#include "BoardTile.h"
#include "ChessTypes.h"

class GameBoard {
public:
    GameBoard();
    ~GameBoard();
    void CleanBoard();
    void ResetBoard();
    void GenerateFigures(int line, bool isBlack);
    BoardTile* getDiagonalLine(const BoardTile& first, const BoardTile& last);
    BoardTile* getCardinalLine(const BoardTile& first, const BoardTile& last);
private:
    const static int BoardSize = 8;
    BoardTile board[BoardSize][BoardSize];
    King* whiteKing;
    King* blackKing;
};


#endif //CHESSGAME_GAMEBOARD_H
