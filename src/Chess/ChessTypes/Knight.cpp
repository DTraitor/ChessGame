#include "../../Board/GameBoard.h"
#include "Knight.h"

bool Knight::canMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board) {
    if(!ChessPiece::canMove(ourTile, tileToMove, board))
        return false;

    int deltaX = std::abs(ourTile.getX() - tileToMove.getX());
    int deltaY = std::abs(ourTile.getY() - tileToMove.getY());

    if(deltaX != 2 && deltaY != 2)
        return false;

    if(deltaX != 1 && deltaY != 1)
        return false;

    return true;
}
