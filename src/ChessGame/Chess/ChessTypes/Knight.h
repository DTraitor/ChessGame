#ifndef CHESSGAME_KNIGHT_H
#define CHESSGAME_KNIGHT_H


#include "../ChessPiece.h"

namespace ChessGame {
    class Knight : public ChessPiece {
    public:
        Knight(BoardTile *ourTile, const bool &isBlack) : ChessPiece(ourTile, isBlack, 'N') {}

        bool CanMove(BoardTile &previousTile, BoardTile &newTile) override;
    };
} // ChessGame


#endif //CHESSGAME_KNIGHT_H
