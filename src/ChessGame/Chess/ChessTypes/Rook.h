#ifndef CHESSGAME_ROOK_H
#define CHESSGAME_ROOK_H


#include "../ChessPiece.h"

namespace ChessGame {
    class Rook : public ChessPiece {
    public:
        Rook(BoardTile *ourTile, const bool &isBlack) : ChessPiece(ourTile, isBlack, 'R') {}

        bool CanMove(BoardTile &previousTile, BoardTile &newTile) override;
    };
} //ChessGame


#endif //CHESSGAME_ROOK_H
