//
// Created by ander on 05.06.2023.
//
#include <iostream>
#include "Field.h"
#include "../constants/Constants.h"
#include "../player/Player.h"

void draw() {
    system("cls");
    for(int y = 0; y < FIELD_Y; y++) {
        for(int x = 0; x < FIELD_X; x++) {
            if((y == 0 || x == 0) || (y == FIELD_Y - 1 || x == FIELD_X - 1)) {
                std::cout<<"#";
            }
            else if(x == Player::posX && y == Player::posY) {
                std::cout<<"*";
            }
            else {
                std::cout<<" ";
            }
        }
        std::cout<<std::endl;
    }
    std::cout<<"X: "<<Player::posX<<" "<<"Y: "<<Player::posY;
}