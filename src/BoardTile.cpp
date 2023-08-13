#include "ChessPiece.h"
#include "BoardTile.h"

BoardTile::BoardTile(const int& x, const int& y) {
    this->x = x;
    this->y = y;
}

BoardTile::BoardTile() {
    this->x = 0;
    this->y = 0;
}
