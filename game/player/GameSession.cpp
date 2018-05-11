//
// Created by peter on 3/31/18.
//

#include "GameSession.h"

void GameSession::handleInput(std::shared_ptr<Json> msg) {
    //TODO delete this
    int keyValue = msg->find("v").value().get<int>();

    switch (keyValue) {
        case 37:
            //left
            x -= 10;
            break;
        case 38:
            //up
            y -= 10;
            break;
        case 39:
            //right
            x += 10;
            break;
        case 40:
            //down
            y += 10;
            break;
    }
}

std::map<std::string, std::string> GameSession::getData() {
    //TODO data should be sent from there not from invoking data from player from this class.

    return {{"t", "u"},
            {"x", std::to_string(this->x)},
            {"y", std::to_string(this->y)}};
}

void GameSession::update() {


    // TODO sendign update frame specification
    // TODO push game session logic there ?


}

GameSession::GameSession(std::shared_ptr<Car> car, std::string nickname, Box2dManager *box2dManager) : car_(
        std::move(car)), nickname_(nickname), dataCollector_(box2dManager) {

}

const std::shared_ptr<Car> &GameSession::getCar() const {
    return car_;
}

void GameSession::handleMessage(std::shared_ptr<Json> message) {


    auto messageTypeIt = message->find("t");
    if (messageTypeIt == message->end()) {
        return;
    }

    char messageType = messageTypeIt.value().get<std::string>()[0];

    switch(messageType){
        case 'k':
            //keyboard handling
            break;
    }

}

std::shared_ptr<Json> GameSession::getDataFrame() {

    Json json = Json::parse(dataCollector_.getJsonData(getCar()->getPosition()));
    return std::make_shared<Json>(json);
}

bool GameSession::isAlive() {
    return this->sessionAlive_;
}
