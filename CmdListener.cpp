#include "CmdListener.hpp"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>

static struct termios old_tio, new_tio;

CmdListener::CmdListener() {
    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
}

CmdListener::~CmdListener() {
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
}

char CmdListener::OnKeyPress() {
    char ch = 0;
    if (read(STDIN_FILENO, &ch, 1) > 0) {
        return ch;
    }
    return 0;
}

bool CmdListener::IsKeyPressed(int key) {
    fd_set readfds;
    struct timeval tv;

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    tv.tv_sec = 0;
    tv.tv_usec = 0;

    return select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv) > 0;
}
