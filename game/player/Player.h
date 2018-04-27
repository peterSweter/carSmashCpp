//
// Created by peter on 3/21/18.
//

#ifndef CARSMASHCPP_PLAYER_H
#define CARSMASHCPP_PLAYER_H


#include "../../networking/SessionI.h"
#include "GameSession.h"
#include "../entities/car/CarFactory.h"


class Player {
private:

    std::shared_ptr<SessionI> sessionI_;
    std::shared_ptr<GameSession> gameSessionI_;
    CarFactory  * carFactory_;
    std::string collectDataToSend();

public:
    Player(std::shared_ptr<SessionI>  && sessionI, CarFactory * carFactory );
    void update();
    void handleMessage(std::shared_ptr<Json> message);
    void sendData();


};


#endif //CARSMASHCPP_PLAYER_H
