//
// Created by peter on 4/14/18.
//

#ifndef CARSMASHCPP_CAR_H
#define CARSMASHCPP_CAR_H


#include <map>
#include <Box2D/Box2D.h>
#include <iostream>
#include "CarPart.h"
#include "CarPrototype.h"
#include "../../box2D/Box2dManager.h"

#include "../../dataCollector/DataCollectableOnceI.h"
#include "../../player/PlayerI.h"
#include "../../input/KeyboardManager.h"
#include "CarEngine/CarEngine.h"
#include "../EntityI.h"


class Car : public DataCollectableOnceI, public EntityI {

    Box2dManager * box2dManager_;
    PlayerI * player_;
    KeyboardManager * keyboardManager_ = nullptr;
    CarEngine carEngine_;
    double score_ = 0;
    double maxHealth;


public:

    std::map<std::string,b2Body*> bodies_;
    std::map<std::string, std::shared_ptr<CarPart>> carParts_;

    Car(std::shared_ptr<CarPrototype> carPrototype, Box2dManager * box2dManager);
    void setPlayer(PlayerI * player);
    void setKeyboardManager(KeyboardManager * keyboardManager);
    void update();
    b2Vec2 getPosition();
    double getScore();

    //TODO checking if data was fetched already from this object
    std::shared_ptr<Json> getJsonData();

    void dealDamage(InteractiveEntityPartA *entity, double dmg) override;

    ~Car();
};


#endif //CARSMASHCPP_CAR_H
