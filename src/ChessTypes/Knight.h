#ifndef CHESSGAME_KNIGHT_H
#define CHESSGAME_KNIGHT_H


#include "../ChessPiece.h"

class Knight : public ChessPiece {
public:
    Knight(const bool& isBlack) : ChessPiece(isBlack, 'P') {}
    bool canMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board) override;
};


#endif //CHESSGAME_KNIGHT_H
