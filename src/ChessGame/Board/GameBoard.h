#ifndef CHESSGAME_GAMEBOARD_H
#define CHESSGAME_GAMEBOARD_H


#include "BoardTile.h"
#include "../Chess/ChessTypes.h"

namespace ChessGame {
    class GameBoard {
    public:
        GameBoard();

        ~GameBoard();

        void CleanBoard();

        void ResetBoard();

        void GenerateFigures(int line, bool isBlack);

        BoardTile *GetDiagonalLine(const BoardTile &first, const BoardTile &last);

        BoardTile *GetCardinalLine(const BoardTile &first, const BoardTile &last);

        void PrintBoard();

        inline BoardTile &GetTileAt(int x, int y){
            return board[y][x];
        }

        const static int BoardSize = 8;
    private:
        BoardTile board[BoardSize][BoardSize];
        King *whiteKing{};
        King *blackKing{};
    };
} // ChessGame


#endif //CHESSGAME_GAMEBOARD_H
