#include "../../Board/GameBoard.h"
#include "Queen.h"
#include <stdexcept>

bool Queen::canMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board) {
    if(!ChessPiece::canMove(ourTile, tileToMove, board))
        return false;

    if((tileToMove.getX() - ourTile.getX()) && (tileToMove.getY() - ourTile.getY())){
        if(std::abs(tileToMove.getX() - ourTile.getX()) != std::abs(tileToMove.getY() - ourTile.getY()))
            return false;

        try{
            checkArray(
                    board.GetDiagonalLine(ourTile, tileToMove),
                    tileToMove.getX() - ourTile.getX()
            );
        }
        catch (std::logic_error& e){
            return false;
        }
    }
    else{
        try{
            checkArray(
                    board.GetCardinalLine(ourTile, tileToMove),
                    (tileToMove.getX() - ourTile.getX()) || (tileToMove.getY() - ourTile.getY())
            );
        }
        catch (std::logic_error& e){
            return false;
        }
    }
    return true;
}
