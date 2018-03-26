//
// Created by peter on 3/21/18.
//

#include <zconf.h>
#include "Game.h"

void Game::run() {

    //TODO create simple communication with js client
    std::cout << "[Game] Started run()." << std::endl;


    while (true) {
        //this is temporary game loop
        playersManager_->update();
        sleep(1);
        std::cout << " Inside update loop" << std::endl;
    }
}

void Game::update() {

}

Game::Game() {


    webSocketServerAsync_ = std::make_unique<WebSocketServerAsync>();
    playersManager_ = std::make_unique<PlayersManager>();

    webSocketServerAsync_->run();
    webSocketServerAsync_->registerObserver(playersManager_.get());

    this->run();
}
