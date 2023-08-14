#ifndef CHESSGAME_KING_H
#define CHESSGAME_KING_H


#include "../ChessPiece.h"

namespace ChessGame {
    class King : public ChessPiece {
    public:
        King(const bool &isBlack) : ChessPiece(isBlack, 'K') {}
        bool canMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board) override;
    };
} // ChessGame


#endif //CHESSGAME_KING_H
