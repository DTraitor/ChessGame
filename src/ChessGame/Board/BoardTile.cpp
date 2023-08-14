#include "../Chess/ChessPiece.h"
#include "BoardTile.h"

namespace ChessGame {
    BoardTile::BoardTile(const int &x, const int &y) {
        this->x = x;
        this->y = y;
    }

    BoardTile::BoardTile() {
        this->x = 0;
        this->y = 0;
    }
} // ChessGame