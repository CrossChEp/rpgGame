//
// Created by ander on 05.06.2023.
//
#include "../field/Field.h"
#include "../player/Player.h"
#include <thread>
#include <chrono>

void mainLoop() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        draw();
        Player::control();
    }
}