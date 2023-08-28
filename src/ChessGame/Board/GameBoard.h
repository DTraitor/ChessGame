#ifndef CHESSGAME_GAMEBOARD_H
#define CHESSGAME_GAMEBOARD_H


#include "BoardTile.h"
#include "../Chess/ChessTypes.h"
#include <memory>
#include <array>
#include <vector>

namespace ChessGame {
    class GameBoard {
    public:
        GameBoard();
        ~GameBoard();
        void CleanBoard();
        void ResetBoard();
        void PrintBoard();
        std::vector<BoardTile> GetDiagonalLine(const BoardTile &first, const BoardTile &last);
        std::vector<BoardTile> GetCardinalLine(const BoardTile &first, const BoardTile &last);

        inline BoardTile &GetTileAt(uint8_t x, uint8_t y){
            return board[y - 1][x - 1];
        }

        inline std::shared_ptr<King> GetKing(bool isBlack){
            return isBlack ? blackKing : whiteKing;
        }

        const static int8_t BoardSize = 8;
    private:
        void GenerateFigures(int line, bool isBlack);

        //This is ugly but necessary
        std::array<std::array<BoardTile, BoardSize>, BoardSize> board = {{
            {{{this, 1, 1}, {this, 2, 1}, {this, 3, 1}, {this, 4, 1}, {this, 5, 1}, {this, 6, 1}, {this, 7, 1}, {this, 8, 1}}},
            {{{this, 1, 2}, {this, 2, 2}, {this, 3, 2}, {this, 4, 2}, {this, 5, 2}, {this, 6, 2}, {this, 7, 2}, {this, 8, 2}}},
            {{{this, 1, 3}, {this, 2, 3}, {this, 3, 3}, {this, 4, 3}, {this, 5, 3}, {this, 6, 3}, {this, 7, 3}, {this, 8, 3}}},
            {{{this, 1, 4}, {this, 2, 4}, {this, 3, 4}, {this, 4, 4}, {this, 5, 4}, {this, 6, 4}, {this, 7, 4}, {this, 8, 4}}},
            {{{this, 1, 5}, {this, 2, 5}, {this, 3, 5}, {this, 4, 5}, {this, 5, 5}, {this, 6, 5}, {this, 7, 5}, {this, 8, 5}}},
            {{{this, 1, 6}, {this, 2, 6}, {this, 3, 6}, {this, 4, 6}, {this, 5, 6}, {this, 6, 6}, {this, 7, 6}, {this, 8, 6}}},
            {{{this, 1, 7}, {this, 2, 7}, {this, 3, 7}, {this, 4, 7}, {this, 5, 7}, {this, 6, 7}, {this, 7, 7}, {this, 8, 7}}},
            {{{this, 1, 8}, {this, 2, 8}, {this, 3, 8}, {this, 4, 8}, {this, 5, 8}, {this, 6, 8}, {this, 7, 8}, {this, 8, 8}}}
        }};
        std::shared_ptr<King> whiteKing;
        std::shared_ptr<King> blackKing;
    };

} // ChessGame


#endif //CHESSGAME_GAMEBOARD_H
