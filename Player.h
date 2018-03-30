//
// Created by peter on 3/21/18.
//

#ifndef CARSMASHCPP_PLAYER_H
#define CARSMASHCPP_PLAYER_H


#include "networking/SessionI.h"



class Player {
private:
    std::shared_ptr<SessionI> sessionI_;
public:
    Player(std::shared_ptr<SessionI>  && sessionI );
    void update();

};


#endif //CARSMASHCPP_PLAYER_H
