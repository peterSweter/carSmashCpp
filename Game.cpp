//
// Created by peter on 3/21/18.
//

#include <zconf.h>
#include "Game.h"

std::stringstream Game::threadOut;
std::mutex Game::mutex_;

void Game::run() {

    //TODO create simple communication with js client
    std::cout << "[Game] Started run()." << std::endl;


    while (true) {
        //this is temporary game loop
        playersManager_->update();
        sleep(1);
        std::cout << Game::threadOut.str();
        Game::threadOut.str("");


    }
}

void Game::update() {

}

Game::Game() {


    webSocketServerAsync_ = std::make_unique<WebSocketServerAsync>();
    playersManager_ = std::make_unique<PlayersManager>();

    webSocketServerAsync_->registerObserver(playersManager_.get());
    webSocketServerAsync_->run();

    this->run();
}
