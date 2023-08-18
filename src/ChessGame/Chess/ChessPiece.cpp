#include "ChessPiece.h"
#include "../Board/BoardTile.h"

namespace ChessGame {
    bool ChessPiece::CanMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board) {
        if ((ourTile.GetX() == tileToMove.GetX()) && (ourTile.GetY() == tileToMove.GetY()))
            return false;

        if (tileToMove.HasPiece() && (tileToMove.GetPiece()->IsBlack() == this->IsBlack()))
            return false;

        return true;
    }
} // ChessGame
