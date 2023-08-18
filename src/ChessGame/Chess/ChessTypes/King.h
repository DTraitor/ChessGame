#ifndef CHESSGAME_KING_H
#define CHESSGAME_KING_H


#include "../ChessPiece.h"

namespace ChessGame {
    class King : public ChessPiece {
    public:
        King(const bool &isBlack) : ChessPiece(isBlack, 'K') {}
        bool CanMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board) override;
        bool IsMate(BoardTile &toCheck, GameBoard &board);
        bool IsCheckmate(BoardTile &toCheck, GameBoard &board);
    };

    inline bool checkArrayForMate(std::vector<BoardTile> toCheck, BoardTile &ourTile, GameBoard &board, bool isBlack){
        for(BoardTile &tile : toCheck){
            if(!tile.HasPiece())
                continue;
            return tile.GetPiece()->CanMove(tile, ourTile, board);
        }
        return false;
    }
} // ChessGame


#endif //CHESSGAME_KING_H
