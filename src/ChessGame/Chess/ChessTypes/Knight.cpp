#include "../../Board/GameBoard.h"
#include "Knight.h"

namespace ChessGame {
    bool Knight::CanMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board) {
        if (!ChessPiece::CanMove(ourTile, tileToMove, board))
            return false;

        int deltaX = std::abs(ourTile.GetX() - tileToMove.GetX());
        int deltaY = std::abs(ourTile.GetY() - tileToMove.GetY());

        if (deltaX != 2 && deltaY != 2)
            return false;

        if (deltaX != 1 && deltaY != 1)
            return false;

        return true;
    }
} // ChessGame
