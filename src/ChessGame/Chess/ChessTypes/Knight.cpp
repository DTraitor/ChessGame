#include "../../Board/GameBoard.h"
#include "Knight.h"

namespace ChessGame {
    bool Knight::CanMove(BoardTile &previousTile, BoardTile &newTile) {
        if (!ChessPiece::CanMove(previousTile, newTile))
            return false;

        int deltaX = std::abs(previousTile.GetX() - newTile.GetX());
        int deltaY = std::abs(previousTile.GetY() - newTile.GetY());

        if (deltaX != 2 && deltaY != 2)
            return false;

        if (deltaX != 1 && deltaY != 1)
            return false;

        return true;
    }
} // ChessGame
