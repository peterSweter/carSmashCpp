//
// Created by peter on 3/31/18.
//

#ifndef CARSMASHCPP_GAMESESSION_H
#define CARSMASHCPP_GAMESESSION_H


#include "../../networking/SessionI.h"
#include "../entities/car/Car.h"

class GameSession {
private:

    std::shared_ptr<Car> car_;  //CarFactoryGetModel
    std::string nickname_;

    //init data string for car model

    int x = 0,y =0;
public:
    GameSession(std::shared_ptr<Car> car, std::string nickname);
    void handleInput(std::shared_ptr<Json> msg);
    std::map<std::string, std::string> getData();
    void update();
};


#endif //CARSMASHCPP_GAMESESSION_H
