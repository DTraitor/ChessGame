#ifndef CHESSGAME_KING_H
#define CHESSGAME_KING_H


#include "../ChessPiece.h"


class King : public ChessPiece {
    public:
    King(const bool& isBlack) : ChessPiece(isBlack, 'K') {}
    bool canMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board) override;
};


#endif //CHESSGAME_KING_H
