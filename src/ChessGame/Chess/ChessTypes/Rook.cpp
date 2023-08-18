#include "../../Board/GameBoard.h"
#include "Rook.h"
#include <stdexcept>

namespace ChessGame {
    bool Rook::CanMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board) {
        if (!ChessPiece::CanMove(ourTile, tileToMove, board))
            return false;

        try {
            checkArray(board.GetCardinalLine(ourTile, tileToMove));
        }
        catch (std::logic_error &e) {
            return false;
        }

        return true;
    }
} // ChessGame
