#include <iostream>
#include <conio.h>
#include "ChessGame/Board/GameBoard.h"
#include "ChessGame/GameStatus.h"
#include "ConsoleControl/ConsoleControl.h"

using ChessGame::GameStatus;

ChessGame::GameBoard board;
int32_t hoverX = 1;
int32_t hoverY = 1;
const static std::string rowLetters = "abcdefgh";
//Whose turn white or black
bool blackTurn = false;
// NOTE: Pointer to an object on stack
// Pointer to selected tile
ChessGame::BoardTile *selected = nullptr;
GameStatus gameStatus = GameStatus::ONGOING;

void PrintControls();
void PrintInformation(const std::string& info);
void UpdateTurnInformation();
void UpdateTileRender(ChessGame::BoardTile &tile);
void ChangeHover(int8_t deltaX, int8_t deltaY);
std::string OnTileSelectAttempt();


int main() {
#ifdef _WIN32
    ConsoleControl::SetVirtualTerminalProcessing(true);
#endif
    ConsoleControl::ResetConsole();
    ConsoleControl::SetCursorVisibility(false);

    board.PrintBoard();
    PrintControls();
    UpdateTurnInformation();

    //To render default hovering
    UpdateTileRender(board.GetTileAt(1, 1));

    while (gameStatus == GameStatus::ONGOING){
        switch (_getch()) {
            //Who the hell though it was a good idea to intercept Ctrl+C...
            case static_cast<int>(ConsoleControl::KeyCodes::CTRL_C):
            case static_cast<int>(ConsoleControl::KeyCodes::SMALL_X):
                gameStatus = GameStatus::DRAW;
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
                PrintInformation(OnTileSelectAttempt());
                break;
            case static_cast<int>(ConsoleControl::KeyCodes::ESC):
                if(selected == nullptr)
                    break;
                selected->SetSelected(false);
                UpdateTileRender(*selected);
                selected = nullptr;
                break;
            case static_cast<int>(ConsoleControl::KeyCodes::SMALL_R):
                board.ResetBoard();

                blackTurn = false;
                UpdateTurnInformation();

                ConsoleControl::SetCursorPosition(1, 1);
                board.PrintBoard();

                hoverX = 1;
                hoverY = 1;
                UpdateTileRender(board.GetTileAt(1, 1));

                PrintInformation("The game was successfully restarted!");
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
    std::cout << "[ X ] - Exit | [ R ] - Restart The Game\n";
    std::cout << "[ ENTER ] - Select Tile | [ ESC ] - De-select Tile\n";
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

    ChessGame::BoardTile &previousTile = board.GetTileAt(hoverX, hoverY);
    ConsoleControl::SetCursorPosition(hoverX, hoverY);
    if(previousTile.IsSelected()){
        std::cout << previousTile.GenerateSelectedString();
    } else{
        std::cout << previousTile.GenerateDefaultString();
    }

    hoverX += deltaX;
    hoverY += deltaY;

    ChessGame::BoardTile &newTile = board.GetTileAt(hoverX, hoverY);
    ConsoleControl::SetCursorPosition(hoverX, hoverY);
    std::cout << newTile.GenerateHoverString();
}

std::string OnTileSelectAttempt(){
    //If none selected
    if(selected == nullptr){
        if(!board.GetTileAt(hoverX, hoverY).HasPiece())
            return "Cannot select a tile without a chess piece!";
        if(board.GetTileAt(hoverX, hoverY).GetPiece()->IsBlack() != blackTurn)
            return "Cannot select a piece of a different colour!";
        selected = &board.GetTileAt(hoverX, hoverY);
        selected->SetSelected(true);
        UpdateTileRender(*selected);
        return "Chess piece selected.";
    }

    //De-select on attempt to select same tile
    if(selected == &board.GetTileAt(hoverX, hoverY)){
        selected->SetSelected(false);
        UpdateTileRender(*selected);
        selected = nullptr;
        return "Chess piece de-selected.";
    }


    //Try to move a tile
    if(selected->GetPiece()->Move(board.GetTileAt(hoverX, hoverX))){
        if(board.GetKing(blackTurn)->IsMate()){
            selected->GetPiece()->ForceMove(*selected);
            return "Cannot move this chess piece here due to a mate to your king.";
        }

        std::string message = "Moved piece from ";
        message += rowLetters[selected->GetX()];
        message += std::to_string(selected->GetY());
        message += " to ";
        message += rowLetters[board.GetTileAt(hoverX, hoverX).GetX()];
        message += std::to_string(board.GetTileAt(hoverX, hoverX).GetY());
        message += ".";

        UpdateTileRender(board.GetTileAt(hoverX, hoverX));
        selected->SetSelected(false);
        UpdateTileRender(*selected);
        selected = nullptr;

        //We moved so it's time to change a turn
        blackTurn = !blackTurn;
        UpdateTurnInformation();

        if(board.GetKing(blackTurn)->IsCheckmate()){
            gameStatus = blackTurn ? GameStatus::WHITE_WIN : GameStatus::BLACK_WIN;
        }

        return message;
    }

    return "Cannot move a chess piece here!";
}
