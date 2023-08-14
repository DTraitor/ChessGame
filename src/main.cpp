#include <iostream>
#include "Board/GameBoard.h"
#include "ConsoleOuput/ConsoleControl.h"

int main() {
#ifdef _WIN32
    ConsoleControl::SetVirtualTerminalProcessing(true);
#endif
    ConsoleControl::ResetConsole();
    ConsoleControl::SetCursorVisibility(false);

    GameBoard board;
    board.PrintBoard();

    std::cin.get();

    ConsoleControl::SetCursorVisibility(true);
    ConsoleControl::ResetConsole();
#ifdef _WIN32
    ConsoleControl::SetVirtualTerminalProcessing(false);
#endif
    return 0;
}
