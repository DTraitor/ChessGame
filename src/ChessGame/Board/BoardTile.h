#ifndef CHESSGAME_BOARDTILE_H
#define CHESSGAME_BOARDTILE_H


#include "../Chess/ChessPiece.h"

namespace ChessGame {
    class BoardTile {
    public:
        BoardTile();
        BoardTile(const int& x, const int& y);
        inline int getX() const{
            return x;
        }
        inline int getY() const{
            return y;
        }
        inline bool hasPiece() const{
            return piece;
        }
        inline ChessPiece* getPiece(){
            return piece;
        }
        inline void setPiece(ChessPiece* newPiece){
            piece = newPiece;
        }

    private:
        ChessPiece* piece = nullptr;
        int x;
        int y;
    };

    inline bool checkArray(BoardTile* array, int size){
        for (int i = 0; i < std::abs(size); i++) {
            if(array[i].hasPiece()){
                delete array;
                return false;
            }
        }
        delete array;
        return true;
    }
} // ChessGame


#endif //CHESSGAME_BOARDTILE_H
