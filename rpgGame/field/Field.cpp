//
// Created by ander on 05.06.2023.
//
#include <iostream>
#include "Field.h"
#include "../constants/Constants.h"
#include "../player/Player.h"
#include "../gun/Gun.h"

void draw() {
#if defined _WIN32 || defined WIN64
    system("cls");
#else
    system("clear");
#endif
    for(int y = 0; y < FIELD_Y; y++) {
        for(int x = 0; x < FIELD_X; x++) {
            if((y == 0 || x == 0) || (y == FIELD_Y - 1 || x == FIELD_X - 1)) {
                std::cout<<"#";
            }
            else if(x == Player::posX && y == Player::posY) {
                std::cout<<"*";
            }
            else if(x == Gun::bulPosX && y == Gun::bulPosY) {
                std::cout<<"x";
            }
            else {
                std::cout<<" ";
            }
        }
        std::cout<<std::endl;
    }
    std::cout<<"X: "<<Player::posX<<" "<<"Y: "<<Player::posY<<std::endl;
    std::cout<<"bul_X: "<<Gun::bulPosX<<" "<<"bul_Y: "<<Gun::bulPosY<<std::endl;
}