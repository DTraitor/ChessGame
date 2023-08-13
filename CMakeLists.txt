cmake_minimum_required(VERSION 3.25)
project(ChessGame)

set(CMAKE_CXX_STANDARD 23)

add_executable(ChessGame src/main.cpp src/GameBoard.cpp src/GameBoard.h src/BoardTile.cpp src/BoardTile.h src/ChessPiece.cpp src/ChessPiece.h src/ChessTypes/Pawn.cpp src/ChessTypes/Pawn.h src/ChessTypes/Rook.cpp src/ChessTypes/Rook.h src/ChessTypes/Queen.cpp src/ChessTypes/Queen.h src/ChessTypes/King.cpp src/ChessTypes/King.h src/ChessTypes/Bishop.cpp src/ChessTypes/Bishop.h src/ChessTypes/Knight.cpp src/ChessTypes/Knight.h src/ChessTypes.h)
