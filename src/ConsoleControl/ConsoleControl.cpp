#include "ConsoleControl.h"
#include <iostream>

#ifdef _WIN32
#include <Windows.h>

void ConsoleControl::SetVirtualTerminalProcessing(bool enabled) {
    DWORD dwMode = 0;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleMode(hConsole, &dwMode);
    if(enabled)
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    else
        dwMode &= ~ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hConsole, dwMode);
}
#endif

void ConsoleControl::SetCursorVisibility(bool visible) {
    if(visible)
        std::cout << "\33[?25h";
    else
        std::cout << "\33[?25l";
    std::cout.flush();
}

void ConsoleControl::ResetConsole() {
    std::cout << "\33c" << std::flush;
}

void ConsoleControl::SetCursorPosition(int x, int y) {
    std::cout << "\33[" << y << ";" << x << "H"<< std::flush;
}

void ConsoleControl::CursorUp() {
    std::cout << "\33[1A" << std::flush;
}

void ConsoleControl::CursorDown() {
    std::cout << "\33[1B" << std::flush;
}

void ConsoleControl::CursorRight() {
    std::cout << "\33[1C" << std::flush;
}

void ConsoleControl::CursorLeft() {
    std::cout << "\33[1D" << std::flush;
}

void ConsoleControl::SetCursorControls(){
    SetCursorPosition(1, 13);
}

void ConsoleControl::SetCursorTurnInformation(){
    SetCursorPosition(1, 9);
}

void ConsoleControl::SetCursorInformation(){
    SetCursorPosition(1, 11);
}

void ConsoleControl::EraseLineAfter() {
    std::cout << "\33[K" << std::flush;
}
