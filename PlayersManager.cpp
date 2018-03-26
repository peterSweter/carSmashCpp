//
// Created by peter on 3/21/18.
//

#include "PlayersManager.h"

void PlayersManager::update() {

    //TODO  check if server/I has/have  new session

 ;

    while(!receivedSessionQ_.empty()){

        createNewPlayer(receivedSessionQ_.front());
        receivedSessionQ_.pop();
    }

}

void PlayersManager::pushNewSession(std::shared_ptr<SessionI> sessionI) {

    std::cout<< "[PlayerManager] Pushing new session to receivedSessionQ" << std::endl;
    receivedSessionQ_.push(sessionI);

}

void PlayersManager::createNewPlayer(std::shared_ptr<SessionI> sessionI) {
    std::cout << "New player is about to be created!" << std::endl;
}
