#include "../GameBoard.h"
#include "Rook.h"
#include <stdexcept>

bool Rook::canMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board) {
    if(!ChessPiece::canMove(ourTile, tileToMove, board))
        return false;

    try{
        checkArray(
                board.getCardinalLine(ourTile, tileToMove),
                (tileToMove.getX() - ourTile.getX()) || (tileToMove.getY() - ourTile.getY())
        );
    }
    catch (std::logic_error& e){
        return false;
    }

    return true;
}
