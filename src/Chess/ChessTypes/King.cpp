#include "../../Board/GameBoard.h"
#include "King.h"

bool King::canMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board) {
    if(!ChessPiece::canMove(ourTile, tileToMove, board))
        return false;

    if(std::abs(ourTile.getX() - tileToMove.getX()) > 1 || std::abs(ourTile.getY() - tileToMove.getY()) > 1)
        return false;

    //TODO: Add if a check for a mate

    return true;
}
