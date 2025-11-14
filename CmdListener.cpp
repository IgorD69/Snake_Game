#include "CmdListener.hpp"

#include <windef.h>
#include <windows.h>

char CmdListener::OnKeyPress() {
    for(int key = 8; key <= 190; ++key) {
        if (GetAsyncKeyState(key) & 0x0001) {
            return key;
        }
    }
    return 0; // Placeholder return value
}
bool CmdListener::IsKeyPressed(int key) {
    return GetAsyncKeyState(key) & 0x8000;
}