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

    std::string BoardTile::GenerateDefaultString() {
        ConsoleControl::TextFormat format{ConsoleControl::TextAttributes::NONE};
        format.backgroundColor = ((getX() + getY()) & 1) ? oddBackground : evenBackground;
        if (hasPiece())
            format.textColor = getPiece()->IsBlack() ? blackColor : whiteColor;

        return format.FormatString(hasPiece() ? getPiece()->GetIcon() : ' ');
    }

    std::string BoardTile::GeneratedSelectedString() {
        ConsoleControl::TextFormat format{ConsoleControl::TextAttributes::NONE};
        format.backgroundColor = selectedBackground;
        if (hasPiece())
            format.textColor = getPiece()->IsBlack() ? blackColor : whiteColor;

        return format.FormatString(hasPiece() ? getPiece()->GetIcon() : ' ');
    }


} // ChessGame