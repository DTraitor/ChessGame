#ifndef CHESSGAME_BOARDTILE_H
#define CHESSGAME_BOARDTILE_H


#include <cstdint>
#include <memory>
#include <vector>
#include <algorithm>
#include "../Chess/ChessPiece.h"
#include "../../ConsoleControl/ConsoleControl.h"

using std::int8_t;

namespace ChessGame {
    class BoardTile {
    public:
        BoardTile() : x(0), y(0) {}
        BoardTile(const int8_t& x, const int8_t& y) : x(x), y(y) {}
        inline int32_t GetX() const{
            return x;
        }
        inline int32_t GetY() const{
            return y;
        }
        inline bool HasPiece() const{
            return piece != nullptr;
        }
        inline std::shared_ptr<ChessPiece> GetPiece() {
            return piece;
        }
        inline void SetPiece(std::shared_ptr<ChessPiece> newPiece){
            piece = std::move(newPiece);
        }
        inline void RemovePiece(){
            piece = nullptr;
        }
        inline bool IsSelected() const{
            return isSelected;
        }
        inline void SetSelected(bool selection){
            isSelected = selection;
        }

        std::string GenerateDefaultString();
        std::string GenerateHoverString();
        std::string GenerateSelectedString();

    const static ConsoleControl::TextColors whiteColor = ConsoleControl::TextColors::WHITE;
    const static ConsoleControl::TextColors blackColor = ConsoleControl::TextColors::BLACK;
    const static ConsoleControl::BackgroundColors oddBackground = ConsoleControl::BackgroundColors::CYAN;
    const static ConsoleControl::BackgroundColors evenBackground = ConsoleControl::BackgroundColors::GREEN;
    const static ConsoleControl::BackgroundColors hoverBackground = ConsoleControl::BackgroundColors::MAGENTA;
    const static ConsoleControl::BackgroundColors selectedBackground = ConsoleControl::BackgroundColors::YELLOW;

    private:
        std::shared_ptr<ChessPiece> piece;
        bool isSelected = false;
        const int8_t x;
        const int8_t y;
    };

    inline bool checkArray(std::vector<BoardTile> toCheck){
        return std::ranges::all_of(
                toCheck.begin(),
                toCheck.end(),
                [](auto const& s) {return !s.HasPiece();}
                );
    }
} // ChessGame


#endif //CHESSGAME_BOARDTILE_H
