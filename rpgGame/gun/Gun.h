//
// Created by ander on 05.06.2023.
//
#include <string>

#ifndef RPGGAME_GUN_H
#define RPGGAME_GUN_H
class Gun {
private:
    static bool _checkBullet(const std::string& coordType, const std::string& operation);
    static void _shoot (int type, int op);
    static void _shootRight();
    static void _shootLeft();
    static void _shootUp();
    static void _shootDown();
public:
    static int bulPosX;
    static int bulPosY;
    static int coordType;
    static int operation;
    static bool isActive;
    static void gunAnimation();
};
#endif //RPGGAME_GUN_H
