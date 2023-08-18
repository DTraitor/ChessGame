#include "../../Board/GameBoard.h"
#include "Pawn.h"
#include <cmath>

namespace ChessGame {
    bool Pawn::CanMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board) {
        if (!ChessPiece::CanMove(ourTile, tileToMove, board))
            return false;

        //If we try to move left or right for more than 1 tile
        if (std::abs(tileToMove.GetX() - ourTile.GetX()) > 1)
            return false;

        //If we try to move backwards or more than 1 tile forward
        if (IsBlack()) {
            if ((ourTile.GetY() - tileToMove.GetY()) != -1)
                return false;
        } else {
            if ((ourTile.GetY() - tileToMove.GetY()) != 1)
                return false;
        }

        if (tileToMove.HasPiece()) {
            //Pawn can attack only diagonally
            if (!(tileToMove.GetX() - ourTile.GetX()))
                return false;
        } else {
            //Pawn cant move diagonally without attacking
            if (tileToMove.GetX() - ourTile.GetX())
                return false;
        }

        return true;
    }
} // ChessGame
