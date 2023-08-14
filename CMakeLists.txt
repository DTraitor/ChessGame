cmake_minimum_required(VERSION 3.25)
project(ChessGame)

set(CMAKE_CXX_STANDARD 23)

add_executable(ChessGame src/main.cpp src/Board/GameBoard.cpp src/Board/GameBoard.h src/Board/BoardTile.cpp src/Board/BoardTile.h src/Chess/ChessPiece.cpp src/Chess/ChessPiece.h src/Chess/ChessTypes/Pawn.cpp src/Chess/ChessTypes/Pawn.h src/Chess/ChessTypes/Rook.cpp src/Chess/ChessTypes/Rook.h src/Chess/ChessTypes/Queen.cpp src/Chess/ChessTypes/Queen.h src/Chess/ChessTypes/King.cpp src/Chess/ChessTypes/King.h src/Chess/ChessTypes/Bishop.cpp src/Chess/ChessTypes/Bishop.h src/Chess/ChessTypes/Knight.cpp src/Chess/ChessTypes/Knight.h src/Chess/ChessTypes.h src/ConsoleOuput/ConsoleControl.cpp src/ConsoleOuput/ConsoleControl.h)
