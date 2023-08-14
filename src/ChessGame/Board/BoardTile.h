#ifndef CHESSGAME_BOARDTILE_H
#define CHESSGAME_BOARDTILE_H


#include "../Chess/ChessPiece.h"
#include "../../ConsoleControl/ConsoleControl.h"

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
        std::string GenerateDefaultString();
        std::string GeneratedSelectedString();

    const static ConsoleControl::TextColors whiteColor = ConsoleControl::TextColors::WHITE;
    const static ConsoleControl::TextColors blackColor = ConsoleControl::TextColors::BLACK;
    const static ConsoleControl::BackgroundColors oddBackground = ConsoleControl::BackgroundColors::CYAN;
    const static ConsoleControl::BackgroundColors evenBackground = ConsoleControl::BackgroundColors::GREEN;
    const static ConsoleControl::BackgroundColors selectedBackground = ConsoleControl::BackgroundColors::RED;

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
