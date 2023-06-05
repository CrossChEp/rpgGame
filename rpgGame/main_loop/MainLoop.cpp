//
// Created by ander on 05.06.2023.
//
#include "../field/Field.h"
#include "../player/Player.h"
#include "../gun/Gun.h"
#include <thread>
#include <chrono>

void mainLoop() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        draw();
        Player::control();
        Gun::gunAnimation();
    }
}