//
// Created by peter on 3/21/18.
//

#ifndef CARSMASHCPP_PLAYER_H
#define CARSMASHCPP_PLAYER_H


#include "../../networking/SessionI.h"
#include "GameSession.h"


class Player {
private:

    std::shared_ptr<SessionI> sessionI_;
    std::shared_ptr<GameSession> gameSessionI_;
    std::string collectDataToSend();

public:
    Player(std::shared_ptr<SessionI>  && sessionI );
    void update();
    void handleMessage(std::shared_ptr<Json> message);
    void sendData();


};


#endif //CARSMASHCPP_PLAYER_H
