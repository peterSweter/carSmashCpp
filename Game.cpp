//
// Created by peter on 3/21/18.
//

#include <zconf.h>
#include "Game.h"

void Game::run() {
    while (true) {
        //this is temporary game loop
        playersManager.update();
        sleep(1);
    }
}

void Game::update() {
}
