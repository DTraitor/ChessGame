#ifndef CHESSGAME_GAMEBOARD_H
#define CHESSGAME_GAMEBOARD_H


#include "BoardTile.h"
#include "../Chess/ChessTypes.h"
#include "../ConsoleOuput/ConsoleControl.h"

class GameBoard {
public:
    GameBoard();
    ~GameBoard();
    void CleanBoard();
    void ResetBoard();
    void GenerateFigures(int line, bool isBlack);
    BoardTile* GetDiagonalLine(const BoardTile& first, const BoardTile& last);
    BoardTile* GetCardinalLine(const BoardTile& first, const BoardTile& last);
    void PrintBoard();
private:
    const static int BoardSize = 8;
    const static ConsoleControl::TextColors whiteColor = ConsoleControl::TextColors::WHITE;
    const static ConsoleControl::TextColors blackColor = ConsoleControl::TextColors::BLACK;
    const static ConsoleControl::BackgroundColors oddBackground = ConsoleControl::BackgroundColors::CYAN;
    const static ConsoleControl::BackgroundColors evenBackground = ConsoleControl::BackgroundColors::GREEN;

    BoardTile board[BoardSize][BoardSize];
    King* whiteKing;
    King* blackKing;
};


#endif //CHESSGAME_GAMEBOARD_H
