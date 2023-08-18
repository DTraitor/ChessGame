#include "../../Board/GameBoard.h"
#include "Bishop.h"
#include <stdexcept>

namespace ChessGame {
    bool Bishop::CanMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board) {
        if (!ChessPiece::CanMove(ourTile, tileToMove, board))
            return false;

        try {
            checkArray(board.GetDiagonalLine(ourTile, tileToMove));
        }
        catch (std::logic_error &e) {
            return false;
        }

        return true;
    }
} // ChessGame
