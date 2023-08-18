#include "GameBoard.h"
#include <cmath>
#include <memory>
#include <stdexcept>
#include <iostream>

template <typename T>
int getSign(T val) {
    return (0 < val) - (val < 0);
}

namespace ChessGame {
    GameBoard::GameBoard() {
        ResetBoard();
    }

    GameBoard::~GameBoard() {
        CleanBoard();
    }

    void GameBoard::CleanBoard() {
        for (auto &line: board) {
            for (BoardTile &tile: line) {
                tile.RemovePiece();
            }
        }
    }

    void GameBoard::ResetBoard() {
        CleanBoard();

        //Generate black pieces
        GenerateFigures(0, true);
        for (BoardTile &tile: board[1]) {
            tile.SetPiece(std::make_shared<Pawn>(true));
        }

        //Generate white pieces
        GenerateFigures(BoardSize - 1, false);
        for (BoardTile &tile: board[BoardSize - 2]) {
            tile.SetPiece(std::make_shared<Pawn>(false));
        }
    }

    void GameBoard::GenerateFigures(int line, bool isBlack) {
        board[line][0].SetPiece(std::make_shared<Rook>(isBlack));
        board[line][1].SetPiece(std::make_shared<Knight>(isBlack));
        board[line][2].SetPiece(std::make_shared<Bishop>(isBlack));
        board[line][3].SetPiece(std::make_shared<Queen>(isBlack));

        if (isBlack) {
            blackKing = std::make_shared<King>(true);
            board[line][4].SetPiece(blackKing);
        } else {
            whiteKing = std::make_shared<King>(false);
            board[line][4].SetPiece(whiteKing);
        }

        board[line][5].SetPiece(std::make_shared<Bishop>(isBlack));
        board[line][6].SetPiece(std::make_shared<Knight>(isBlack));
        board[line][7].SetPiece(std::make_shared<Rook>(isBlack));
    }

    std::vector<BoardTile> GameBoard::GetDiagonalLine(const BoardTile &first, const BoardTile &last) {
        if (std::abs(first.GetX() - last.GetX()) != std::abs(first.GetY() - last.GetY()))
            throw std::logic_error("Tried to get diagonal line between 2 non-diagonal tiles!");

        int signX = getSign(last.GetX() - first.GetX());
        int signY = getSign(last.GetY() - first.GetY());

        std::vector<BoardTile> returnArray(std::abs(last.GetX() - first.GetX()));

        for (int i = 1; i <= std::abs(last.GetX() - first.GetX()); i++) {
            returnArray.push_back(board[first.GetX() + (i * signX)][first.GetY() + (i * signY)]);
        }

        return returnArray;
    }

    std::vector<BoardTile> GameBoard::GetCardinalLine(const BoardTile &first, const BoardTile &last) {
        if ((first.GetX() != last.GetX()) && (first.GetY() != last.GetY()))
            throw std::logic_error("Tried to get cardinal line between 2 diagonal tiles!");

        if (last.GetX() - first.GetX()) {
            std::vector<BoardTile> returnArray(std::abs(last.GetX() - first.GetX()));

            int signX = getSign(last.GetX() - first.GetX());

            for (int i = 1; i <= std::abs(last.GetX() - first.GetX()); i++) {
                returnArray.push_back(board[first.GetX() + (i * signX)][first.GetY()]);
            }
            return returnArray;
        } else {
            std::vector<BoardTile> returnArray(std::abs(last.GetY() - first.GetY()));

            int signY = getSign(last.GetY() - first.GetY());

            for (int i = 1; i <= std::abs(last.GetY() - first.GetY()); i++) {
                returnArray.push_back(board[first.GetX()][first.GetY() + (i * signY)]);
            }
            return returnArray;
        }
    }

    void GameBoard::PrintBoard() {
        for (auto & line : board) {
            for (BoardTile &tile : line) {
                if(tile.IsSelected())
                    std::cout << tile.GenerateSelectedString();
                else
                    std::cout << tile.GenerateDefaultString();
            }
            std::cout << "\n";
        }

        std::cout.flush();
    }
} // ChessGame
