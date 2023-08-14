#include "GameBoard.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

template <typename T>
int getSign(T val) {
    return (0 < val) - (val < 0);
}

GameBoard::GameBoard() {
    ResetBoard();
}

GameBoard::~GameBoard() {
    CleanBoard();
}

void GameBoard::CleanBoard() {
    for (auto &line : board) {
        for (BoardTile &tile : line) {
            delete(tile.getPiece());
        }
    }
}

void GameBoard::ResetBoard() {
    CleanBoard();

    //Generate black pieces
    GenerateFigures(0, true);
    for (BoardTile &tile : board[1]) {
        tile.setPiece(new Pawn(true));
    }

    //Generate white pieces
    GenerateFigures(BoardSize - 1, false);
    for (BoardTile &tile : board[BoardSize - 2]) {
        tile.setPiece(new Pawn(false));
    }
}

void GameBoard::GenerateFigures(int line, bool isBlack) {
    board[line][0].setPiece(new Rook(isBlack));
    board[line][1].setPiece(new Knight(isBlack));
    board[line][2].setPiece(new Bishop(isBlack));
    board[line][3].setPiece(new Queen(isBlack));

    if(isBlack){
        blackKing = new King(isBlack);
        board[line][4].setPiece(blackKing);
    }
    else{
        whiteKing = new King(isBlack);
        board[line][4].setPiece(whiteKing);
    }

    board[line][5].setPiece(new Bishop(isBlack));
    board[line][6].setPiece(new Knight(isBlack));
    board[line][7].setPiece(new Rook(isBlack));
}

BoardTile* GameBoard::GetDiagonalLine(const BoardTile& first, const BoardTile& last){
    if(std::abs(first.getX() - last.getX()) != std::abs(first.getY() - last.getY()))
        throw std::logic_error("Tried to get diagonal line between 2 non-diagonal tiles!");

    int signX = getSign(last.getX() - first.getX());
    int signY = getSign(last.getY() - first.getY());

    BoardTile* returnArray = new BoardTile[std::abs(last.getX() - first.getX())];

    for (int i = 1; i <= std::abs(last.getX() - first.getX()); i++) {
        returnArray[i - 1] = board[first.getX() + (i * signX)][first.getY() + (i * signY)];
    }

    return returnArray;
}

BoardTile* GameBoard::GetCardinalLine(const BoardTile& first, const BoardTile& last){
    if((first.getX() != last.getX()) && (first.getY() != last.getY()))
        throw std::logic_error("Tried to get cardinal line between 2 diagonal tiles!");

    BoardTile* returnArray;
    if(last.getX() - first.getX()){
        returnArray = new BoardTile[std::abs(last.getX() - first.getX())];

        int signX = getSign(last.getX() - first.getX());

        for (int i = 1; i <= std::abs(last.getX() - first.getX()); i++) {
            returnArray[i] = board[first.getX() + (i * signX)][first.getY()];
        }
    }
    else{
        returnArray = new BoardTile[std::abs(last.getY() - first.getY())];

        int signY = getSign(last.getY() - first.getY());

        for (int i = 1; i <= std::abs(last.getY() - first.getY()); i++) {
            returnArray[i] = board[first.getX()][first.getY() + (i * signY)];
        }
    }

    return returnArray;
}

void GameBoard::PrintBoard() {
    ConsoleControl::TextFormat format{ConsoleControl::TextAttributes::NONE};

    for(int i = 0; i < BoardSize; i++)
    {
        for(int j = 0; j < BoardSize; j++){
            format.backgroundColor = ((i + j) & 1) ? oddBackground : evenBackground;
            if(board[i][j].hasPiece())
                format.textColor = board[i][j].getPiece()->IsBlack() ? blackColor : whiteColor;

            std::cout << format.FormatString(board[i][j].hasPiece() ? board[i][j].getPiece()->GetIcon() : ' ');
        }
        std::cout << "\n";
    }

    std::cout.flush();
}
