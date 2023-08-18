#include "../Chess/ChessPiece.h"
#include "BoardTile.h"

namespace ChessGame {
    std::string BoardTile::GenerateDefaultString() {
        ConsoleControl::TextFormat format{ConsoleControl::TextAttributes::NONE};
        format.backgroundColor = ((GetX() + GetY()) & 1) ? oddBackground : evenBackground;
        if (HasPiece())
            format.textColor = GetPiece()->IsBlack() ? blackColor : whiteColor;

        return format.FormatString(HasPiece() ? GetPiece()->GetIcon() : ' ');
    }

    std::string BoardTile::GenerateHoverString() {
        ConsoleControl::TextFormat format{ConsoleControl::TextAttributes::NONE};
        format.backgroundColor = hoverBackground;
        if (HasPiece())
            format.textColor = GetPiece()->IsBlack() ? blackColor : whiteColor;

        return format.FormatString(HasPiece() ? GetPiece()->GetIcon() : ' ');
    }

    std::string BoardTile::GenerateSelectedString() {
        ConsoleControl::TextFormat format{ConsoleControl::TextAttributes::NONE};
        format.backgroundColor = selectedBackground;
        if (HasPiece())
            format.textColor = GetPiece()->IsBlack() ? blackColor : whiteColor;

        return format.FormatString(HasPiece() ? GetPiece()->GetIcon() : ' ');
    }

} // ChessGame