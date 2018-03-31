//
// Created by peter on 3/21/18.
//

#include "PlayersManager.h"
#include "../Game.h"

void PlayersManager::update() {

    //TODO  check if server/I has/have  new session



    while(!receivedSessionQ_.empty()){

        createNewPlayer(receivedSessionQ_.front());
        receivedSessionQ_.pop();
    }


    for(auto player : playersList_){
        player->update();
    }

}

void PlayersManager::pushNewSession(std::shared_ptr<SessionI> sessionI) {
    receivedSessionQ_.push(sessionI);

}

void PlayersManager::createNewPlayer(std::shared_ptr<SessionI> sessionI) {
    playersList_.push_back(std::make_shared<Player>(std::move(sessionI)));

}
