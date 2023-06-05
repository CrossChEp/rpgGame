//
// Created by ander on 05.06.2023.
//
#include "Player.h"
#include "../constants/Constants.h"
#include <conio.h>
#include <cstdlib>

int Player::posX = 0;
int Player::posY = 0;

void Player::control() {
    if(_kbhit()) {
        switch (_getch()) {
            case 'w':
                posY++;
                break;
            case 'a':
                posX--;
                break;
            case 's':
                posY--;
                break;
            case 'd':
                posX++;
                break;
        }
    }
}

void Player::_moveRight() {
    if(!_check(true)) {
        return;
    }
    posX++;
}

void Player::_moveLeft() {
    if(!_check(true)) {
        return;
    }
    posX--;
}

void Player::_moveUp() {
    if(!_check(false)) {
        return;
    }
    posY++;
}

void Player::_moveDown() {
    if(!_check(false)) {
        return;
    }
    posY--;
}

bool Player::_check(bool isX) {
    if((isX && posX >= FIELD_X) || (isX && posX <= -FIELD_X)) {
        return false;
    }
    if((isX && posY >= FIELD_Y) || (isX && posY <= -FIELD_Y)) {
        return false;
    }
    return true;
}
