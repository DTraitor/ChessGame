#include <iostream>
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

    std::cin.get();

    ConsoleControl::SetCursorVisibility(true);
    ConsoleControl::ResetConsole();
#ifdef _WIN32
    ConsoleControl::SetVirtualTerminalProcessing(false);
#endif
    return 0;
}
