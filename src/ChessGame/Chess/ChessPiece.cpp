#include "ChessPiece.h"
#include "../Board/BoardTile.h"

namespace ChessGame {
    bool ChessPiece::CanMove(BoardTile &previousTile, BoardTile &newTile) {
        if ((previousTile.GetX() == newTile.GetX()) && (previousTile.GetY() == newTile.GetY()))
            return false;

        if (newTile.HasPiece() && (newTile.GetPiece()->IsBlack() == this->IsBlack()))
            return false;

        return true;
    }

    bool ChessPiece::Move(BoardTile &newTile) {
        if(!CanMove(newTile))
            return false;
        BoardTile &oldTile = GetOurTile();
        newTile.SetPiece(std::shared_ptr<ChessPiece>(this));
        oldTile.RemovePiece();
        ourTile = &newTile;
        return true;
    }

    bool ChessPiece::CanMoveAlongLine(std::vector<BoardTile> line) const {
        for(int i = 0; i < line.size() - 1; i++){
            if(line[i].HasPiece())
                return false;
        }

        BoardTile &lastTile = line[line.size() - 1];
        if(lastTile.HasPiece() && lastTile.GetPiece()->IsBlack() == IsBlack())
            return false;
        return true;
    }
} // ChessGame
