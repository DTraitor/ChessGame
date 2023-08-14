#include "../../Board/GameBoard.h"
#include "Pawn.h"
#include <cmath>

bool Pawn::canMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board) {
    if(!ChessPiece::canMove(ourTile, tileToMove, board))
        return false;

    //If we try to move left or right for more than 1 tile
    if(std::abs(tileToMove.getX() - ourTile.getX()) > 1)
        return false;

    //If we try to move backwards or more than 1 tile forward
    if(IsBlack()){
        if((ourTile.getY() - tileToMove.getY()) != 1)
            return false;
    }
    else{
        if((ourTile.getY() - tileToMove.getY()) != -1)
            return false;
    }

    if(tileToMove.hasPiece()){
        //Pawn can attack only diagonally
        if(!(tileToMove.getX() - ourTile.getX()))
            return false;
    }
    else{
        //Pawn cant move diagonally without attacking
        if(tileToMove.getX() - ourTile.getX())
            return false;
    }

    return true;
}
