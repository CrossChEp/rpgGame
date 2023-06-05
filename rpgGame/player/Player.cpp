//
// Created by ander on 05.06.2023.
//
#include "Player.h"
#include "../constants/Constants.h"
#include "../field/Field.h"
#include "../gun/Gun.h"
#if defined _WIN32 || defined WIN64
#include <conio.h>
#else
#include "../support_functions/Support.h"
#endif
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <iostream>

#define X "x"
#define Y "y"
#define PLUS "+"
#define MINUS "-"
#define BUL_X 1
#define BUL_Y 2
#define BUL_PLUS 1
#define BUL_MINUS 2

int Player::posX = FIELD_X  / 2;
int Player::posY = FIELD_Y / 2;

void Player::control() {
#if defined _WIN32 || defined WIN64
    if(_kbhit()) {
        switch (_getch()) {
            case 'w':
                _moveUp();
                break;
            case 'a':
                _moveLeft();
                break;
            case 's':
                _moveDown();
                break;
            case 'd':
                _moveRight();
                break;
            case 'q':
                system("pause");
                break;
            case 77:
                _shootRight();
                break;
            case 75:
                _shootLeft();
                break;
            case 72:
                _shootUp();
                break;
            case 80:
                _shootDown();
                break;
        }
    }
#else
    if(kbhit()) {
        switch (getch()) {
            case 'w':
                _moveUp();
                break;
            case 'a':
                _moveLeft();
                break;
            case 's':
                _moveDown();
                break;
            case 'd':
                _moveRight();
                break;
            case 'q':
                system("pause");
                break;
            case 67:
                _shootRight();
                break;
            case 68:
                _shootLeft();
                break;
            case 65:
                _shootUp();
                break;
            case 66:
                _shootDown();
                break;
        }
    }
#endif
}


void Player::_moveRight() {
    if(!_check(X, PLUS)) {
        posX = posX;
    } else {
        posX++;
    }
}

void Player::_moveLeft() {
    if(!_check(X, MINUS)) {
        posX = posX;
    } else {
        posX--;
    }
}

void Player::_moveUp() {
    if(!_check(Y, MINUS)) {
        posY = posY;
    } else {
        posY--;
    }
}

void Player::_moveDown() {
    if (!_check(Y, PLUS)) {
        posY = posY;
    } else {
        posY++;
    }
}

bool Player::_check(const std::string &coordType, const std::string &operation) {
    if(coordType == Y && operation == PLUS) {
        if(posY == FIELD_Y - 2) {
            return false;
        }
    }
    if(coordType == Y && operation == MINUS) {
        if(posY == 1) {
            return false;
        }
    }
    if(coordType == X && operation == PLUS) {
        if(posX == FIELD_X - 3) {
            return false;
        }
    }
    if(coordType == X && operation == MINUS) {
        if(posX == 2) {
            return false;
        }
    }
    return true;
}

void Player::_shootRight() {
    Gun::isActive = true;
    Gun::coordType = BUL_X;
    Gun::operation = BUL_PLUS;
}

void Player::_shootLeft() {
    Gun::isActive = true;
    Gun::coordType = BUL_X;
    Gun::operation = BUL_MINUS;
}

void Player::_shootUp() {
    Gun::isActive = true;
    Gun::coordType = BUL_Y;
    Gun::operation = BUL_MINUS;
}

void Player::_shootDown() {
    Gun::isActive = true;
    Gun::coordType = BUL_Y;
    Gun::operation = BUL_PLUS;
}

