//
// Created by peter on 3/31/18.
//

#include <iostream>
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


void GameSession::update() {

    // TODO sendign update frame specification
    // TODO push game session logic there ?


    car_->update();


}

GameSession::GameSession(std::shared_ptr<Car> car, std::string nickname, Box2dManager *box2dManager) : car_(
        std::move(car)), nickname_(nickname), dataCollector_(box2dManager) {
    std::cout << "[GameSession] Constructor." << std::endl;
    car_->setKeyboardManager(&keyboardManager_);

}

const std::shared_ptr<Car> &GameSession::getCar() const {
    return car_;
}

void GameSession::handleMessage(std::shared_ptr<Json> message) {

    std::cout << "[Game session] Handle message:  " <<  message->dump() << std::endl;


    auto messageTypeIt = message->find("t");
    if (messageTypeIt == message->end()) {
        return;
    }

    char messageType = messageTypeIt.value().get<std::string>()[0];

    switch(messageType){
        case 'k':
            //keyboard handling

        std::cout<< "[GameSession] Keyboard message" << std::endl;

            int keyValue = message->find("v").value().get<int>();
            //TODO create logic for sending proper state of pressed ore released button
            //char state = message->find("state").value().get<char>();
            char state = message->find("s").value().get<char>();
            keyboardManager_.handleInput(keyValue, state);

            break;
    }

}

std::shared_ptr<Json> GameSession::getDataFrame() {

    Json json = Json::parse(dataCollector_.getJsonData(getCar()->getPosition(), getCar().get()));
    return std::make_shared<Json>(json);
}

bool GameSession::isAlive() {
    return this->car_->isAlive();
}

GameSession::~GameSession() {
    std::cout << "[GameSession] Deconstructor." << std::endl;
}
