//
// Created by peter on 3/21/18.
//

#ifndef CARSMASHCPP_PLAYER_H
#define CARSMASHCPP_PLAYER_H


#include "../../networking/SessionI.h"
#include "GameSession.h"
#include "../entities/car/CarFactory.h"
#include "../dataCollector/DataCollector.h"
#include "PlayerI.h"
#include "../../networking/MsgAcceptorI.h"


class Player : public PlayerI, public MsgAcceptorI {
private:

    std::shared_ptr<SessionI> sessionI_;
    std::shared_ptr<GameSession> gameSessionI_;
    CarFactory *carFactory_;
    std::string nickname_;
    Box2dManager *box2dManager_;

public:
    std::string getNickname() override;

    Player(std::shared_ptr<SessionI> &&sessionI, CarFactory *carFactory, Box2dManager *box2dManager);

    void update();
    void handleMessage(std::shared_ptr<Json> message) override;
    std::shared_ptr<GameSession> getGameSession();

};


#endif //CARSMASHCPP_PLAYER_H
