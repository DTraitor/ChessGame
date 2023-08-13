#ifndef CHESSGAME_QUEEN_H
#define CHESSGAME_QUEEN_H


#include "../ChessPiece.h"

class Queen : public ChessPiece {
public:
    Queen(const bool& isBlack) : ChessPiece(isBlack, 'P') {}
    bool canMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board) override;
};


#endif //CHESSGAME_QUEEN_H
