#include <iostream>
#include <conio.h>
#include "ChessGame/Board/GameBoard.h"
#include "ConsoleControl/ConsoleControl.h"

int32_t hoverX = 1;
int32_t hoverY = 1;
const static std::string rowLetters = "abcdefgh";
//Whose turn white or black
bool blackTurn = false;
// NOTE: Pointer to an object on stack
// Pointer to selected tile
ChessGame::BoardTile *selected = nullptr;

void PrintControls();
void PrintInformation(const std::string& info);
void UpdateTurnInformation();
void UpdateTileRender(ChessGame::BoardTile &tile);
void ChangeHover(int8_t deltaX, int8_t deltaY);

int main() {
#ifdef _WIN32
    ConsoleControl::SetVirtualTerminalProcessing(true);
#endif
    ConsoleControl::ResetConsole();
    ConsoleControl::SetCursorVisibility(false);

    ChessGame::board.PrintBoard();

    PrintControls();
    UpdateTurnInformation();

    //To render ou
    UpdateTileRender(ChessGame::board.GetTileAt(1, 1));

    bool runTheGame = true;

    while (runTheGame){
        switch (_getch()) {
            //Who the hell though it was a good idea to intercept Ctrl+C...
            case static_cast<int>(ConsoleControl::KeyCodes::CTRL_C):
            case static_cast<int>(ConsoleControl::KeyCodes::SMALL_X):
                runTheGame = false;
                break;
            case static_cast<int>(ConsoleControl::KeyCodes::UP):
                ChangeHover(0, -1);
                break;
            case static_cast<int>(ConsoleControl::KeyCodes::DOWN):
                ChangeHover(0, 1);
                break;
            case static_cast<int>(ConsoleControl::KeyCodes::RIGHT):
                ChangeHover(1, 0);
                break;
            case static_cast<int>(ConsoleControl::KeyCodes::LEFT):
                ChangeHover(-1, 0);
                break;
            case static_cast<int>(ConsoleControl::KeyCodes::ENTER):
                if(selected == nullptr){
                    selected = &ChessGame::board.GetTileAt(hoverX, hoverY);
                    if(selected->HasPiece())
                        if(selected->GetPiece()->IsBlack() == blackTurn){
                            selected->SetSelected(true);
                            PrintInformation("Chess piece selected.");
                            break;
                        } else{
                            selected = nullptr;
                            PrintInformation("Cannot select a tile with a chess piece of a different colour!");
                            break;
                        }
                    else{
                        selected = nullptr;
                        PrintInformation("Cannot select a tile without a chess piece!");
                        break;
                    }
                } else{
                    if(selected == &ChessGame::board.GetTileAt(hoverX, hoverY)){
                        selected->SetSelected(false);
                        selected = nullptr;
                        PrintInformation("Chess piece was de-selected.");
                        break;
                    } else{
                        ChessGame::BoardTile &newSelection = ChessGame::board.GetTileAt(hoverX, hoverY);
                        if(selected->GetPiece()->Move(newSelection)){
                            std::string message = "Moved piece from ";
                            message += rowLetters[selected->GetX()];
                            message += std::to_string(selected->GetY());
                            message += " to ";
                            message += rowLetters[newSelection.GetX()];
                            message += std::to_string(newSelection.GetY());
                            message += ".";
                            PrintInformation(message);

                            blackTurn = !blackTurn;
                            UpdateTurnInformation();
                        } else{
                            PrintInformation("Cannot move chess piece here!");
                        }
                    }
                }

                break;
            case static_cast<int>(ConsoleControl::KeyCodes::ESC):
                if(selected == nullptr)
                    break;
                selected->SetSelected(false);
                UpdateTileRender(*selected);
                selected = nullptr;
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

void PrintControls(){
    ConsoleControl::SetCursorControls();
    std::cout << "[ X ] - Exit | [ ENTER ] - Choose Tile\n";
    std::cout << "[ UP ] - Move Up | [ DOWN ] - Move Down\n";
    std::cout << "[ LEFT ] - Move Left | [ RIGHT ] - Move Right";
}

void PrintInformation(const std::string& info){
    ConsoleControl::SetCursorInformation();
    std::cout << info;
    ConsoleControl::EraseLineAfter();
}

void UpdateTurnInformation(){
    ConsoleControl::SetCursorTurnInformation();
    if(blackTurn)
        std::cout << "Black turn";
    else
        std::cout << "White turn";
}

void UpdateTileRender(ChessGame::BoardTile &tile){
    ConsoleControl::SetCursorPosition(tile.GetX(), tile.GetY());
    if(tile.GetX() == hoverX && tile.GetY() == hoverY)
        std::cout << tile.GenerateHoverString();
    else if(tile.IsSelected())
        std::cout << tile.GenerateSelectedString();
    else
        std::cout << tile.GenerateDefaultString();
}

void ChangeHover(int8_t deltaX, int8_t deltaY){
    if((hoverX + deltaX) < 1 || (hoverX + deltaX) > ChessGame::GameBoard::BoardSize)
        return;
    if((hoverY + deltaY) < 1 || (hoverY + deltaY) > ChessGame::GameBoard::BoardSize)
        return;

    ChessGame::BoardTile &previousTile = ChessGame::board.GetTileAt(hoverX, hoverY);
    ConsoleControl::SetCursorPosition(hoverX, hoverY);
    if(previousTile.IsSelected()){
        std::cout << previousTile.GenerateSelectedString();
    } else{
        std::cout << previousTile.GenerateDefaultString();
    }


    hoverX += deltaX;
    hoverY += deltaY;

    ChessGame::BoardTile &newTile = ChessGame::board.GetTileAt(hoverX, hoverY);
    ConsoleControl::SetCursorPosition(hoverX, hoverY);
    std::cout << newTile.GenerateHoverString();
}
