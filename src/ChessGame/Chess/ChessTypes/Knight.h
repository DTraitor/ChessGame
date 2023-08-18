#ifndef CHESSGAME_KNIGHT_H
#define CHESSGAME_KNIGHT_H


#include "../ChessPiece.h"

namespace ChessGame {
    class Knight : public ChessPiece {
    public:
        Knight(const bool &isBlack) : ChessPiece(isBlack, 'N') {}

        bool CanMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board) override;
    };
} // ChessGame


#endif //CHESSGAME_KNIGHT_H
