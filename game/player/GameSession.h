//
// Created by peter on 3/31/18.
//

#ifndef CARSMASHCPP_GAMESESSION_H
#define CARSMASHCPP_GAMESESSION_H


#include "../../networking/SessionI.h"
#include "../entities/car/Car.h"
#include "../../networking/MsgAcceptorI.h"
#include "../input/KeyboardManager.h"


class GameSession : public MsgAcceptorI{
private:

    std::shared_ptr<Car> car_;  //CarFactoryGetModel
    std::string nickname_;
    KeyboardManager keyboardManager_;
    DataCollector dataCollector_;
    bool sessionAlive_ = true;


    //init data string for car model

    int x = 0,y =0;
public:
    GameSession(std::shared_ptr<Car> car, std::string nickname, Box2dManager * box2dManager);
    void handleInput(std::shared_ptr<Json> msg);
    std::map<std::string, std::string> getData();
    bool sessionOver_ = false;

    //TODO RayCast Data
    //TODO problem with conversion units and scale

    void update();

    const std::shared_ptr<Car> &getCar() const;

    void handleMessage(std::shared_ptr<Json> message) override;
    std::shared_ptr<Json> getDataFrame();
    bool isAlive();
};


#endif //CARSMASHCPP_GAMESESSION_H
