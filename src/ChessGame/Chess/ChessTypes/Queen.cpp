#include "../../Board/GameBoard.h"
#include "Queen.h"
#include <stdexcept>

namespace ChessGame {
    bool Queen::CanMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board) {
        if (!ChessPiece::CanMove(ourTile, tileToMove, board))
            return false;

        if ((tileToMove.GetX() - ourTile.GetX()) && (tileToMove.GetY() - ourTile.GetY())) {
            if (std::abs(tileToMove.GetX() - ourTile.GetX()) != std::abs(tileToMove.GetY() - ourTile.GetY()))
                return false;

            try {
                checkArray(board.GetDiagonalLine(ourTile, tileToMove));
            }
            catch (std::logic_error &e) {
                return false;
            }
        } else {
            try {
                checkArray(board.GetCardinalLine(ourTile, tileToMove));
            }
            catch (std::logic_error &e) {
                return false;
            }
        }
        return true;
    }
}
