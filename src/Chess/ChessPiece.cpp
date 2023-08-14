#include "ChessPiece.h"
#include "../Board/BoardTile.h"

bool ChessPiece::canMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board) {
    if((ourTile.getX() == tileToMove.getX()) && (ourTile.getY() == tileToMove.getY()))
        return false;

    if (tileToMove.hasPiece() && (tileToMove.getPiece()->IsBlack() == this->IsBlack()))
        return false;

    return true;
}
