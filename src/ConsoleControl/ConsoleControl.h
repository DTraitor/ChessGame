#ifndef CHESSGAME_CONSOLECONTROL_H
#define CHESSGAME_CONSOLECONTROL_H


#include <string>

namespace ConsoleControl {
    enum class KeyCodes{
        CTRL_C = 3,
        ENTER = 13,
        ESC = 27,
        UP = 72,
        LEFT = 75,
        RIGHT = 77,
        DOWN = 80,
        SMALL_X = 'x',
        SMALL_R = 'r'
    };

    enum class TextAttributes{
        NONE,
        HIGH_INTENSITY = 1,
        UNDERLINE = 4,
        BLINK = 5,
        REVERSE = 7,
        INVISIBLE = 8
    };

    enum class TextColors{
        NONE,
        BLACK = 30,
        RED = 31,
        GREEN = 32,
        YELLOW = 33,
        BLUE = 34,
        MAGENTA = 35,
        CYAN = 36,
        WHITE = 37
    };

    enum class BackgroundColors{
        NONE,
        BLACK = 40,
        RED = 41,
        GREEN = 42,
        YELLOW = 43,
        BLUE = 44,
        MAGENTA = 45,
        CYAN = 46,
        WHITE = 47
    };

#ifdef _WIN32
    void SetVirtualTerminalProcessing(bool enabled);
#endif

    void SetCursorVisibility(bool visible);
    void ResetConsole();
    void SetCursorPosition(int x, int y);
    void CursorUp();
    void CursorDown();
    void CursorRight();
    void CursorLeft();
    void SetCursorControls();
    void SetCursorTurnInformation();
    void SetCursorInformation();
    void EraseLineAfter();

    struct TextFormat{
        template <typename toFormat>
        std::string FormatString(const toFormat &input) const{
            std::string result;
            if(attribute != TextAttributes::NONE)
                result += ("\33[" + std::to_string(static_cast<int>(attribute)) + 'm');
            if(textColor != TextColors::NONE)
                result += ("\33[" + std::to_string(static_cast<int>(textColor)) + 'm');
            if(backgroundColor != BackgroundColors::NONE)
                result += ("\33[" + std::to_string(static_cast<int>(backgroundColor)) + 'm');
            result += input;
            result += "\33[0m";
            return result;
        }

        TextAttributes attribute = TextAttributes::NONE;
        TextColors textColor = TextColors::NONE;
        BackgroundColors backgroundColor = BackgroundColors::NONE;
    };
};


#endif //CHESSGAME_CONSOLECONTROL_H
