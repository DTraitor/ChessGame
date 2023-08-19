#include "../../Board/GameBoard.h"
#include "King.h"

namespace ChessGame {
    bool King::CanMove(BoardTile &previousTile, BoardTile &newTile) {
        if (!ChessPiece::CanMove(previousTile, newTile))
            return false;

        if (std::abs(previousTile.GetX() - newTile.GetX()) > 1 || std::abs(previousTile.GetY() - newTile.GetY()) > 1)
            return false;

        if(IsMate(previousTile))
            return false;

        return true;
    }

    bool King::IsMate(BoardTile &toCheck) {
        //Cardinal check
        if(toCheck.GetX() > 1){
            if(checkArrayForMate(
                    board.GetCardinalLine(toCheck, board.GetTileAt(1, toCheck.GetY())),
                    toCheck,
                    board,
                    IsBlack()
            ))
                return true;
        }

        if(toCheck.GetX() < GameBoard::BoardSize){
            if(checkArrayForMate(
                    board.GetCardinalLine(toCheck, board.GetTileAt(GameBoard::BoardSize, toCheck.GetY())),
                    toCheck,
                    board,
                    IsBlack()
            ))
                return true;
        }

        if(toCheck.GetY() > 1){
            if(checkArrayForMate(
                    board.GetCardinalLine(toCheck, board.GetTileAt(toCheck.GetX(), 1)),
                    toCheck,
                    board,
                    IsBlack()
            ))
                return true;

            //northwest
            if(toCheck.GetX() > 1){
                int smallestDelta = std::min(toCheck.GetX() - 1, toCheck.GetY() - 1);
                if(checkArrayForMate(
                        board.GetCardinalLine(
                                toCheck,
                                board.GetTileAt(toCheck.GetX() - smallestDelta, toCheck.GetY() - smallestDelta)
                                ),
                        toCheck,
                        board,
                        IsBlack()
                ))
                    return true;
            }

            //northeast
            if(toCheck.GetX() < GameBoard::BoardSize){
                int smallestDelta = std::min(GameBoard::BoardSize - toCheck.GetX(), toCheck.GetY() - 1);
                if(checkArrayForMate(
                        board.GetCardinalLine(
                                toCheck,
                            board.GetTileAt(toCheck.GetX() + smallestDelta, toCheck.GetY() - smallestDelta)
                        ),
                        toCheck,
                        board,
                        IsBlack()
                ))
                    return true;
            }
        }

        //Diagonal check

        if(toCheck.GetY() < GameBoard::BoardSize){
            if(checkArrayForMate(
                    board.GetDiagonalLine(toCheck, board.GetTileAt(toCheck.GetX(), GameBoard::BoardSize)),
                    toCheck,
                    board,
                    IsBlack()
            ))
                return true;

            //southwest
            if(toCheck.GetX() > 1){
                int smallestDelta = std::min(toCheck.GetX() - 1, GameBoard::BoardSize - toCheck.GetY());
                if(checkArrayForMate(
                        board.GetDiagonalLine(
                                toCheck,
                                board.GetTileAt(toCheck.GetX() - smallestDelta, toCheck.GetY() + smallestDelta)
                        ),
                        toCheck,
                        board,
                        IsBlack()
                ))
                    return true;
            }

            //southeast
            if(toCheck.GetX() < GameBoard::BoardSize){
                int smallestDelta = std::min(GameBoard::BoardSize - toCheck.GetX(), GameBoard::BoardSize - toCheck.GetY());
                if(checkArrayForMate(
                        board.GetDiagonalLine(
                                toCheck,
                                board.GetTileAt(toCheck.GetX() + smallestDelta, toCheck.GetY() + smallestDelta)
                                ),
                            toCheck,
                            board,
                            IsBlack()
                            ))
                    return true;
            }
        }

        //Check for knights

        if(toCheck.GetX() > 1 && toCheck.GetY() > 1){
            if(toCheck.GetX() > 2){
                BoardTile &tile = board.GetTileAt(toCheck.GetX() - 2, toCheck.GetY() - 1);
                if(tile.HasPiece() && tile.GetPiece()->CanMove(tile, toCheck))
                    return true;
            }
            if(toCheck.GetY() > 2){
                BoardTile &tile = board.GetTileAt(toCheck.GetX() - 1, toCheck.GetY() - 2);
                if(tile.HasPiece() && tile.GetPiece()->CanMove(tile, toCheck))
                    return true;
            }
        }
        if(toCheck.GetX() > 1 && toCheck.GetY() < GameBoard::BoardSize){
            if(toCheck.GetX() > 2){
                BoardTile &tile = board.GetTileAt(toCheck.GetX() - 2, toCheck.GetY() + 1);
                if(tile.HasPiece() && tile.GetPiece()->CanMove(tile, toCheck))
                    return true;
            }
            if(toCheck.GetY() < GameBoard::BoardSize - 1){
                BoardTile &tile = board.GetTileAt(toCheck.GetX() - 1, toCheck.GetY() + 2);
                if(tile.HasPiece() && tile.GetPiece()->CanMove(tile, toCheck))
                    return true;
            }
        }
        if(toCheck.GetX() < GameBoard::BoardSize && toCheck.GetY() > 1){
            if(toCheck.GetX() < GameBoard::BoardSize - 1){
                BoardTile &tile = board.GetTileAt(toCheck.GetX() + 2, toCheck.GetY() - 1);
                if(tile.HasPiece() && tile.GetPiece()->CanMove(tile, toCheck))
                    return true;
            }
            if(toCheck.GetY() > 2){
                BoardTile &tile = board.GetTileAt(toCheck.GetX() + 1, toCheck.GetY() - 2);
                if(tile.HasPiece() && tile.GetPiece()->CanMove(tile, toCheck))
                    return true;
            }
        }
        if(toCheck.GetX() < GameBoard::BoardSize && toCheck.GetY() < GameBoard::BoardSize){
            if(toCheck.GetX() < GameBoard::BoardSize - 1){
                BoardTile &tile = board.GetTileAt(toCheck.GetX() + 2, toCheck.GetY() + 1);
                if(tile.HasPiece() && tile.GetPiece()->CanMove(tile, toCheck))
                    return true;
            }
            if(toCheck.GetY() < GameBoard::BoardSize - 1){
                BoardTile &tile = board.GetTileAt(toCheck.GetX() + 1, toCheck.GetY() + 2);
                if(tile.HasPiece() && tile.GetPiece()->CanMove(tile, toCheck))
                    return true;
            }
        }

        return false;
    }

    bool King::IsCheckmate(BoardTile &toCheck){
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                BoardTile &tile = board.GetTileAt(toCheck.GetX() - i, toCheck.GetY() - j);
                if(tile.HasPiece() && (tile.GetPiece()->IsBlack() == IsBlack()))
                    continue;
                if(!IsMate(tile))
                    return false;
            }
        }

        return true;
    }
} // ChessGame
