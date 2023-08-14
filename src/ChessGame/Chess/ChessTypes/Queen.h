#ifndef CHESSGAME_QUEEN_H
#define CHESSGAME_QUEEN_H


#include "../ChessPiece.h"

namespace ChessGame {
    class Queen : public ChessPiece {
    public:
        Queen(const bool &isBlack) : ChessPiece(isBlack, 'Q') {}

        bool canMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board) override;
    };
} // ChessGame


#endif //CHESSGAME_QUEEN_H
