#ifndef CHESSGAME_QUEEN_H
#define CHESSGAME_QUEEN_H


#include "../ChessPiece.h"

namespace ChessGame {
    class Queen : public ChessPiece {
    public:
        Queen(BoardTile *ourTile, const bool &isBlack) : ChessPiece(ourTile, isBlack, 'Q') {}

        bool CanMove(BoardTile &previousTile, BoardTile &newTile) override;
    };
} // ChessGame


#endif //CHESSGAME_QUEEN_H
