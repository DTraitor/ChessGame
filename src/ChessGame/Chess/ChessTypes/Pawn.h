#ifndef CHESSGAME_PAWN_H
#define CHESSGAME_PAWN_H


#include "../ChessPiece.h"

namespace ChessGame {
    class Pawn : public ChessPiece {
    public:
        Pawn(const bool &isBlack) : ChessPiece(isBlack, 'P') {}

        bool canMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board) override;
    };
} // ChessGame


#endif //CHESSGAME_PAWN_H
