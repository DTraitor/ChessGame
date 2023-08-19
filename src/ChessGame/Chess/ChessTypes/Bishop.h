#ifndef CHESSGAME_BISHOP_H
#define CHESSGAME_BISHOP_H


#include "../ChessPiece.h"

namespace ChessGame {
    class Bishop : public ChessPiece{
    public:
        Bishop(BoardTile *ourTile, const bool& isBlack) : ChessPiece(ourTile, isBlack, 'B') {}
        bool CanMove(BoardTile &previousTile, BoardTile &newTile) override;
    };
} // ChessPiece


#endif //CHESSGAME_BISHOP_H
