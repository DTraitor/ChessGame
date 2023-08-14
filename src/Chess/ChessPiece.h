#ifndef CHESSGAME_CHESSPIECE_H
#define CHESSGAME_CHESSPIECE_H


#include <cmath>

class BoardTile;
class GameBoard;


class ChessPiece {
public:
    ChessPiece(const bool& isBlack, const char& newIcon) : black(isBlack), icon(newIcon) {}
    inline char GetIcon() const{
        return icon;
    }
    inline bool IsBlack() const{
        return black;
    }
    //If we can move onto this tile
    virtual bool canMove(BoardTile &ourTile, BoardTile &tileToMove, GameBoard &board);

private:
    // Character representing this piece
    const char icon;
    // Whether it's black or white
    bool black;
};


#endif //CHESSGAME_CHESSPIECE_H
