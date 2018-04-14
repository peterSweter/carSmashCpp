//
// Created by peter on 3/21/18.
//

#ifndef CARSMASHCPP_GAME_H
#define CARSMASHCPP_GAME_H


#include "player/PlayersManager.h"
#include "../networking/WebSocketServerAsync.h"
#include "box2D/Box2dManager.h"

class Game {
private:
    std::unique_ptr<PlayersManager> playersManager_;
    std::unique_ptr<WebSocketServerAsync> webSocketServerAsync_;
    std::unique_ptr<Box2dManager> box2dManager_;

    void update();


public:
    static std::stringstream threadOut;
    static std::mutex mutex_;
    static double MS_PER_FRAME;
    Game();
    void run();

};


#endif //CARSMASHCPP_GAME_H
