//
// Created by peter on 3/21/18.
//

#include "Player.h"
#include "../Game.h"

void Player::update() {




    while (!sessionI_->getMessages()->empty()) {

        auto tmpMessage = std::move(sessionI_->getMessages()->front());
        sessionI_->getMessages()->pop();

        if(gameSessionI_){
            gameSessionI_->handleMessage(tmpMessage);
        }else{
            handleMessage(tmpMessage);
        }

    }

    if (gameSessionI_) {

        if(!gameSessionI_->isAlive()){
            std::cout << "[Player]  player car is dead  :(. " << std::endl;
            //TODO message to client about tragic accident.
            gameSessionI_.reset();
        }else{
            gameSessionI_->update();
            sessionI_->sendJSON(gameSessionI_->getDataFrame());
        }


    }

    //TODO consider splitting sending message with game data frame and update
}

Player::Player(std::shared_ptr<SessionI> &&sessionI, CarFactory *carFactory, Box2dManager * box2dManager) : sessionI_(std::move(sessionI)),
                                                                               carFactory_(carFactory),
                                                                               box2dManager_(box2dManager) {
    Game::threadOut << "Created new player " << std::endl;
}

void Player::handleMessage(std::shared_ptr<Json> message) {

    //TODO catch exceptions while parsing json data package
    //TODO checking if player is in appropriate state to sent certain type of message

    std::cout  << "Player got message from client" << std::endl;

    auto messageTypeIt = message->find("t");
    if (messageTypeIt == message->end()) {
        return;
    }

    char messageType = messageTypeIt.value().get<std::string>()[0];

    std::cout << message->dump() << std::endl;


    switch (messageType) {
        case 'n': {

            //new player event, player nick
            /* Game::threadOut << *message->find("v") << std::endl;
             std::map<std::string, std::string> msgRetMap = {{"t", "u"},
                                                             {"x", "12"},
                                                             {"y", "12"}};
             sessionI_->sendJSON(Json(msgRetMap));*/

            std::string carModelID = message->at("carModelID").get<std::string>();
            nickname_ = message->at("nickname").get<std::string>();


            auto carPtr = carFactory_->create(carModelID);
            carPtr->setPlayer(this);
            std::cout << "created new car" << std::endl;


            gameSessionI_ = std::make_shared<GameSession>(carPtr, nickname_, box2dManager_);

            std::cout << "created game session" << std::endl;

            break;
        }
        case 'u':
            //player ui response event

            break;

        case 'k':
            // this should happen inside game session lol
          /*  if (gameSessionI_) {
                gameSessionI_->handleInput(message);
            }*/

            break;
    }
}

std::string Player::getNickname()  {
    return nickname_;
}

std::shared_ptr<GameSession> Player::getGameSession()  {
    return gameSessionI_;
}


