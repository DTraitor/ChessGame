cmake_minimum_required(VERSION 3.25)
project(ChessGame)

set(CMAKE_CXX_STANDARD 23)

add_executable(ChessGame src/main.cpp src/ChessGame/Board/GameBoard.cpp src/ChessGame/Board/GameBoard.h src/ChessGame/Board/BoardTile.cpp src/ChessGame/Board/BoardTile.h src/ChessGame/Chess/ChessPiece.cpp src/ChessGame/Chess/ChessPiece.h src/ChessGame/Chess/ChessTypes/Pawn.cpp src/ChessGame/Chess/ChessTypes/Pawn.h src/ChessGame/Chess/ChessTypes/Rook.cpp src/ChessGame/Chess/ChessTypes/Rook.h src/ChessGame/Chess/ChessTypes/Queen.cpp src/ChessGame/Chess/ChessTypes/Queen.h src/ChessGame/Chess/ChessTypes/King.cpp src/ChessGame/Chess/ChessTypes/King.h src/ChessGame/Chess/ChessTypes/Bishop.cpp src/ChessGame/Chess/ChessTypes/Bishop.h src/ChessGame/Chess/ChessTypes/Knight.cpp src/ChessGame/Chess/ChessTypes/Knight.h src/ChessGame/Chess/ChessTypes.h src/ConsoleControl/ConsoleControl.cpp src/ConsoleControl/ConsoleControl.h
        src/ChessGame/GameStatus.h)
