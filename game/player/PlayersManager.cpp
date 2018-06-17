//
// Created by peter on 3/21/18.
//

#include "PlayersManager.h"
#include "../Game.h"



void PlayersManager::update() {

    //TODO delete disconected players
    for(auto it = playersList_.begin(); it != playersList_.end(); it++){

    }

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
    playersList_.push_back(std::make_shared<Player>(std::move(sessionI), &carFactory_, box2dManager_));

}

PlayersManager::PlayersManager(Box2dManager *box2dManager) : carFactory_(box2dManager), box2dManager_(box2dManager) {
    std::cout << "Players Manager Constructor." << std::endl;
}
