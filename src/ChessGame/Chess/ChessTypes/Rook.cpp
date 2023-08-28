#include "../../Board/GameBoard.h"
#include "Rook.h"
#include <stdexcept>

namespace ChessGame {
    bool Rook::CanMove(BoardTile &previousTile, BoardTile &newTile) {
        if (!ChessPiece::CanMove(previousTile, newTile))
            return false;

        try {
            return CanMoveAlongLine(GetBoard().GetCardinalLine(previousTile, newTile));
        }
        catch (std::logic_error &e) {
            return false;
        }
    }
} // ChessGame
