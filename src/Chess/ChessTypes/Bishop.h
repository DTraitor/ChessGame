#ifndef CHESSGAME_BISHOP_H
#define CHESSGAME_BISHOP_H


#include "../ChessPiece.h"

class Bishop : public ChessPiece{
public:
    Bishop(const bool& isBlack) : ChessPiece(isBlack, 'B') {}
    bool canMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board) override;
};


#endif //CHESSGAME_BISHOP_H
