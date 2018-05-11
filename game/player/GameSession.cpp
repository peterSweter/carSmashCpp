//
// Created by peter on 3/31/18.
//

#include "GameSession.h"

void GameSession::handleInput(std::shared_ptr<Json> msg) {
    int keyValue = msg->find("v").value().get<int>();

    switch (keyValue){
        case 37:
            //left
            x-=10;
            break;
        case 38:
            //up
            y-=10;
            break;
        case 39:
            //right
            x+=10;
            break;
        case 40:
            //down
            y+=10;
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

GameSession::GameSession(std::shared_ptr<Car> car, std::string nickname) : car_(std::move(car)), nickname_(nickname){

}

const std::shared_ptr<Car> &GameSession::getCar() const {
    return car_;
}
