#ifndef CHESSGAME_ROOK_H
#define CHESSGAME_ROOK_H


#include "../ChessPiece.h"

namespace ChessGame {
    class Rook : public ChessPiece {
    public:
        Rook(const bool &isBlack) : ChessPiece(isBlack, 'R') {}

        bool CanMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board) override;
    };
} //ChessGame


#endif //CHESSGAME_ROOK_H
