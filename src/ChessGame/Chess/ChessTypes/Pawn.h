#ifndef CHESSGAME_PAWN_H
#define CHESSGAME_PAWN_H


#include "../ChessPiece.h"

namespace ChessGame {
    class Pawn : public ChessPiece {
    public:
        Pawn(BoardTile *ourTile, const bool &isBlack) : ChessPiece(ourTile, isBlack, 'P') {}

        bool CanMove(BoardTile &previousTile, BoardTile &newTile) override;
    };
} // ChessGame


#endif //CHESSGAME_PAWN_H
