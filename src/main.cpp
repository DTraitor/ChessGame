#include <iostream>
//No linux support YET
#include <windows.h>
#include "GameBoard.h"


enum Keys{
    Up = 72,
    Left = 75,
    Right = 77,
    Down = 80
};

void setCursorVisibility(HANDLE &console, bool visibility){
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(console, &cursorInfo);
    cursorInfo.bVisible = visibility;
    SetConsoleCursorInfo(console, &cursorInfo);
}

int main() {
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    setCursorVisibility(hConsole, false);
    SetConsoleTitle("The Chess Game");

    GameBoard board;
    board.PrintBoard(hConsole);

    int selectedX = 0;
    int selectedY = 0;

    setCursorVisibility(hConsole, true);
    SetConsoleTextAttribute(hConsole,15);
    return 0;
}
