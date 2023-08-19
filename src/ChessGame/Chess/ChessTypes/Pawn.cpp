#include "../../Board/GameBoard.h"
#include "Pawn.h"
#include <cmath>

namespace ChessGame {
    bool Pawn::CanMove(BoardTile &previousTile, BoardTile &newTile) {
        if (!ChessPiece::CanMove(previousTile, newTile))
            return false;

        //If we try to move left or right for more than 1 tile
        if (std::abs(newTile.GetX() - previousTile.GetX()) > 1)
            return false;

        //If we try to move backwards or more than 1 tile forward
        if (IsBlack()) {
            if ((previousTile.GetY() - newTile.GetY()) != -1)
                return false;
        } else {
            if ((previousTile.GetY() - newTile.GetY()) != 1)
                return false;
        }

        if (newTile.HasPiece()) {
            //Pawn can attack only diagonally
            if (!(newTile.GetX() - previousTile.GetX()))
                return false;
        } else {
            //Pawn cant move diagonally without attacking
            if (newTile.GetX() - previousTile.GetX())
                return false;
        }

        return true;
    }
} // ChessGame
