#include "../../Board/GameBoard.h"
#include "Bishop.h"
#include <stdexcept>

namespace ChessGame {
    bool Bishop::CanMove(BoardTile &previousTile, BoardTile &newTile) {
        if (!ChessPiece::CanMove(previousTile, newTile))
            return false;

        try {
            return CanMoveAlongLine(GetBoard().GetDiagonalLine(previousTile, newTile));
        }
        catch (std::logic_error &e) {
            return false;
        }
    }
} // ChessGame
