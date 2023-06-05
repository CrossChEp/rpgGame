//
// Created by ander on 05.06.2023.
//
#include "Player.h"
#include "../constants/Constants.h"
#include "../field/Field.h"
#include <conio.h>
#include <cstdlib>
#include <string>

#define X "x"
#define Y "y"
#define PLUS "+"
#define MINUS "-"

int Player::posX = FIELD_X  / 2;
int Player::posY = FIELD_Y / 2;

void Player::control() {
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
        }
    }
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
    if(!_check(Y, PLUS)) {
        posY = posY;
    } else {
        posY++;
    }
}

bool Player::_check(const std::string& coordType, const std::string& operation) {
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
