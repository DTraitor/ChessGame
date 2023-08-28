#ifndef CHESSGAME_KING_H
#define CHESSGAME_KING_H


#include "../ChessPiece.h"

namespace ChessGame {
    class King : public ChessPiece {
    public:
        King(BoardTile *ourTile, const bool &isBlack) : ChessPiece(ourTile, isBlack, 'K') {}
        bool CanMove(BoardTile &previousTile, BoardTile &newTile) override;
        bool IsMate(BoardTile &toCheck);
        bool IsCheckmate(BoardTile &toCheck);

        inline bool IsMate(){
            return IsMate(GetOurTile());
        }
        inline bool IsCheckmate(){
            return IsCheckmate(GetOurTile());
        }

    };

    inline bool checkArrayForMate(std::vector<BoardTile> toCheck, BoardTile &ourTile){
        for(BoardTile &tile : toCheck){
            if(!tile.HasPiece())
                continue;
            return tile.GetPiece()->CanMove(tile, ourTile);
        }
        return false;
    }
} // ChessGame


#endif //CHESSGAME_KING_H
