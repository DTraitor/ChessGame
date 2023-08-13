#ifndef CHESSGAME_ROOK_H
#define CHESSGAME_ROOK_H


#include "../ChessPiece.h"

class Rook : public ChessPiece{
public:
    Rook(const bool& isBlack) : ChessPiece(isBlack, 'P') {}
    bool canMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board) override;
};


#endif //CHESSGAME_ROOK_H
