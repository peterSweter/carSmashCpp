//
// Created by peter on 3/21/18.
//

#include <zconf.h>
#include "Game.h"


//TODO create separate file for game static settings
std::stringstream Game::threadOut;
std::mutex Game::mutex_;
double Game::MS_PER_FRAME = 1000.0/60.0;


void Game::run() {

    //TODO create simple communication with js client
    std::cout << "[Game] Started run()." << std::endl;


    while (true) {
        auto start = std::chrono::system_clock::now();
        //b2dWordl.step

        //this is temporary game loop
        playersManager_->update();

        //send data


        std::cout << Game::threadOut.str();
        Game::threadOut.str("");

        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        long long  sleepDuration = (long long int) std::max<double>(0, (Game::MS_PER_FRAME - elapsed_seconds.count()) * 1000);
        usleep(sleepDuration);


    }
}

void Game::update() {

}

Game::Game() {


    box2dManager_ =  std::make_unique<Box2dManager>();

    webSocketServerAsync_ = std::make_unique<WebSocketServerAsync>();
    playersManager_ = std::make_unique<PlayersManager>();

    webSocketServerAsync_->registerObserver(playersManager_.get());
    webSocketServerAsync_->run();


    this->run();
}
