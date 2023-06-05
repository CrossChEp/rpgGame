//
// Created by ander on 05.06.2023.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H
class Player {
private:
    static void _moveRight();
    static void _moveLeft();
    static void _moveUp();
    static void _moveDown();
    static bool _check(bool isX);
public:
    static int posX;
    static int posY;
    static void control();
};

#endif //GAME_PLAYER_H
