//
// Created by peter on 3/21/18.
//

#ifndef CARSMASHCPP_GAME_H
#define CARSMASHCPP_GAME_H


#include "PlayersManager.h"

class Game {
private:
    PlayersManager playersManager;

    void update();


public:

    void run();

};


#endif //CARSMASHCPP_GAME_H
