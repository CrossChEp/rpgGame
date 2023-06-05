//
// Created by ander on 05.06.2023.
//
#include "Gun.h"
#include "../player/Player.h"
#include "../constants/Constants.h"

#define X "x"
#define Y "y"
#define PLUS "+"
#define MINUS "-"
#define BUL_X 1
#define BUL_Y 2
#define BUL_PLUS 1
#define BUL_MINUS 2

int Gun::bulPosX = BULLET_START_POS_X;
int Gun::bulPosY = BULLET_START_POS_Y;
bool Gun::isActive = false;
int Gun::coordType = 0;
int Gun::operation = 1;


void Gun::gunAnimation() {
    if(isActive) {
        if(bulPosX == BULLET_START_POS_X || bulPosY == BULLET_START_POS_Y) {
            bulPosX = Player::posX;
            bulPosY = Player::posY;
        }
        _shoot(coordType, operation);
    }
}

void Gun::_shoot(int type, int op) {
    if(type == BUL_X && op == BUL_PLUS) {
        _shootRight();
    }
    if(type == BUL_X && op == BUL_MINUS) {
        _shootLeft();
    }
    if(type == BUL_Y && op == BUL_PLUS) {
        _shootDown();
    }
    if(type == BUL_Y && op == BUL_MINUS) {
        _shootUp();
    }
}

void Gun::_shootRight() {
    if(!_checkBullet(X, PLUS)) {
        bulPosX = BULLET_START_POS_X;
        bulPosY = BULLET_START_POS_Y;
        isActive = false;
    }
    bulPosX++;
}

void Gun::_shootLeft() {
    if(!_checkBullet(X, MINUS)) {
        bulPosX = BULLET_START_POS_X;
        bulPosY = BULLET_START_POS_Y;
        isActive = false;
    }
    bulPosX--;
}

void Gun::_shootUp() {
    if(!_checkBullet(Y, MINUS)) {
        bulPosX = BULLET_START_POS_X;
        bulPosY = BULLET_START_POS_Y;
        isActive = false;
    }
    bulPosY--;
}

void Gun::_shootDown() {
    if(!_checkBullet(Y, PLUS)) {
        bulPosX = BULLET_START_POS_X;
        bulPosY = BULLET_START_POS_Y;
        isActive = false;
    }
    bulPosY++;
}

bool Gun::_checkBullet(const std::string &type, const std::string &op) {
    if(type == Y && op == PLUS) {
        if(bulPosY == FIELD_Y - 2) {
            return false;
        }
    }
    if(type == Y && op == MINUS) {
        if(bulPosY == 1) {
            return false;
        }
    }
    if(type == X && op == PLUS) {
        if(bulPosX == FIELD_X - 3) {
            return false;
        }
    }
    if(type == X && op == MINUS) {
        if(bulPosX == 2) {
            return false;
        }
    }
    return true;
}

