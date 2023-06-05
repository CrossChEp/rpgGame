//
// Created by Oleg Andy on 05.06.2023.
//
#if defined(__APPLE__) || defined(__linux__) || defined(unix) || defined(__unix__) || defined(__unix)
#include <sys/ioctl.h>
#include <termios.h>

#ifndef RPGGAME_SUPPORT_H
#define RPGGAME_SUPPORT_H
bool kbhit();
int getch(void);
#endif //RPGGAME_SUPPORT_H
#endif
