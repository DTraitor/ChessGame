#include "../../Board/GameBoard.h"
#include "Bishop.h"
#include <stdexcept>

namespace ChessGame {
    bool Bishop::canMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board) {
        if (!ChessPiece::canMove(ourTile, tileToMove, board))
            return false;

        try {
            checkArray(
                    board.GetDiagonalLine(ourTile, tileToMove),
                    tileToMove.getX() - ourTile.getX()
            );
        }
        catch (std::logic_error &e) {
            return false;
        }

        return true;
    }
} // ChessGame
