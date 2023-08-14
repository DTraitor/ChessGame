#include <iostream>
#include <conio.h>
#include "ChessGame/Board/GameBoard.h"
#include "ConsoleControl/ConsoleControl.h"

int main() {
#ifdef _WIN32
    ConsoleControl::SetVirtualTerminalProcessing(true);
#endif
    ConsoleControl::ResetConsole();
    ConsoleControl::SetCursorVisibility(false);

    ChessGame::GameBoard board;
    board.PrintBoard();

    int selectedX = 1;
    int selectedY = 1;

    ConsoleControl::SetCursorPosition(1, 1);
    std::cout << board.GetTileAt(0, 0).GeneratedSelectedString();
    ConsoleControl::CursorLeft();

    bool runTheGame = true;
    while (runTheGame){
        switch (_getch()) {
            //Who the hell though it was a good idea to intercept Ctrl+C...
            case static_cast<unsigned char>(ConsoleControl::KeyCodes::CTRL_C):
                exit(0);
            case static_cast<unsigned char>(ConsoleControl::KeyCodes::UP):
                if(selectedY <= 1)
                    break;
                std::cout << board.GetTileAt(selectedX - 1, selectedY - 1).GenerateDefaultString();
                --selectedY;
                ConsoleControl::SetCursorPosition(selectedX, selectedY);
                std::cout << board.GetTileAt(selectedX - 1, selectedY - 1).GeneratedSelectedString();
                ConsoleControl::CursorLeft();
                break;
            case static_cast<unsigned char>(ConsoleControl::KeyCodes::DOWN):
                if(selectedY >= ChessGame::GameBoard::BoardSize)
                    break;
                std::cout << board.GetTileAt(selectedX - 1, selectedY - 1).GenerateDefaultString();
                ++selectedY;
                ConsoleControl::SetCursorPosition(selectedX, selectedY);
                std::cout << board.GetTileAt(selectedX - 1, selectedY - 1).GeneratedSelectedString();
                ConsoleControl::CursorLeft();
                break;
            case static_cast<unsigned char>(ConsoleControl::KeyCodes::RIGHT):
                if(selectedX >= ChessGame::GameBoard::BoardSize)
                    break;
                std::cout << board.GetTileAt(selectedX - 1, selectedY - 1).GenerateDefaultString();
                //We don't move here because printing moves the cursor
                ++selectedX;
                std::cout << board.GetTileAt(selectedX - 1, selectedY - 1).GeneratedSelectedString();
                ConsoleControl::CursorLeft();
                break;
            case static_cast<unsigned char>(ConsoleControl::KeyCodes::LEFT):
                if(selectedX <= 1)
                    break;
                std::cout << board.GetTileAt(selectedX - 1, selectedY - 1).GenerateDefaultString();
                --selectedX;
                ConsoleControl::SetCursorPosition(selectedX, selectedY);
                std::cout << board.GetTileAt(selectedX - 1, selectedY - 1).GeneratedSelectedString();
                ConsoleControl::CursorLeft();
                break;
            case static_cast<unsigned char>(ConsoleControl::KeyCodes::SMALL_X):
                runTheGame = false;
                break;
        }
    }

    ConsoleControl::SetCursorVisibility(true);
    ConsoleControl::ResetConsole();
#ifdef _WIN32
    ConsoleControl::SetVirtualTerminalProcessing(false);
#endif
    return 0;
}
