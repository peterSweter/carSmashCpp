//
// Created by peter on 3/21/18.
//

#include "Player.h"
#include "../Game.h"

void Player::update() {
    while (!sessionI_->getMessages()->empty()) {

        auto tmpMessage = std::move(sessionI_->getMessages()->front());
        sessionI_->getMessages()->pop();
        handleMessage(tmpMessage);

    }

    if(gameSessionI_){
        gameSessionI_->update();
    }
}

Player::Player(std::shared_ptr<SessionI> &&sessionI,  CarFactory *carFactory) : sessionI_(std::move(sessionI)), carFactory_(carFactory) {
    Game::threadOut << "Created new player " << std::endl;
}

void Player::handleMessage(std::shared_ptr<Json> message) {

    //TODO catch exceptions while parsing json data package
    //TODO checking if player is in appropriate state to sent ceratin type of message

    //Game::threadOut << "Player got message from client" << std::endl;

    auto messageTypeIt = message->find("t");
    if (messageTypeIt == message->end()) {
        return;
    }

    char messageType = messageTypeIt.value().get<std::string>()[0];

    switch (messageType) {
        case 'n': {
            //new player event, player nick
           /* Game::threadOut << *message->find("v") << std::endl;
            std::map<std::string, std::string> msgRetMap = {{"t", "u"},
                                                            {"x", "12"},
                                                            {"y", "12"}};
            sessionI_->sendJSON(Json(msgRetMap));*/

           std::string carModelID = message->at("carModelID").get<std::string>();
           std::string nickname = message->at("nickname").get<std::string>();

           auto carPtr = carFactory_->create(carModelID);

           Game::threadOut << "created new car" << std::endl;

            gameSessionI_ = std::make_shared<GameSession>(carPtr, nickname);

            break;
        }
        case 'u':
            //player ui response event

            break;

        case 'k':
            //keyboard event delegate to game object
            gameSessionI_->handleInput(message);
            sessionI_->sendJSON(Json(gameSessionI_->getData()));

            break;
    }
}

