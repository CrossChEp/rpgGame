//
// Created by ander on 05.06.2023.
//
#include <string>
#ifndef RPGGAME_PLAYER_H
#define RPGGAME_PLAYER_H
class Player {
private:
    static void _moveRight();
    static void _moveLeft();
    static void _moveUp();
    static void _moveDown();
    static bool _check(const std::string& coordType, const std::string& operation);
public:
    static int posX;
    static int posY;
    static void control();
};
#endif //RPGGAME_PLAYER_H
