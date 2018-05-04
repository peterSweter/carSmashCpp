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

    if (gameSessionI_) {
        gameSessionI_->update();


        //TODO query data and send
        updateCount_ = !updateCount_;

        Json json = Json::parse(dataCollector_.getJsonData(this, gameSessionI_->getCar()->getPosition(), this->getUpdateCount()));
        sessionI_->sendJSON(json);

    }

    //TODO consider splitting sending message with game data frame and update
}

Player::Player(std::shared_ptr<SessionI> &&sessionI, CarFactory *carFactory, Box2dManager * box2dManager) : sessionI_(std::move(sessionI)),
                                                                               carFactory_(carFactory),
                                                                               dataCollector_(box2dManager_),
                                                                               box2dManager_(box2dManager) {
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
            nickname_ = message->at("nickname").get<std::string>();

            auto carPtr = carFactory_->create(carModelID);
            carPtr->setPLayer(this);

            Game::threadOut << "created new car" << std::endl;

            gameSessionI_ = std::make_shared<GameSession>(carPtr, nickname_);

            break;
        }
        case 'u':
            //player ui response event

            break;

        case 'k':
            //keyboard event delegate to game object
            if (gameSessionI_) {
                gameSessionI_->handleInput(message);
                sessionI_->sendJSON(Json(gameSessionI_->getData()));
            }
            break;
    }
}

std::string Player::getNickname()  {
    return nickname_;
}

std::shared_ptr<GameSession> Player::getGameSession()  {
    return gameSessionI_;
}

const bool Player::getUpdateCount() {
    return this->updateCount_;
}

