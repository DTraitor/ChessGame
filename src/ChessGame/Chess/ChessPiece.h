#ifndef CHESSGAME_CHESSPIECE_H
#define CHESSGAME_CHESSPIECE_H


#include <cmath>
#include <vector>

namespace ChessGame {
    class BoardTile;
    class GameBoard;

    class ChessPiece {
    public:
        ChessPiece(BoardTile *ourTile, const bool &isBlack, const char &newIcon) : ourTile(ourTile), black(isBlack), icon(newIcon) {}

        //If we can move onto this tile
        virtual bool CanMove(BoardTile &previousTile, BoardTile &newTile);

        inline bool CanMove(BoardTile &tileToMove){
            return CanMove(GetOurTile(), tileToMove);
        }

        bool Move(BoardTile &newTile);
        void ForceMove(BoardTile &newTile);

        inline BoardTile &GetOurTile(){
            return *ourTile;
        }

        [[nodiscard]] inline char GetIcon() const {
            return icon;
        }

        [[nodiscard]] inline bool IsBlack() const {
            return black;
        }

        GameBoard& GetBoard();

    protected:
        [[nodiscard]] bool CanMoveAlongLine(std::vector<BoardTile> line) const;

    private:
        BoardTile *ourTile;
        // Character representing this piece
        const char icon;
        // Whether it's black or white
        const bool black;
    };
} // ChessGame

#endif //CHESSGAME_CHESSPIECE_H
