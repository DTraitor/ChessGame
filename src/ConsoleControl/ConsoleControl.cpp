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
    std::cout << "\33[" << y << ";" << x << "H";
}

void ConsoleControl::CursorUp() {
    std::cout << "\33[1A";
}

void ConsoleControl::CursorDown() {
    std::cout << "\33[1B";
}

void ConsoleControl::CursorRight() {
    std::cout << "\33[1C";
}

void ConsoleControl::CursorLeft() {
    std::cout << "\33[1D";
}

