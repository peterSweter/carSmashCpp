//
// Created by peter on 3/21/18.
//

#ifndef CARSMASHCPP_PLAYERSMANAGER_H
#define CARSMASHCPP_PLAYERSMANAGER_H


#include "networking/ListenerI.h"

class PlayersManager {
private:
    ListenerI & listener;
public:

    PlayersManager();
    void update();
};


#endif //CARSMASHCPP_PLAYERSMANAGER_H
