//
// Created by peter on 3/21/18.
//

#ifndef CARSMASHCPP_GAME_H
#define CARSMASHCPP_GAME_H


#include "PlayersManager.h"
#include "networking/WebSocketServerAsync.h"

class Game {
private:
    std::unique_ptr<PlayersManager> playersManager_;
    std::unique_ptr<WebSocketServerAsync> webSocketServerAsync_;
    void update();


public:
    static std::stringstream threadOut;
    static std::mutex mutex_;
    Game();
    void run();

};


#endif //CARSMASHCPP_GAME_H
