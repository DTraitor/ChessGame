#include "../../Board/GameBoard.h"
#include "Queen.h"
#include <stdexcept>

namespace ChessGame {
    bool Queen::CanMove(BoardTile &previousTile, BoardTile &newTile) {
        if (!ChessPiece::CanMove(previousTile, newTile))
            return false;

        if ((newTile.GetX() - previousTile.GetX()) && (newTile.GetY() - previousTile.GetY())) {
            if (std::abs(newTile.GetX() - previousTile.GetX()) != std::abs(newTile.GetY() - previousTile.GetY()))
                return false;

            try {
                return CanMoveAlongLine(board.GetDiagonalLine(previousTile, newTile));
            }
            catch (std::logic_error &e) {
                return false;
            }
        }
        try {
            return CanMoveAlongLine(board.GetCardinalLine(previousTile, newTile));
        }
        catch (std::logic_error &e) {
            return false;
        }
    }
}
