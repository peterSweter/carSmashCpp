//
// Created by peter on 3/21/18.
//

#ifndef CARSMASHCPP_PLAYER_H
#define CARSMASHCPP_PLAYER_H


#include "networking/SessionI.h"



class Player {
private:
    SessionI &sessionI;
public:
    Player();
    void update();

};


#endif //CARSMASHCPP_PLAYER_H
